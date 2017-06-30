/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:51:26 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 16:32:02 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <semaphore.h>
#include "thread_pool.h"

static void	*tp_manager(void *params)
{
	t_thread_pool	*tp;
	t_worker_thread	*worker;

	tp = params;
	while(tp->running)
	{
		//wait for work to be availible
		sem_wait(&tp->work_todo);

		//get worker
		if (queue_count(tp->idle_threads) > 0)
			worker = queue_pop(&tp->idle_threads);
		else
			worker = new_worker_thread();

		//assign job to worker
		worker->thread_job = queue_pop(&tp->job_queue);

		//signal worker to start
		sem_post(&worker->start_sig);
	}
	//cleanup

	sem_post();
	return (0);
}

void	tp_launch(t_thread_pool *tp)
{
	pthread_create(tp->manager, NULL, tp_manager, tp);
}