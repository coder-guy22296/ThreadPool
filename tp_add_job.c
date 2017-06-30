/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_add_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:44:48 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 16:30:27 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "thread_pool.h"

void	tp_add_job(t_thread_pool *tp, void (*task_function)(void *),
		void *params)
{
	t_job	*job;

	job = (t_job *)calloc(1, sizeof(t_job));
	job->task_function = task_function;
	job->params = params;
	queue_enqueue(&tp->job_queue, new_lst(job));
	sem_post(&tp->work_todo);
}