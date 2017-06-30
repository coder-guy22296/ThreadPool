/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 20:20:46 by iwagner           #+#    #+#             */
/*   Updated: 2017/06/29 14:40:50 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
#include "queue.h"

void	*queue_peak(t_queue **queue)
{
	void	*bundle;
	t_lst	*node;

	if (*queue)
	{
		pthread_mutex_lock(&(*queue)->mutex);
		node = (*queue)->first;
		if (node)
			bundle = node->data;
		pthread_mutex_unlock(&(*queue)->mutex);
	}
	return (bundle);
}
