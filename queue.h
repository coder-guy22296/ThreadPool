/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:50:05 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/29 23:58:29 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include <pthread.h>
# include <stdio.h>

typedef struct			s_lst
{
	void 				*data;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_queue
{
	int					count;
	t_lst				*first;
	t_lst				*last;
	pthread_mutex_t		mutex;
}						t_queue;

t_queue		*new_queue();

t_lst		*queue_pop_link(t_queue **queue);

t_lst		*new_lst(void *data);
t_lst 		*queue_remove(t_queue **queue, void *data);
/*
 * 	Pops a node off the queue
 * 		@param **queue	A queue struct that holds first, last and size
 */
void		*queue_pop(t_queue **queue);

/*
 * 	Adds a node to the end of the queue. Returns the last param.
 * 		@param **queue	A queue struct that holds first, last and size
 * 		@param *new		The new node to be added to the queue
 */
t_lst		*queue_enqueue(t_queue **queue, t_lst *new_node);

/*
*	returns first workunit in queue without deletion from queue
*/
void		*queue_peek(t_queue **queue);

/*
*	returns the total count of items in queue
*/
int			queue_count(t_queue *queue);

#endif