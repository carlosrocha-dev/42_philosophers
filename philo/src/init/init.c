/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:49:47 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/23 12:29:45 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

void	*parse_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args) * argc);
	if (!args)
	{
		printf("Error: malloc\n");
		exit(1);
	}
	args->num_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	// if (argc == 6)
	// 	args->num_meals = ft_atoi(argv[5]);
}
