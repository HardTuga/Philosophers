/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/03 15:31:20 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_die(t_philos *philo)
{
	pthread_mutex_lock(&(philo->data.dead));
	if (philo->data.die > current_time(*philo) - philo->last_eat)
	{
		philo->data.died++;
		printf("%lld %d died\n", current_time(*philo), philo->philo_n);
		return (0);
	}
	pthread_mutex_unlock(&(philo->data.dead));
	return (1);
}

void	print_msg(t_philos *philo, int option)
{
	//pthread_mutex_lock(&(philo->data.dead));
	//if (philo->data.died > 0)
	//	return ;
	//pthread_mutex_lock(&(philo->data.dead));
	if (option == EATING)
		printf("%lld %d is eating\n", current_time(*philo), philo->philo_n);
	else if (option == SLEEPING)
		printf("%lld %d is sleeping\n", current_time(*philo), philo->philo_n);
	else if (option == THINKING)
		printf("%lld %d is thinking\n", current_time(*philo), philo->philo_n);
	else if (option == FORK)
	{
		printf("%lld %d has taken a fork\n", current_time(*philo),
			philo->philo_n);
		printf("%lld %d has taken a fork\n", current_time(*philo),
			philo->philo_n);
	}
}

int	grab_forks(t_philos *philo, int id, int r, int l)
{
	// if (!philo_die(philo))
		// return (0);
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
	print_msg(philo, FORK);
	return (1);
}

void	philo_eat(t_philos *philo)
{
	// if (!philo_die(philo))
		// return ;
	print_msg(philo, EATING);
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
}

void	*start_routine(void *idk)
{
	int			forks;
	int			id;
	t_philos	*philo;

	philo = idk;
	forks = 0;
	id = philo->philo_n;
	while (forks == 0)
	{
		if (id == philo->data.n_philos)
			forks = grab_forks(philo, id, id - 1, 0);
		else
			forks = grab_forks(philo, id, id - 1, id);
	}
	philo_eat(philo);
	// if (!philo_die(philo))
		// return (NULL);
	print_msg(philo, SLEEPING);
	usleep(philo->data.sleep * 1000);
	// if (!philo_die(philo))
		// return (NULL);
	print_msg(philo, THINKING);
	if (philo->data.repeat == -1)
		start_routine(philo);
	return (NULL);
}
