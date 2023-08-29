/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:15:11 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/29 09:15:12 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Check if there's a request to stop the simulation due to a philosopher's death.
*/
int	anyone_dying_soon(t_args *args)
{
	pthread_mutex_lock(&(args->death_mutex));
	if (args->stop_simulation)
	{
		pthread_mutex_unlock(&(args->death_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(args->death_mutex));
	return (0);
}

/*
Check if the philosopher's last meal time exceeds the time to die.
*/
int	is_philo_dying(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->last_meal_mutex));
	if (timestamp(philo->last_meal) > args->time_to_die)
	{
		pthread_mutex_unlock(&(args->last_meal_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(args->last_meal_mutex));
	return (0);
}

/*
Check if all philosophers are done eating.
*/
int	all_philos_done_eating(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->philosophers)
	{
		pthread_mutex_lock(&(args->philo[i].is_done_mutex));
		if (!(args->philo[i].is_done))
		{
			pthread_mutex_unlock(&(args->philo[i].is_done_mutex));
			return (0);
		}
		pthread_mutex_unlock(&(args->philo[i].is_done_mutex));
	}
	return (1);
}

/*
Check if a particular philosopher is done eating.
*/
int	philo_finished_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->is_done_mutex));
	if (!(philo->is_done))
	{
		pthread_mutex_unlock(&(philo->is_done_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(philo->is_done_mutex));
	return (1);
}

/*
Observe philosophers and terminate simulation if necessary
*/
void	observe_and_terminate(t_args *args)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < args->philosophers)
		{
			if (is_philo_dying(args, &args->philo[i])
				&& (!philo_finished_eating(&args->philo[i])))
			{
				print_philo(args, args->philo[i].id, "died");
				args->is_dead = 1;
			}
		}
		i = -1;
		if (all_philos_done_eating(args))
			break ;
		if (args->is_dead)
		{
			pthread_mutex_lock(&(args->death_mutex));
			args->stop_simulation = 1;
			pthread_mutex_unlock(&(args->death_mutex));
			break ;
		}
	}
}
