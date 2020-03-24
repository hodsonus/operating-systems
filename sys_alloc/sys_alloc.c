#include <linux/cred.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <kernel/sched/sched.h>

SYSCALL_DEFINE2(set_alloc, int, level, int, new_allocation)
{
	// if the user is not the superuser, fail
	if (current_uid().val != 0) return -1;
	// if the level is not valid, fail
	if (level < 0 || level > 3) return -1; 

	// calculate the new total allocated time with this change
	struct rq *rq;
	int i, total_alloc;

	total_alloc = 0;
	rq = this_rq();

	for (i = 0; i < 4; ++i)
	{
		if (i == level)
		{
			// if i is the proposed level to update, add the newly proposed value
			total_alloc += new_allocation;
		}
		else
		{
			// else it is not the proposed level to update, so add the current value
			total_alloc += rq->levels.alloc[i];
		}
	} 

	// if the proposed update puts us underneath the total minimum allocation, fail
	if (total_alloc <= 5) return -1;

	// perform the update if we passed all of the checks
	rq->levels.alloc[level] = new_allocation;
}

SYSCALL_DEFINE1(get_alloc, int, level)
{
	// if the level is not valid, fail
	if (level < 0 || level > 3) return -1; 

	// return the allocation for the level on this CPU's rq
	return this_rq()->levels.alloc[level];
}