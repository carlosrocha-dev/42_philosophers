/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:13:58 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 09:34:08 by caalbert         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_args	*args;

	printf("Init Philo:\n");
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (!args_analyser(ac, av))
		return (1);
	printf("Pass analyser:\n");
	printf("Args_analyser: %d\n\n\n", args_analyser(ac, av));
	args = parse_args(ac, av);
	if (!args)
		return (1);
	printf("Pass args validator:\n");
	printf("Number of philosophers: %d\n", args->num_philo);
	printf("Time to die: %d\n", args->time_to_die);
	printf("Time to eat: %d\n", args->time_to_eat);
	printf("Time to sleep: %d\n", args->time_to_sleep);
	printf("Number of meals: %d\n", args->num_meals);
	printf("\n");
	return (0);
}
