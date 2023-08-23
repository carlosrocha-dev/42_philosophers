/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:13:58 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/23 10:29:40 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosoplhers.h"

int args_analyser(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Error: wrong argument\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (!args_analyser(ac, av))
		return (1);
	return (0);
}
