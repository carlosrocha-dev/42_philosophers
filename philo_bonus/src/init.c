/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:15:01 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/29 09:15:02 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Initialize philosophers
*/
void	init_philosophers(t_args *args)
{
	int	i;

	i = -1;
	args->philo = (t_philo *)malloc(sizeof(t_philo) * (args->philosophers + 1));
	while (++i < args->philosophers)
	{
		args->philo[i].id = i + 1;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->philosophers;
		args->philo[i].last_meal = 0;
		args->philo[i].times_ate = 0;
		args->philo[i].is_done = 0;
		args->philo[i].args = args;
	}
}

/*
Initialize mutexes
*/
int	init_mutex(t_args *args)
{
	int	i;

	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (args->philosophers));
	if (!args->forks)
		return (1);
	i = -1;
	while (++i < args->philosophers)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (1);
		if (pthread_mutex_init(&(args->philo[i].is_done_mutex), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(args->write_mutex), NULL))
		return (1);
	if (pthread_mutex_init(&(args->last_meal_mutex), NULL))
		return (1);
	if (pthread_mutex_init(&(args->death_mutex), NULL))
		return (1);
	return (0);
}

/*
Initialize arguments
*/
t_args	*init_args(int ac, char **av)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->philosophers = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->number_of_meals = -1;
	if (ac == 6)
		args->number_of_meals = ft_atoi(av[5]);
	args->start_time = timestamp(0);
	args->is_dead = 0;
	args->stop_simulation = 0;
	args->meals_finished = 0;
	init_philosophers(args);
	if (init_mutex(args))
		return (NULL);
	return (args);
}

/*
Create thread for single philosopher
*/
int	single_philosopher_simulation(t_args *args)
{
	if (pthread_create(&args->philo[0].th, NULL,
			&single_philosopher_routine, &(args->philo[0])))
		return (1);
	args->philo[0].last_meal = timestamp(0);
	terminate(args);
	return (0);
}

/*
Create threads for each philosopher
*/
int	start_simulation(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->philosophers)
	{
		if (pthread_create(&args->philo[i].th, NULL,
				&philosophers_routine, &(args->philo[i])))
			return (1);
		pthread_mutex_lock(&(args->last_meal_mutex));
		args->philo[i].last_meal = timestamp(0);
		pthread_mutex_unlock(&(args->last_meal_mutex));
	}
	observe_and_terminate(args);
	terminate(args);
	return (0);
}
