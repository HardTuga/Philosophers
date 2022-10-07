/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:17:21 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/07 16:40:00 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_prog(t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->n_philos)
		pthread_mutex_destroy(&philos->data->forks[i]);
	// free(philos->data->forks);
	pthread_mutex_destroy(&philos->data->dead);
	free(philos);
}
