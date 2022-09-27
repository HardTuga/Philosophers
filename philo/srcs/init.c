/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/27 16:15:49 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_forks(t_philos *philo, int id, int	r, int l)
{
	if(id % 2 == 0)
	{
		if(pthread_mutex_lock(&(philo->data.forks[r])) || pthread_mutex_lock(&(philo->data.forks[l])))
			return (0);
	}
	else
	{
		if(pthread_mutex_lock(&(philo->data.forks[l])) || pthread_mutex_lock(&(philo->data.forks[r])))
			return (0);
	}
	printf("O philo %d agarrou em 2 garfos\n", id);
	return(1);
}

void	*rotina_de_teste(void *cenas)
{
	int 	forks;
	int		id;
	t_philos *philo;

	philo = cenas;
	forks = 0;
	id = philo->philo_n;
	while(forks != 1)
	{
		if (id == philo->data.n_philos)
			forks = grab_forks(philo, id, id - 1, 0);
		else
			forks = grab_forks(philo, id, id - 1, id);
	}
	if (id == philo->data.n_philos)
	{
		pthread_mutex_unlock(&(philo->data.forks[id - 1]));
		pthread_mutex_unlock(&(philo->data.forks[0]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->data.forks[id - 1]));
		pthread_mutex_unlock(&(philo->data.forks[id]));
	}
	printf("O philo %d largou os garfos\n", id);
	return (NULL);
}

int	init(t_philos *philos)
{
	int i;
	
	i = -1;
	while(++i < philos->data.n_philos)
		if(pthread_mutex_init(&(philos->data.forks[i]), NULL))
			return (0);
	i = -1;
	while(++i < philos->data.n_philos)
	{
		philos[i].philo_n = i + 1;
		if(pthread_create(&(philos[i]).tid, NULL, rotina_de_teste, (void*)&(philos[i])))
			return (0);
	}
	i = -1;
	while(++i < philos->data.n_philos)
		pthread_join((philos[i]).tid, NULL);
	return(1);
}