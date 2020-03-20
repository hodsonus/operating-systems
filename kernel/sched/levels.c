#include "sched.h"
#include <trace/events/sched.h>

static void enqueue_task_levels(struct rq *rq, struct task_struct *p, int flags)
{
}

static void dequeue_task_levels(struct rq *rq, struct task_struct *p, int flags)
{
}

static void yield_task_levels(struct rq *rq)
{
}

static bool yield_to_task_levels(struct rq *rq, struct task_struct *p, bool preempt)
{
}

static void check_preempt_wakeup_levels(struct rq *rq, struct task_struct *p, int wake_flags)
{
}
static struct task_struct *pick_next_task_levels(struct rq *rq, struct task_struct *prev, struct rq_flags *rf)
{
}

static void put_prev_task_levels(struct rq *rq, struct task_struct *prev)
{
}

#ifdef CONFIG_SMP

static int select_task_rq_levels(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags)
{
}

static void migrate_task_rq_levels(struct task_struct *p, int new_cpu)
{
}

static void rq_online_levels(struct rq *rq)
{
}

static void rq_offline_levels(struct rq *rq)
{
}

static void task_dead_levels(struct task_struct *p)
{
}

#endif /* COMFIG_SMP */

static void set_curr_task_levels(struct rq *rq)
{
}

static void task_tick_levels(struct rq *rq, struct task_struct *curr, int queued)
{
}

static void task_fork_levels(struct task_struct *p)
{
}

static void prio_changed_levels(struct rq *rq, struct task_struct *p, int oldprio)
{
}

static void switched_from_levels(struct rq *rq, struct task_struct *p)
{
}

static void switched_to_levels(struct rq *rq, struct task_struct *p)
{
}

static unsigned int get_rr_interval_levels(struct rq *rq, struct task_struct *task)
{
}

static void update_curr_levels(struct rq *rq)
{
}

#ifdef CONFIG_FAIR_GROUP_SCHED

static void task_change_group_levels(struct task_struct *p, int type)
{
}

#endif

const struct sched_class levels_sched_class = {
	.next			= &fair_sched_class,
	.enqueue_task		= enqueue_task_levels,
	.dequeue_task		= dequeue_task_levels,
	.yield_task		= yield_task_levels,
	.yield_to_task		= yield_to_task_levels,

	.check_preempt_curr	= check_preempt_wakeup_levels,

	.pick_next_task		= pick_next_task_levels,
	.put_prev_task		= put_prev_task_levels,

#ifdef CONFIG_SMP
	.select_task_rq		= select_task_rq_levels,
	.migrate_task_rq	= migrate_task_rq_levels,

	.rq_online		= rq_online_levels,
	.rq_offline		= rq_offline_levels,

	.task_dead		= task_dead_levels,
	.set_cpus_allowed	= set_cpus_allowed_common,
#endif

	.set_curr_task          = set_curr_task_levels,
	.task_tick		= task_tick_levels,
	.task_fork		= task_fork_levels,

	.prio_changed		= prio_changed_levels,
	.switched_from		= switched_from_levels,
	.switched_to		= switched_to_levels,

	.get_rr_interval	= get_rr_interval_levels,

	.update_curr		= update_curr_levels,

#ifdef CONFIG_FAIR_GROUP_SCHED
	.task_change_group	= task_change_group_levels,
#endif
};