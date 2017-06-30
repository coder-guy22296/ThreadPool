/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 22:42:45 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 02:40:27 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "timers.h"
#include "thread_pool.h"
#include "queue.h"

int G_jobs = 0;

void job_a(void *param)
{
	char *str;
	int val;

	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			val += i*j - j*2;
		}
	}
	str = (char *)param;
	sleep(1);
	//printf("job a done: %s + %d\n", str, val);
}

void job_b(void *param)
{
	char *str;
	int val;

	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			val += i*j - j*2;
		}
	}
	sleep(1);
	str = (char *)param;
	//printf("job b done: %s + %d\n", str, val);
}

void threaded()
{
	t_queue			*queue;
	t_thread_pool	*tp;
	char			*string;
	int				i;

	queue = new_queue();
	queue_enqueue(&queue, new_lst("job 1"));
	queue_enqueue(&queue, new_lst("job 2"));
	queue_enqueue(&queue, new_lst("job 3"));
	queue_enqueue(&queue, new_lst("job 4"));
	queue_enqueue(&queue, new_lst("job 5"));
	queue_enqueue(&queue, new_lst("job 6"));
	queue_enqueue(&queue, new_lst("job 7"));
	queue_enqueue(&queue, new_lst("job 8"));
	for(int i = 0; i < G_jobs; i++)
		queue_enqueue(&queue, new_lst("job 9"));
	printf("created jobs\n");
	int count = queue_count(queue);
	tp = new_thread_pool(count);
	tp_launch(tp);
	printf("thread_pool launched\n");
	while (queue_count(queue) > 0)
	{
		string = queue_pop(&queue);
		if (i % 2)
			tp_add_job(tp, job_a, string);
		else
			tp_add_job(tp, job_b, string);
		i++;
	}
	printf("done loading jobs\n");
	tp_wait(tp);
}

void not_threaded()
{
	t_queue			*queue;
	char			*string;
	int				i;

	queue = new_queue();
	queue_enqueue(&queue, new_lst("job 1"));
	queue_enqueue(&queue, new_lst("job 2"));
	queue_enqueue(&queue, new_lst("job 3"));
	queue_enqueue(&queue, new_lst("job 4"));
	queue_enqueue(&queue, new_lst("job 5"));
	queue_enqueue(&queue, new_lst("job 6"));
	queue_enqueue(&queue, new_lst("job 7"));
	queue_enqueue(&queue, new_lst("job 8"));
	for(int i = 0; i < G_jobs; i++)
		queue_enqueue(&queue, new_lst("job 9"));
	printf("created jobs\n");
	while (queue_count(queue) > 0)
	{
		string = queue_pop(&queue);
		if (i % 2)
			job_a(string);
		else
			job_b(string);
		i++;
	}
	printf("done with jobs\n");
}

int main()
{
	G_jobs = 10;
	TIMER_SETUP(time)
	TIMER_START(time)
	threaded();
	TIMER_STOP(time)
	TIMER_PRINT("threaded", time)
	TIMER_START(time)
	not_threaded();
	TIMER_STOP(time)
	TIMER_PRINT("non-threaded", time)
	return (0);
}