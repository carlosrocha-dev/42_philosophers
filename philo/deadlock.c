/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:26:18 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 15:16:42 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct
{
	pthread_mutex_t mutex1;
	pthread_mutex_t mutex2;
} Mutexes;

void	*thread1_function(void *ptr)
{
	Mutexes *mutexes = (Mutexes *)ptr;

	pthread_mutex_lock(&mutexes->mutex1);
	printf("Thread 1: Bloqueou mutex1.\n");
	sleep(1);

	printf("Thread 1: Tentando bloquear mutex2...\n");
	pthread_mutex_lock(&mutexes->mutex2);
	printf("Thread 1: Bloqueou mutex2.\n");

	pthread_mutex_unlock(&mutexes->mutex2);
	pthread_mutex_unlock(&mutexes->mutex1);
	return NULL;
}

void	*thread2_function(void *ptr)
{
	Mutexes *mutexes = (Mutexes *)ptr;

	pthread_mutex_lock(&mutexes->mutex2);
	printf("Thread 2: Bloqueou mutex2.\n");
	sleep(1);
	printf("Thread 2: Tentando bloquear mutex1...\n");
	pthread_mutex_lock(&mutexes->mutex1);
	printf("Thread 2: Bloqueou mutex1.\n");
	pthread_mutex_unlock(&mutexes->mutex1);
	pthread_mutex_unlock(&mutexes->mutex2);
	return NULL;
}

int	main(void)
{
	pthread_t thread1, thread2;
	Mutexes mutexes;

	pthread_mutex_init(&mutexes.mutex1, NULL);
	pthread_mutex_init(&mutexes.mutex2, NULL);

	pthread_create(&thread1, NULL, thread1_function, &mutexes);
	pthread_create(&thread2, NULL, thread2_function, &mutexes);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutexes.mutex1);
	pthread_mutex_destroy(&mutexes.mutex2);

	return 0;
}
