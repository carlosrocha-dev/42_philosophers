/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:12:25 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 17:07:21 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

static void	messages(const char *message)
{
	printf("Error: %s\n", message);
}

int	validate_input(int philo_count, t_args *args)
{
	if (philo_count > 200)
	{
		messages("too many philosophers");
		return (1);
	}
	if (philo_count < 1)
	{
		messages("too few philosophers");
		return (1);
	}
	if (args->time_to_die < 60 || args->time_to_eat < 60 || \
	args->time_to_sleep < 60)
	{
		messages("time values are too short");
		return (1);
	}
	return (0);
}
