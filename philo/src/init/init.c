/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:49:47 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/26 20:39:47 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void	create_philosophers(t_args *args);

void	*parse_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args) * argc);
	if (!args)
		return (NULL);
	args->num_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->num_meals = -1;
	if (argc == 6)
		args->num_meals = ft_atoi(argv[5]);
	args->is_dead = 0;
	args->stop_simulation = 0;
	args->meals_finished = 0;
	create_philosophers(args);
	free(args);
	return (args);
}

void	create_philosophers(t_args *args)
{
	int	i;

	i = 0;
	args->philo = malloc(sizeof(t_philo) * (args->num_philo + 1));
	while (++i < args->num_philo)
	{
		args->philo[i].id = i;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->num_philo;
		args->philo[i].last_meal = 0;
		args->philo[i].times_ate = 0;
		args->philo[i].is_done = 0;
		args->philo[i].args = args;
	}
}

int	init_mutex(t_args *args)
{
	int	i;

	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (args->num_philo));
	if (!args->forks)
		return (1);
	i = -1;
	while (++i < args->num_philo)
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
