/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:43:04 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/26 20:45:43 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	start_simulation(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philo)
	{
		if (pthread_create(&args->philo[i].thread, NULL,
				&philo_routine, &(args->philo[i])))
			return (1);
		pthread_mutex_lock(&(args->last_meal_mutex));
		args->philo[i].last_meal = timestamp(0);
		pthread_mutex_unlock(&(args->last_meal_mutex));
	}
	observe_and_terminate(args);
	terminate(args);
	return (0);
}
