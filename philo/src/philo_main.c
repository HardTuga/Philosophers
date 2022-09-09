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
	int i;
	int j;

	i = -1;
	if(ac < 4 || ac > 5)
		return (0);
	while(av[++i])
	{
		while(av[i][++j])
		{
			if(!ft_isdigit(av[i]))
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	fill_struct(char **av, t_data *data)
{
	data->n_philos = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (av[5])
		data->repeat = ft_atoi(av[5]);
	if (data->n_philos < 1 || data->die < 1 || data->eat < 1 ||
		data->sleep < 1 || data->repeat < 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data data;
	t_philo	*philo;

	if(!check_args(ac, av))
	{
		ft_putstr_fd("Erro nos argumentos\n", 2);
		return (-1);
	}
	if(!fill_struct(av, &data))
	{
		ft_putstr_fd("Erro no valor dos argumentos\n", 2);
		return (-1);
	}
	philo = malloc(sizeof(t_philo) * data.n_philos);
}