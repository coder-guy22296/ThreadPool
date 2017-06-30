/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_add_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:44:48 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 02:22:10 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "thread_pool.h"

void	tp_add_job(t_thread_pool *tp, void (*task_function)(void *),
		void *params)
{
	t_job	*job;

	if (tp->tasks_assigned >= tp->max_tasks)
		return ;
	// make job struct
	job = (t_job *)calloc(1, sizeof(t_job));
	job->task_function = task_function;
	job->params = params;

	// put the job on the task queue
	queue_enqueue(&tp->job_queue, new_lst(job));

	// signal manager to hand dispatch work
	// printf("posting job\n");
	sem_post(tp->work_todo);
	// printf("job posted\n");
	tp->tasks_assigned++;
}