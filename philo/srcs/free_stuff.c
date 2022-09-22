/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:17:21 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/22 12:37:36 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data data, t_philos *philos)
{
	free_data(data);
    free_philos(data, philos);
}

void	free_data(t_data data)
{
	if (data.forks)
		pthread_mutex_destroy(data.forks);
	if (data.dead)
		pthread_mutex_destroy(data.dead);
}

void	free_philos(t_data data, t_philos *philos)
{
	
}