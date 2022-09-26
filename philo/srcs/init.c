/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/26 16:24:36 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_forks(t_philos *philo, int id)
{
	if(id == 1)
	{
		if(!pthread_mutex_lock(&(philo->data->forks[id - 1])) || !pthread_mutex_lock(&(philo->data->forks[philo->data->n_philos])))
			return (0);
	}
	else
	{
		if(!pthread_mutex_lock(&(philo->data->forks[id - 1])) || !pthread_mutex_lock(&(philo->data->forks[id - 2])))
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
	//(void)forks;
	id = philo->philo_n;
	//printf("ID:%d\n", id);
	while(forks != 1)
		forks = grab_forks(philo, id);
	if (id == 1)
	{
		pthread_mutex_unlock(&(philo->data->forks[id - 1]));
		pthread_mutex_lock(&(philo->data->forks[philo->data->n_philos]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->data->forks[id - 1]));
		pthread_mutex_lock(&(philo->data->forks[id - 2]));
	}
	printf("O philo %d largou os garfos\n", id);
	return (NULL);
}

int	init(t_philos *philos)
{
	int i;
	
	i = -1;
	while(++i < philos->data->n_philos)
		if(pthread_mutex_init(&(philos->data->forks[i]), NULL))
			return (0);
	i = -1;
	while(++i < philos->data->n_philos)
	{
		philos[i].philo_n = i + 1;
		if(pthread_create(&(philos[i]).tid, NULL, rotina_de_teste, (void*)&(philos[i])))
			return (0);
	}
	i = -1;
	while(++i < philos->data->n_philos)
		pthread_join((philos[i]).tid, NULL);
	return(1);
}