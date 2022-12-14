/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:38:12 by pcampos-          #+#    #+#             */
/*   Updated: 2022/10/17 14:43:10 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------------------------INCLUDES------------------------------//
# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<pthread.h>
# include   <sys/time.h>

//------------------------------DEFINES------------------------------//
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define FORK		4
# define DEAD		5
# define AVAILABLE	0
# define TAKEN		1

//------------------------------STRUCTS------------------------------//
typedef struct s_data
{
	int				n_philos;
	int				die;
	int				eat;
	int				sleep;
	int				repeat;
	pthread_mutex_t	dead;
	pthread_mutex_t	msg;
	int				died;
	pthread_mutex_t	*forks;
	int				*forks_status;
}				t_data;

typedef struct s_philos
{
	pthread_t		tid;
	int				philo_n;
	int				status;
	int				n_forks;
	t_data			*data;
	int				n_eat;
	long long		time_init;
	long long		last_eat;
}				t_philos;

//------------------------------PHILO_MAIN------------------------------//
int			check_args(int ac, char **av);
int			fill_data(char **av, t_data *data);
t_philos	fill_philo(t_data *data);
int			init(t_philos *philos);

//------------------------------ROUTINE------------------------------//
void		*start_routine(void *cenas);
void		philo_eat(t_philos *philo);
void		print_msg(t_philos *philo, int option);
int			philo_die(t_philos *philo);

//------------------------------FORKS------------------------------//
int			grab_forks(t_philos *philo, int r, int l);
void		drop_forks(t_philos *philo, int r, int l);

//------------------------------TIMER------------------------------//
long long	current_time(t_philos philo);
long long	get_timer(void);

//------------------------------END_PROG------------------------------//
void		end_prog(t_philos *philos);

//------------------------------UTILS------------------------------//
void		smart_sleep(t_philos *philo, int time);
int			ft_atoi(const char *str);

#endif
