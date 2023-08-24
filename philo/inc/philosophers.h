/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:30:35 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 20:30:11 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "structs.h"

int			ft_isdigit(int c);
void		*parse_args(int argc, char **argv);
int			ft_atoi(const char *nptr);
int			validate_input(int philo_count, t_args *args);
void		*single_philosopher_routine(void *void_philo);
int			single_philosopher_simulation(t_args *args);
void		print_philo(t_args *args, int philo_id, char *s);
long long	timestamp(long long previous_time);
int			single_philosopher_simulation(t_args *args);
void		*single_philosopher_routine(void *void_philo);
int			anyone_dying_soon(t_args *args);
int			is_philo_dying(t_args *args, t_philo *philo);
int			all_philos_done_eating(t_args *args);
int			philo_finished_eating(t_philo *philo);
void		observe_and_terminate(t_args *args);
#endif