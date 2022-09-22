/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:38:12 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/22 14:44:38 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------------------------INCLUDES------------------------------//
# include   <sys/time.h>
# include	<pthread.h>
# include	<stdio.h>
# include	<stdlib.h>

//------------------------------STRUCTS------------------------------//
typedef struct s_data
{
	int				n_philos;
	int				die;
	int				eat;
	int				sleep;
	int				repeat;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*forks;
}				t_data;

typedef struct s_philos
{
	pthread_t	tid;
	int			philo_n;
}				t_philos;

//------------------------------PHILO_MAIN------------------------------//
int check_args(int ac, char **av);

//------------------------------UTILS------------------------------//
int	ft_atoi(const char *str);

#endif
