/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:50:39 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/26 20:38:39 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

//NOTE: sequência de ações realizadas por um filósofo durante a simulação
void	philo_actions(t_philo *philo, t_args *args)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&(args->forks[philo->left_fork]));
		print_philo(args, philo->id, "GREEN has taken a fork 🍴");
		pthread_mutex_lock(&(args->forks[philo->right_fork]));
		print_philo(args, philo->id, "has taken a fork 🍴");
	}
	else
	{
		pthread_mutex_lock(&(args->forks[philo->right_fork]));
		print_philo(args, philo->id, "GREEN hhas taken a fork 🍴");
		pthread_mutex_lock(&(args->forks[philo->left_fork]));
		print_philo(args, philo->id, "GREEN hhas taken a fork 🍴");
	}
	pthread_mutex_lock(&(args->last_meal_mutex));
	philo->last_meal = timestamp(0);
	pthread_mutex_unlock(&(args->last_meal_mutex));
	print_philo(args, philo->id, "YELLOW is eating 🍝");
	usleep(args->time_to_eat * 1000);
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	pthread_mutex_unlock(&(args->forks[philo->right_fork]));
}

void	*single_philosopher_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	pthread_mutex_lock(&(args->forks[philo->left_fork]));
	print_philo(args, philo->id, "GREEN has taken a fork");
	printf("Philosopher %d GREEN has taken a fork\n", philo->id);
	usleep(args->time_to_die * 1000);
	printf("RED Philosopher %d died 💀\n", philo->id);
	print_philo(args, philo->id, "RED died 💀");
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	return (NULL);
}

void	philosopher_sleep_and_think(t_args *args, t_philo *philo)
{
	print_philo(args, philo->id, "PURPLE is sleeping 😴");
	usleep(args->time_to_sleep * 1000);
	print_philo(args, philo->id, "PURPLE is thinking 🤔");
	if (philo->id % 2)
		usleep(3000);
}

void	*philo_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	while (1)
	{
		if (anyone_dying_soon(args))
			break ;
		if (args->num_meals != -1
			&& philo->times_ate >= args->num_meals)
		{
			pthread_mutex_lock(&(philo->is_done_mutex));
			philo->is_done = 1;
			pthread_mutex_unlock(&(philo->is_done_mutex));
			break ;
		}
		philo_actions(philo, args);
		philo->times_ate += 1;
		philosopher_sleep_and_think(args, philo);
	}
	return (NULL);
}
