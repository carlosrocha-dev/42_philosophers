/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:31:43 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/26 21:51:13 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	terminate(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philo)
		pthread_join(args->philo[i].thread, NULL);
	i = -1;
	while (++i < args->num_philo)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		pthread_mutex_destroy(&(args->philo[i].is_done_mutex));
	}
	pthread_mutex_destroy(&(args->write_mutex));
	pthread_mutex_destroy(&(args->last_meal_mutex));
	pthread_mutex_destroy(&(args->death_mutex));
	if (args->philo)
		free(args->philo);
	if (args->forks)
		free(args->forks);
	if (args)
		free(args);
	return (0);
}
