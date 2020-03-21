#include "sched.h"
#include <trace/events/sched.h>

static void enqueue_task_levels(struct rq *rq, struct task_struct *p, int flags)
{
   /* TODO - implement me!? */
   fair_sched_class.enqueue_task(rq, p, flags);
}

static void dequeue_task_levels(struct rq *rq, struct task_struct *p, int flags)
{
   /* TODO - implement me!? */
   fair_sched_class.dequeue_task(rq, p, flags);
}

static void yield_task_levels(struct rq *rq)
{
   /* TODO - implement me!? */
   fair_sched_class.yield_task(rq);
}

static bool yield_to_task_levels(struct rq *rq, struct task_struct *p, bool preempt)
{
   /* TODO - implement me!? */
   return fair_sched_class.yield_to_task(rq, p, preempt);
}

static void check_preempt_wakeup_levels(struct rq *rq, struct task_struct *p, int wake_flags)
{
   /* TODO - implement me!? */
   fair_sched_class.check_preempt_curr(rq, p, wake_flags);
}
static struct task_struct* pick_next_task_levels(struct rq *rq, struct task_struct *prev, struct rq_flags *rf)
{
   /* TODO - implement me!? */
   return fair_sched_class.pick_next_task(rq, prev, rf);
}

static void put_prev_task_levels(struct rq *rq, struct task_struct *prev)
{
   /* TODO - implement me!? */
   fair_sched_class.put_prev_task(rq, prev);
}

#ifdef CONFIG_SMP

static int select_task_rq_levels(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags)
{
   /* TODO - implement me!? */
   return fair_sched_class.select_task_rq(p, prev_cpu, sd_flag, wake_flags);
}

static void migrate_task_rq_levels(struct task_struct *p, int new_cpu)
{
   /* TODO - implement me!? */
   fair_sched_class.migrate_task_rq(p, new_cpu);
}

static void rq_online_levels(struct rq *rq)
{
   /* TODO - implement me!? */
   fair_sched_class.rq_online(rq);
}

static void rq_offline_levels(struct rq *rq)
{
   /* TODO - implement me!? */
   fair_sched_class.rq_offline(rq);
}

static void task_dead_levels(struct task_struct *p)
{
   /* TODO - implement me!? */
   fair_sched_class.task_dead(p);
}

#endif /* COMFIG_SMP */

static void set_curr_task_levels(struct rq *rq)
{
   /* TODO - implement me!? */
   fair_sched_class.set_curr_task(rq);
}

static void task_tick_levels(struct rq *rq, struct task_struct *curr, int queued)
{
   /* TODO - implement me!? */
   fair_sched_class.task_tick(rq, curr, queued);
}

static void task_fork_levels(struct task_struct *p)
{
   /* TODO - implement me!? */
   fair_sched_class.task_fork(p);
}

static void prio_changed_levels(struct rq *rq, struct task_struct *p, int oldprio)
{
   /* TODO - implement me!? */
   fair_sched_class.prio_changed(rq, p, oldprio);
}

static void switched_from_levels(struct rq *rq, struct task_struct *p)
{
   /* TODO - implement me!? */
   fair_sched_class.switched_from(rq, p);
}

static void switched_to_levels(struct rq *rq, struct task_struct *p)
{
   /* TODO - implement me!? */
   fair_sched_class.switched_to(rq, p);
}

static unsigned int get_rr_interval_levels(struct rq *rq, struct task_struct *task)
{
   /* TODO - implement me!? */
   return fair_sched_class.get_rr_interval(rq, task);
}

static void update_curr_levels(struct rq *rq)
{
   /* TODO - implement me!? */
   fair_sched_class.update_curr(rq);
}

#ifdef CONFIG_FAIR_GROUP_SCHED

static void task_change_group_levels(struct task_struct *p, int type)
{
   /* TODO - implement me!? */
   fair_sched_class.task_change_group(p, type);
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