/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:20:42 by ssmith            #+#    #+#             */
/*   Updated: 2017/06/30 00:00:15 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

t_lst	*queue_pop_link(t_queue **queue)
{
	t_lst		*node;

	node = NULL;
	if (*queue)
	{
		pthread_mutex_lock(&(*queue)->mutex);
		if ((*queue)->first)
		{
			node = (*queue)->first;
			(*queue)->count--;
			(*queue)->first = (*queue)->first->next;
		}
		if ((*queue)->count == 0)
			(*queue)->last = NULL;
		pthread_mutex_unlock(&(*queue)->mutex);
	}
	return (node);
}

void	*queue_pop(t_queue **queue)
{
	void	*data;
	t_lst	*node;

	data = NULL;
	if (*queue)
	{
		pthread_mutex_lock(&(*queue)->mutex);
		node = (*queue)->first;
		if (node)
		{
			(*queue)->count--;
			data = node->data;
			(*queue)->first = (*queue)->first->next;
			free(node);
		}
		if ((*queue)->count == 0)
			(*queue)->last = NULL;
		pthread_mutex_unlock(&(*queue)->mutex);
	}
	return (data);
}
