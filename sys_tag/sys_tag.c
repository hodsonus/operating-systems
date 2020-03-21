#include <linux/cred.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(set_tag, int, pid, int, new_tag)
{
    struct pid *pid_struct = NULL;
    struct task_struct *task = NULL;

    // useful bitmasks
    const unsigned int BIT_0 = 0b1;
    const unsigned int BIT_01 = 0b11;
    const unsigned int BIT_MSB = 0x80000000;

	if (new_tag < 0) return -1;

	pid_struct = find_get_pid(pid);
	if (!pid_struct)
		return -1;

	task = pid_task(pid_struct, PIDTYPE_PID);
	if (!task)
		return -1;

    // new_tag must have 0 in MSB
    if (new_tag & BIT_MSB) return -1;

	if (current_uid().val == 0) {
		// A process running as the superuser may read and write the tag of any process.

		task->tag = new_tag;
		return new_tag;
	} else {
        int new_level = new_tag & BIT_01;
        int curr_level = task->tag & BIT_01;
		if (task == current) {
			// user process changing its own security level
            // a user process may decrease its own level, but not increase it
			if (new_level <= curr_level) {
                // a user process may reset a bit in its tag's bitmap to zero but not set a bit
                unsigned int i = 0;
                for (i = 2; i <= 30; i++) {
                    int mask = BIT_0 << i;
                    int new_byte = new_tag & mask;
                    int curr_byte = task->tag & mask;
                    if (new_byte > curr_byte) return -1;
                }
				task->tag = new_tag;
				return new_tag;
			} else
				return -1;
		}
		// a user process has read-only access to the tag of any process
		return -1;

	}
	return -1;
}

SYSCALL_DEFINE1(get_tag, int, pid)
{
	struct pid *pid_struct = NULL;
    struct task_struct *task = NULL;

    pid_struct = find_get_pid(pid);
	if (!pid_struct) {
		return -1;
	}

	task = pid_task(pid_struct, PIDTYPE_PID);
	if (!task)
		return -1;

	return task->tag;
}