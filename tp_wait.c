/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 23:51:06 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 23:51:42 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "thread_pool.h"

void	tp_wait(t_thread_pool *tp)
{
	sem_wait(tp->done);
}