/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:14:53 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/29 12:37:53 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_args	t_args;

typedef struct s_philo {
	int				id;
	pthread_t		th;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	int				is_done;
	pthread_mutex_t	is_done_mutex;
	int				times_ate;
	t_args			*args;
}	t_philo;

typedef struct s_args {
	int				philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				is_dead;
	int				stop_simulation;
	int				meals_finished;
	long long		start_time;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	sem_t			*available_forks;
}	t_args;

int			input_parser(int ac, char **av);
void		init_philosophers(t_args *args);
t_args		*init_args(int ac, char **av);
void		*philosophers_routine(void *arg);
int			start_simulation(t_args *args);
int			terminate(t_args *args);
long long	timestamp(long long previous_time);
void		print_philo(t_args *args, int philo_id, char *s);
void		philosophers_actions(t_philo *philo, t_args *args);
void		observe_and_terminate(t_args *args);
int			anyone_dying_soon(t_args *args);
int			all_philos_done_eating(t_args *args);
int			philo_finished_eating(t_philo *philo);
void		*single_philosopher_routine(void *void_philo);
int			single_philosopher_simulation(t_args *args);
int			is_philo_dying(t_args *args, t_philo *philo);
void		philo_sleep_and_think(t_args *args, t_philo *philo);
int			ft_atoi(const char *nptr);

#endif
