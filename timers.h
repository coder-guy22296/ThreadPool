/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <cyildiri@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 00:24:27 by cyildiri          #+#    #+#             */
/*   Updated: 2017/06/30 00:31:35 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMERS_H
# define TIMERS_H
# define METRICS 1

#define TIMER_SETUP(VAR) \
	clock_t VAR_start;\
	clock_t VAR_diff;\
	int	VAR;
#define TIMER_START(VAR) \
	VAR_start = clock();
#define TIMER_STOP(VAR) \
	VAR_diff = clock() - VAR_start;\
	VAR = VAR_diff * 1000 / CLOCKS_PER_SEC;
#define TIMER_PRINT(PREFIX, VAR) \
	if (METRICS) \
		printf("%s took %d seconds %d milliseconds\n", PREFIX, VAR/1000, \
		VAR%1000);

#endif