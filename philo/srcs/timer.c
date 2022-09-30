/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:15:58 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/30 16:39:03 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timer()
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	return ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));
}

long long	current_time(t_philos philo)
{
	struct timeval time_now;
	long long	time;
	
	printf("Init: %lld\n", philo.time_init);
	gettimeofday(&time_now, NULL);
	time = ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000)) - philo.time_init;
	//printf("Now: %ld\n", ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000)));
	return (time);
}