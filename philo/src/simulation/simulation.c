/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:16:25 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/26 19:30:05 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

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

int	all_philos_done_eating(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philo)
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

void	observe_and_terminate(t_args *args)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < args->num_philo)
		{
			if (is_philo_dying(args, &args->philo[i])
				&& (!philo_finished_eating(&args->philo[i])))
			{
				print_philo(args, args->philo[i].id, "RED died 💀");
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
