#include <linux/cred.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(set_alloc, int, level, int, new_allocation)
{
	/* TODO - implement me?! */
	return -1;
}

SYSCALL_DEFINE1(get_alloc, int, level)
{
	/* TODO - implement me?! */
	return -1;
}