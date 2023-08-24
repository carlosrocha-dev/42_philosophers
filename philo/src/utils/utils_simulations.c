/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simulations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:19:40 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 20:19:46 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

long long	timestamp(long long previous_time);

void	print_philo(t_args *args, int philo_id, char *s)
{
	pthread_mutex_lock(&(args->write_mutex));
	printf("%lli ", timestamp(args->start_time));
	printf("%i ", philo_id);
	printf("%s\n", s);
	pthread_mutex_unlock(&(args->write_mutex));
}

int	single_philosopher_simulation(t_args *args)
{
	if (pthread_create(&args->philo[0].thread, NULL,
			&single_philosopher_routine, &(args->philo[0])))
		return (1);
	args->philo[0].last_meal = timestamp(0);
	return (0);
}

long long	timestamp(long long previous_time)
{
	long long		current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time - previous_time);
}
