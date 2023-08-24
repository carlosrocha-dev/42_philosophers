/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:30:35 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 18:23:08 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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

int			ft_isdigit(int c);
void		*parse_args(int argc, char **argv);
int			ft_atoi(const char *nptr);
int			validate_input(int philo_count, t_args *args);
void		*single_philosopher_routine(void *void_philo);
int			single_philosopher_simulation(t_args *args);
void		print_philo(t_args *args, int philo_id, char *s);
long long	timestamp(long long previous_time);
int			single_philosopher_simulation(t_args *args);
void		*single_philosopher_routine(void *void_philo);

#endif