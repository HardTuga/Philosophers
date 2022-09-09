/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:38:12 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/09 15:36:01 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------------------------INCLUDES------------------------------//
# include	"../libft/libft.h"
# include   <sys/time.h>
# include	<pthread.h>

//------------------------------STRUCTS------------------------------//
typedef struct s_data
{
	int	n_philos;
	int	die;
	int	eat;
	int	sleep;
	int	repeat;
}				t_data;

typedef struct s_philo
{
	int	*dead;
	pthread_t	philo_id;
}				t_philo;

//------------------------------PHILO_MAIN------------------------------//
int check_args(int ac, char **av);

#endif
