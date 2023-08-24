/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:16:25 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 20:28:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	anyone_dying_soon(t_args *args);
/*
NOTE: Verifica se algum filósofo está prestes a morrer (morte iminente);
*/

int	is_philo_dying(t_args *args, t_philo *philo);
/*
NOTE: Verifica se um filósofo está em processo de morrer (não está morto,
mas está prestes a morrer).
*/

int	all_philos_done_eating(t_args *args);
/*
NOTE: Verifica se todos os filósofos terminaram de comer, indicando que a
simulação pode ser encerrada.
*/

int	philo_finished_eating(t_philo *philo);
/*
NOTE: Verifica se um filósofo terminou de comer todas as suas refeições,
indicando que ele concluiu sua parte da simulação.
*/

void	observe_and_terminate(t_args *args);
/*
NOTE: Observa os filósofos e verifica se algum deles está
 morrendo ou se todos terminaram de comer. Encerra a simulação se necessário.
*/
