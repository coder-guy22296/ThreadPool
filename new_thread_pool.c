/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread_pool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:14:17 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 02:32:18 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "thread_pool.h"

t_thread_pool	*new_thread_pool(int max_tasks)
{
	t_thread_pool	*tp;

	tp = (t_thread_pool *)calloc(1, sizeof(t_thread_pool));
	tp->manager = (pthread_t *)calloc(1, sizeof(pthread_t));
	tp->max_tasks = max_tasks;
	sem_unlink("/test99");
	sem_unlink("/me99");
	tp->work_todo = sem_open("/test99", O_CREAT, 0777, 0);
	if (tp->work_todo == SEM_FAILED)
		printf("start_sending sem open failed with %d\n", errno);
	tp->done = sem_open("/me99", O_CREAT, 0777, 0);
	if (tp->done == SEM_FAILED)
		printf("start_sending sem open failed with %d\n", errno);
	tp->active_threads = new_queue();
	tp->idle_threads = new_queue();
	tp->job_queue = new_queue();
	return (tp);
}
