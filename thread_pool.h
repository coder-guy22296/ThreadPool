/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:14:14 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 02:17:49 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_POOL_H
# define THREAD_POOL_H
#include <semaphore.h>
# include "queue.h"

typedef struct		s_job
{
	void			*params;
	void 			(*task_function) (void *);
}					t_job;

typedef struct		s_worker_thread
{
	pthread_cond_t	cond;
	pthread_cond_t	ready_cond;
	pthread_mutex_t	mutex;
	void			*parent;
	char			running;
	sem_t			start_sig;
	t_job			*thread_job;
	pthread_t		*tid;
}					t_worker_thread;

typedef struct		s_thread_pool
{
	int				max_tasks;
	int				tasks_assigned;
	int				tasks_done;
	char			running;
	t_queue			*active_threads;
	t_queue			*idle_threads;
	t_queue			*job_queue;
	pthread_t		*manager;
	sem_t			*work_todo;
	sem_t			*done;
}					t_thread_pool;

t_thread_pool	*new_thread_pool(int max_tasks);
t_worker_thread	*new_worker_thread();
void			*worker(void *params);
void			tp_add_job(t_thread_pool *tp, void (*task_function)(void *),
				void *params);
void			tp_launch(t_thread_pool *tp);
void			tp_wait(t_thread_pool *tp);

#endif