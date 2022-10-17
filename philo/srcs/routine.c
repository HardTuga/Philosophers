/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/17 18:35:18 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_die(t_philos *philo)
{
	pthread_mutex_lock(&(philo->data->dead));
	if (philo->data->died > 0)
	{
		pthread_mutex_unlock(&(philo->data->dead));
		return (0);
	}
	if (philo->data->die < current_time(*philo) - philo->last_eat)
	{
		philo->data->died++;
		pthread_mutex_unlock(&(philo->data->dead));
		print_msg(philo, DEAD);
		return (0);
	}
	pthread_mutex_unlock(&(philo->data->dead));
	return (1);
}

void	print_msg(t_philos *philo, int option)
{
	pthread_mutex_lock(&(philo->data->msg));
	if (option == EATING && philo_die(philo))
		printf("%lld %d is eating\n", current_time(*philo), philo->philo_n);
	else if (option == SLEEPING && philo_die(philo))
		printf("%lld %d is sleeping\n", current_time(*philo), philo->philo_n);
	else if (option == THINKING && philo_die(philo))
		printf("%lld %d is thinking\n", current_time(*philo), philo->philo_n);
	else if (option == FORK && philo_die(philo))
	{
		printf("%lld %d has taken a fork\n", current_time(*philo),
			philo->philo_n);
	}
	else if (option == DEAD)
		printf("%lld %d died\n", current_time(*philo), philo->philo_n);
	pthread_mutex_unlock(&(philo->data->msg));
}

void	philo_eat(t_philos *philo)
{
	philo->status = EATING;
	print_msg(philo, EATING);
	philo->last_eat = current_time(*philo);
	smart_sleep(philo, philo->data->eat);
	drop_forks(philo, philo->philo_n - 1,
		philo->philo_n % philo->data->n_philos);
	if (philo->n_eat > 0)
		philo->n_eat--;
}

void	philo_sleep(t_philos *philo)
{
	philo->status = SLEEPING;
	print_msg(philo, SLEEPING);
	smart_sleep(philo, philo->data->sleep);
}

void	*start_routine(void *idk)
{
	t_philos	*philo;

	philo = idk;
	if (philo->philo_n % 2 == 0)
		usleep((philo->data->eat * 1000) / 2);
	while (philo->n_eat != 0 && philo_die(philo))
	{
		if (philo->status == THINKING && philo_die(philo))
		{
			if (!grab_forks(philo, philo->philo_n - 1,
					philo->philo_n % philo->data->n_philos))
				return (NULL);
			philo_eat(philo);
		}
		else if (philo->status == EATING && philo_die(philo))
			philo_sleep(philo);
		else if (philo->status == SLEEPING && philo_die(philo))
		{
			philo->status = THINKING;
			print_msg(philo, THINKING);
		}
	}
	return (NULL);
}
