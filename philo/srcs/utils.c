/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:36:02 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/17 15:18:09 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(t_philos *philo, int time)
{
	long long	start;

	start = get_timer();
	while (philo_die(philo))
	{
		if (get_timer() - start > time)
			break ;
	}
}

int	ft_atoi(const char *str)
{
	int			s;
	long long	n;

	s = 1;
	n = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		s *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		n = (n * 10) + (s * (*str - '0'));
		str++;
		if (n > 2147483647)
			return (-1);
		if (n < -2147483648)
			return (0);
	}
	return (n);
}
