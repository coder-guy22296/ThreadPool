/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:04:49 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 00:00:15 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_lst 		*queue_remove(t_queue **queue, void *data)
{
	t_lst	*head;
	t_lst	*last;

	pthread_mutex_lock(&(*queue)->mutex);
	head = (*queue)->first;
	last = (*queue)->first;
	if (head && head->data == data)
	{
		head = head->next;
		pthread_mutex_unlock(&(*queue)->mutex);
		return (head);
	}
	while (head)
	{
		if (head->data == data)
		{
			last->next = head->next;
			pthread_mutex_unlock(&(*queue)->mutex);
			return (head);
		}
		last = head;
		head = head->next;
	}
	pthread_mutex_unlock(&(*queue)->mutex);
	return (NULL);
}