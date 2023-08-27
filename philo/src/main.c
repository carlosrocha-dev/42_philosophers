/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:13:58 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/26 21:43:46 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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

	if (ac < 5 || ac > 6)
		return (1);
	if (!args_analyser(ac, av))
		return (1);
	args = parse_args(ac, av);
	if (!args)
		return (1);
	if (args->num_philo == 1)
	{
		if (single_philosopher_simulation(args))
			return (1);
		return (0);
	}
	if (start_simulation(args))
		return (1);
	return (0);
}
