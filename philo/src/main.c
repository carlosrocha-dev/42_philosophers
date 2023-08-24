/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:13:58 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 18:42:00 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	args_analyser(int ac, char **av)
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

void	*single_philosopher_routine(void *void_philo)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_philo;
	args = philo->args;
	pthread_mutex_lock(&(args->forks[philo->left_fork]));
	print_philo(args, philo->id, "has taken a fork");
	printf("Philosopher %d has taken a fork\n", philo->id);
	usleep(args->time_to_die * 1000);
	printf("Philosopher %d died\n", philo->id);
	print_philo(args, philo->id, "died");
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
	return (NULL);
}

int	main(int ac, char **av)
{
	t_args	*args;

	if (ac < 5 || ac > 6)
		return (1);
	if (!args_analyser(ac, av))
		return (1);
	args = parse_args(ac, av);
	if (!args)
		return (1);
	if (args->num_philo == 1)
	{
		printf("Starting single philosopher simulation...\n");
		long long start_time = timestamp(0);
		if (single_philosopher_simulation(args))
		{
			printf("Error: single philosopher simulation failed\n");
			return 1;
		}
		long long end_time = timestamp(start_time);
		printf("Single philosopher simulation completed in %lld ms\n", end_time);
		return (0);
	}
	return (0);
}
