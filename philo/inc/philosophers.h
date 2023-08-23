/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:30:35 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/23 12:23:30 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_args
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				is_dead;
	int				stop_simulation;
	int				meals_finished;
	long long		start_time;
}	t_args;

int		ft_isdigit(int c);
void	*parse_args(int argc, char **argv);
int		ft_atoi(const char *nptr);

#endif