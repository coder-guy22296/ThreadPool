/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:32:55 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 02:24:17 by cyildiri         ###   ########.fr       */
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
	worker->running = 1;
	pthread_mutex_lock(&worker->mutex);
	pthread_cond_signal(&worker->ready_cond);
	pthread_mutex_unlock(&worker->mutex);
	while (worker->running)
	{
		//wait for signal
		//  printf("worker waiting\n");
		pthread_mutex_lock(&worker->mutex);
		pthread_cond_wait(&worker->cond, &worker->mutex);
		pthread_mutex_unlock(&worker->mutex);
		//  printf("job active\n");

		// step into active queue
		queue_enqueue(active_threads, new_lst(worker));

		//  printf("added worker to active queue\n");
		//do job
		worker->thread_job->task_function(worker->thread_job->params);
		//  printf("job complete\n");	
		//step into the idle queue
		queue_remove(active_threads, worker);
		// printf("removed worker from active queue\n");
		queue_enqueue(idle_threads, new_lst(worker));
		//  printf("added worker to idle queue\n");
		pthread_mutex_lock(&worker->mutex);
		if (++(parent->tasks_done) >= parent->max_tasks)
			sem_post(parent->done);
		pthread_mutex_unlock(&worker->mutex);
	}
	//cleanup
	return (0);
}
