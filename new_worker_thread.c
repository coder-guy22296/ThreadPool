/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_worker_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:32:37 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 01:43:36 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "thread_pool.h"

t_worker_thread	*new_worker_thread(t_thread_pool *tp)
{
	t_worker_thread	*worker_thread;
	static int count = 0;

	worker_thread = (t_worker_thread *)calloc(1, sizeof(t_worker_thread));
	worker_thread->tid = (pthread_t *)calloc(1, sizeof(pthread_t));
	worker_thread->parent = tp;
	if ( pthread_mutex_init(&worker_thread->mutex, NULL) == -1 )
		printf("start_sending sem open failed with %d\n", errno);
	if ( pthread_cond_init(&worker_thread->cond, NULL) == -1 )
		printf("start_sending sem open failed with %d\n", errno);
	if ( pthread_cond_init(&worker_thread->ready_cond, NULL) == -1 )
		printf("start_sending sem open failed with %d\n", errno);
	pthread_create(worker_thread->tid, NULL, worker, worker_thread);
	pthread_mutex_lock(&worker_thread->mutex);
	pthread_cond_wait(&worker_thread->ready_cond, &worker_thread->mutex);
	pthread_mutex_unlock(&worker_thread->mutex);
	printf("%d worker threads created\n", count++);
	return (worker_thread);
}