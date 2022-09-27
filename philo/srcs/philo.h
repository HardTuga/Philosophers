/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:38:12 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/27 16:26:41 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------------------------INCLUDES------------------------------//
# include	<stdio.h>
# include	<stdlib.h>
# include	<pthread.h>
# include   <sys/time.h>

//------------------------------DEFINES------------------------------//

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
	struct timeval	current_t;
}				t_data;

typedef struct s_philos
{
	pthread_t		tid;
	int				philo_n;
	struct timeval	last_meal;
	t_data			data;
}				t_philos;

//------------------------------PHILO_MAIN------------------------------//
int 	check_args(int ac, char **av);

//------------------------------INIT------------------------------//
int		init(t_philos *philos);
void	*rotina_de_teste(void *cenas);

//------------------------------TIMER------------------------------//
int		get_time();
//------------------------------UTILS------------------------------//
int		ft_atoi(const char *str);

#endif
