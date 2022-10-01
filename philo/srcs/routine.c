/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/01 17:19:44 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_forks(t_philos *philo, int id, int r, int l)
{
	if (id % 2 == 0)
	{
		if (pthread_mutex_lock(&(philo->data.forks[r]))
			|| pthread_mutex_lock(&(philo->data.forks[l])))
			return (0);
	}
	else
	{
		if (pthread_mutex_lock(&(philo->data.forks[l]))
			|| pthread_mutex_lock(&(philo->data.forks[r])))
			return (0);
	}
	printf("%lld %d grabed 2 forks\n", current_time(*philo), id);
	return (1);
}

void	philo_eat(t_philos *philo)
{
	printf("%lld %d is eating\n", current_time(*philo), philo->philo_n);
	philo->last_eat = current_time(*philo);
	usleep(philo->data.eat * 1000);
	if (philo->philo_n == philo->data.n_philos)
	{
		pthread_mutex_unlock(&(philo->data.forks[philo->philo_n - 1]));
		pthread_mutex_unlock(&(philo->data.forks[0]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->data.forks[philo->philo_n - 1]));
		pthread_mutex_unlock(&(philo->data.forks[philo->philo_n]));
	}
	//printf("%lld %d droped both forks\n", current_time(*philo), philo->philo_n);
}

void	*start_routine(void *idk)
{
	int			forks;
	int			id;
	t_philos	*philo;

	philo = idk;
	forks = 0;
	id = philo->philo_n;
	while (forks != 1)
	{
		if (id == philo->data.n_philos)
			forks = grab_forks(philo, id, id - 1, 0);
		else
			forks = grab_forks(philo, id, id - 1, id);
	}
	philo_eat(philo);
	printf("%lld %d is sleeping\n", current_time(*philo), id);
	usleep(philo->data.sleep * 1000);
	if (philo->data.repeat == -1)
		start_routine(philo);
	return (NULL);
}
