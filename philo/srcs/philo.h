/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:38:12 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/01 17:14:48 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------------------------INCLUDES------------------------------//
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
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
}				t_data;

typedef struct s_philos
{
	pthread_t		tid;
	int				philo_n;
	t_data			data;
	long long		time_init;
	long long		last_eat;
}				t_philos;

//------------------------------PHILO_MAIN------------------------------//
int			check_args(int ac, char **av);
int			fill_data(char **av, t_data *data);
t_philos	fill_philo(t_data data);
int			init(t_philos *philos);

//------------------------------ROUTINE------------------------------//
void		*start_routine(void *cenas);
int			grab_forks(t_philos *philo, int id, int r, int l);

//------------------------------TIMER------------------------------//
long long	current_time(t_philos philo);
long long	get_timer(void);

//------------------------------UTILS------------------------------//
int			ft_atoi(const char *str);

#endif
