/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:43:09 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 14:43:35 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue.h"

t_lst *new_lst(void *data)
{
	t_lst *new_link;

	new_link = calloc(1, sizeof(t_lst));
	new_link->data = data;
	new_link->next = NULL;
	return (new_link);
}