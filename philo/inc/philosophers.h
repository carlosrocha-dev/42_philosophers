/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:30:35 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 19:31:45 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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

#endif