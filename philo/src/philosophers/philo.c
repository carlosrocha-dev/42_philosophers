/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:50:39 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 20:03:43 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

//NOTE: sequência de ações realizadas por um filósofo durante a simulação
void	philo_actions(void)
{
	printf("Philosopher is thinking\n");
	printf("Philosopher is eating\n");
	printf("Philosopher is sleeping\n");
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

/*
NOTE: implementa a rotina de execução contínua de um filósofo
durante a simulação
*/
void	*philo_routine(void)
{
	while (1)
	{
		printf("Philosopher is thinking\n");
		printf("Philosopher is eating\n");
		printf("Philosopher is sleeping\n");
	}
}
