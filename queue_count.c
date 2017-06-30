/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 20:21:03 by iwagner           #+#    #+#             */
/*   Updated: 2017/06/30 00:00:38 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "pthread.h"

int	queue_count(t_queue *queue)
{
	int x;

	if (queue)
	{
		pthread_mutex_lock(&queue->mutex);
		if((x = queue->count))
		{
			pthread_mutex_unlock(&queue->mutex);
			return (x);
		}
		else
			pthread_mutex_unlock(&queue->mutex);
	}
	return (0);
}
