/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:22:08 by ssmith            #+#    #+#             */
/*   Updated: 2017/06/30 00:00:15 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
# include <pthread.h>
#include "queue.h"

t_lst	*queue_create_new(void *bundle)
{
	t_lst	*node;

	node = (t_lst *)calloc(1, sizeof(t_lst));
	node->data = bundle;
	node->next = NULL;
	return (node);
}
