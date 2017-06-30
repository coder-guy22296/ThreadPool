/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:46:51 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 00:00:11 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue.h"

t_queue	*new_queue()
{
	t_queue *queue;

	queue = (t_queue *)calloc(1, sizeof(t_queue));
	pthread_mutex_init(&queue->mutex, NULL);
	return (queue);
}
