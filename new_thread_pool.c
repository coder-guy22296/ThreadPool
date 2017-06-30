/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread_pool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:14:17 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 15:38:22 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "thread_pool.h"

t_thread_pool	*new_thread_pool()
{
	t_thread_pool	*tp;

	tp = (t_thread_pool *)calloc(1, sizeof(t_thread_pool));
	tp->manager = (pthread_t *)calloc(1, sizeof(pthread_t));
	tp->active_threads = new_queue();
	tp->idle_threads = new_queue();
	tp->job_queue = new_queue();
	return (tp);
}
