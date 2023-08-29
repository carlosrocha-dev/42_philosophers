/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:15:19 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/29 09:15:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	res;
	int	i;

	signal = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			signal = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += (nptr[i] - 48);
		i++;
	}
	return (res * signal);
}

int	input_parser(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	timestamp(long long previous_time)
{
	long long		current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time - previous_time);
}

void	print_philo(t_args *args, int philo_id, char *s)
{
	pthread_mutex_lock(&(args->write_mutex));
	if (!anyone_dying_soon(args))
	{
		printf("%lli ", timestamp(args->start_time));
		printf("%i ", philo_id);
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&(args->write_mutex));
}

void	philo_sleep_and_think(t_args *args, t_philo *philo)
{
	print_philo(args, philo->id, "is sleeping");
	usleep(args->time_to_sleep * 1000);
	print_philo(args, philo->id, "is thinking");
	if (philo->id % 2)
		usleep(3000);
}
