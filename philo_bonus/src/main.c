/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:15:08 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/29 13:01:55 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Routine for each philosopher in the simulation. This function represents
a philosopher's lifecycle, covering actions such as checking for death
conditions, eating, and sleeping.
*/
void	*philosophers_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	while (1)
	{
		if (anyone_dying_soon(args))
			break ;
		if (args->number_of_meals != -1
			&& philo->times_ate >= args->number_of_meals)
		{
			pthread_mutex_lock(&(philo->is_done_mutex));
			philo->is_done = 1;
			pthread_mutex_unlock(&(philo->is_done_mutex));
			break ;
		}
		philosophers_actions(philo, args);
		philo->times_ate += 1;
		philo_sleep_and_think(args, philo);
	}
	return (NULL);
}

/*
Execute a philosopher's actions: taking forks and eating.
*/
void	philosophers_actions(t_philo *philo, t_args *args)
{
	sem_wait(args->fork_sem);
	print_philo(args, philo->id, "has taken a fork");
	sem_wait(args->fork_sem);
	print_philo(args, philo->id, "has taken a fork");
	pthread_mutex_lock(&(args->last_meal_mutex));
	philo->last_meal = timestamp(0);
	pthread_mutex_unlock(&(args->last_meal_mutex));
	print_philo(args, philo->id, "is eating");
	usleep(args->time_to_eat * 1000);
	sem_post(args->fork_sem);
	sem_post(args->fork_sem);
}

/*
Routine for a lone philosopher: takes a fork and dies.
*/
void	*single_philosopher_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	pthread_mutex_lock(&(args->forks[philo->left_fork]));
	print_philo(args, philo->id, "has taken a fork");
	usleep(args->time_to_die * 1000);
	print_philo(args, philo->id, "died");
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		return (1);
	if (!input_parser(argc, argv))
		return (1);
	args = init_args(argc, argv);
	if (!args)
		return (1);
	if (args->philosophers == 1)
	{
		if (single_philosopher_simulation(args))
			return (1);
		return (0);
	}
	if (start_simulation(args))
		return (1);
	return (0);
}
