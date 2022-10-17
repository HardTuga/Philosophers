/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:19:10 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/09 15:21:17 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		return (0);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= 48 && av[i][j] <= 57))
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	fill_data(char **av, t_data *data)
{
	data->n_philos = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->repeat = ft_atoi(av[5]);
		if (data->repeat < 1)
			return (0);
	}
	else
		data->repeat = -1;
	if (data->n_philos < 1 || data->die < 1 || data->eat < 1 || data->sleep < 1)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (0);
	data->forks_status = malloc(sizeof(int) * data->n_philos);
	if (!data->forks_status)
	{
		free(data->forks);
		return (0);
	}
	memset(data->forks_status, 0, data->n_philos * sizeof(int));
	return (1);
}

t_philos	fill_philo(t_data *data)
{
	t_philos	philo;

	philo.status = THINKING;
	philo.data = data;
	if (data->repeat == -1)
		philo.n_eat = -1;
	else
		philo.n_eat = data->repeat;
	philo.time_init = get_timer();
	philo.last_eat = philo.time_init;
	philo.n_forks = 0;
	return (philo);
}

int	init(t_philos *philos)
{
	int	i;

	if (pthread_mutex_init(&(philos->data->dead), NULL)
		|| pthread_mutex_init(&(philos->data->msg), NULL))
		return (0);
	i = -1;
	while (++i < philos->data->n_philos)
		if (pthread_mutex_init(&(philos->data->forks[i]), NULL))
			return (0);
	i = -1;
	while (++i < philos->data->n_philos)
	{
		philos[i].philo_n = i + 1;
		if (pthread_create(&(philos[i]).tid, NULL, start_routine,
				(void*) &(philos[i])))
			return (0);
	}
	i = -1;
	while (++i < philos->data->n_philos)
		pthread_join(philos[i].tid, NULL);
	return (1);
}

int	main(int ac, char **av)
{
	int				i;
	t_philos		*philos;
	static t_data	data;

	if (!check_args(ac, av) || !fill_data(av, &data))
	{
		printf("Erro nos argumentos\n");
		return (0);
	}
	philos = malloc(sizeof(t_philos) * data.n_philos);
	if (!philos)
	{
		free(data.forks);
		free(data.forks_status);
		return (0);
	}
	i = -1;
	while (++i < data.n_philos)
		philos[i] = fill_philo(&data);
	if (!init(philos))
	{
		printf("Erro ao iniciar mutex ou threads\n");
		return (0);
	}
	end_prog(philos);
}
