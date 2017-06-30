/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_worker_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:32:37 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 16:25:14 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "thread_pool.h"

void	*worker(void *params)
{
	t_worker_thread	*worker;
	t_thread_pool	*parent;
	t_queue			**active_threads;
	t_queue			**idle_threads;

	worker = params;
	parent = worker->parent;
	active_threads = &parent->active_threads;
	idle_threads = &parent->idle_threads;
	while (worker->running)
	{
		//wait for signal
		sem_wait(&worker->start_sig);

		// step into active queue
		queue_enqueue(active_threads, new_lst(worker));

		//do job
		worker->thread_job->task_function(worker->thread_job->params);

		//step into the idle queue
		queue_remove(active_threads, worker);
		queue_enqueue(idle_threads, new_lst(worker));
	}
	//cleanup
	return (0);
}

t_worker_thread	*new_worker_thread()
{
	t_worker_thread	*worker_thread;

	worker_thread = (t_worker_thread *)calloc(1, sizeof(t_worker_thread));
	worker_thread->tid = (pthread_t *)calloc(1, sizeof(pthread_t));
	pthread_create(worker_thread->tid, NULL, worker, worker_thread);
	return (worker_thread);
}