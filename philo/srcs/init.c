/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/22 15:13:23 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_data data, t_philos *philos)
{
	int i;
	
	philos = malloc(sizeof(t_philos) * data.n_philos);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.n_philos);
	i = 0;
	while(++i <= data.n_philos)
	{
		(philos[i - 1]).philo_n = i;
		pthread_create(&(philos[i - 1]).tid, NULL, rotina_de_teste, (void*)&(philos[i - 1]));
	}
	i = 0;
	while(++i <= data.n_philos)
		pthread_join((philos[i - 1]).tid, NULL);
	printf("Tou aqui.\n");
}