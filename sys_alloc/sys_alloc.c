#include <linux/cred.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include "../kernel/sched/sched.h"

SYSCALL_DEFINE2(set_alloc, int, level, int, new_allocation)
{
	int i, total_alloc;

	// if the user is not the superuser, fail
	if (current_uid().val != 0) return -1;
	// if the level is not valid, fail
	if (level < 0 || level >= NUM_TASK_LEVELS) return -1;
	// if the new allocation is not a valid timeslice, fail
	if (new_allocation < 0) return -1;

	// calculate the new total allcoated time with this change
	total_alloc = 0;
	for (i = 0; i < NUM_TASK_LEVELS; ++i)
	{
		// if i is the proposed level to update, add the newly proposed value
		// else it is not the proposed level to update, so add the current value
		if (i == level) total_alloc += new_allocation;
		else total_alloc += levels_management.alloc[i];
	} 

	// if the proposed update puts us underneath the total minimum allocation, fail
	if (total_alloc < MINIMUM_TOTAL_ALLOC) return -1;

	// perform the update if we passed all of the checks
	levels_management.alloc[level] = new_allocation;

	// return new_allocation on success
	return new_allocation;
}

SYSCALL_DEFINE1(get_alloc, int, level)
{
	// if the level is not valid, fail
	if (level < 0 || level >= NUM_TASK_LEVELS) return -1; 

	// return the allocation for the level on this CPU's rq
	return levels_management.alloc[level];
}
