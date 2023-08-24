/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:30:21 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 19:34:48 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philosophers.h"

typedef struct s_args	t_args;
typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	int				is_done;
	int				time_to_ate;
	t_args			*args;
	pthread_t		thread;
	pthread_mutex_t	is_done_mutex;
}	t_philo;

typedef struct s_args
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				is_dead;
	int				stop_simulation;
	int				meals_finished;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*forks;
}	t_args;

#endif