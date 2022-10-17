/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:49:17 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/17 18:35:34 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philos *philo, int side)
{
	pthread_mutex_lock(&(philo->data->forks[side]));
	if (philo->data->forks_status[side] == AVAILABLE)
	{
		philo->data->forks_status[side] = TAKEN;
		philo->n_forks ++;
		print_msg(philo, FORK);
	}
	pthread_mutex_unlock(&(philo->data->forks[side]));
}

void	drop_forks(t_philos *philo, int r, int l)
{
	pthread_mutex_lock(&(philo->data->forks[r]));
	philo->data->forks_status[r] = AVAILABLE;
	pthread_mutex_unlock(&(philo->data->forks[r]));
	pthread_mutex_lock(&(philo->data->forks[l]));
	philo->data->forks_status[l] = AVAILABLE;
	pthread_mutex_unlock(&(philo->data->forks[l]));
	philo->n_forks = 0;
}

int	grab_forks(t_philos *philo, int r, int l)
{
	if (philo->data->n_philos == 1)
	{
		printf("0 %d has taken a fork\n", philo->philo_n);
		usleep(philo->data->die * 1000);
		printf("%d %d died\n", philo->data->die, philo->philo_n);
		return (0);
	}
	while (philo->n_forks < 2)
	{
		if (philo_die(philo))
			take_fork(philo, r);
		if (philo_die(philo))
			take_fork(philo, l);
		if (!philo_die(philo))
			return (0);
	}
	return (1);
}
