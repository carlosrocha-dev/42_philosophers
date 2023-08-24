/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:14:28 by caalbert          #+#    #+#             */
/*   Updated: 2023/08/24 14:22:34 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*show_msg(void *ptr)
{
	char	*message;

	message = (char *) ptr;
	printf("%s\n", message);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	char		*message1;
	char		*message2;
	int			iret1;
	int			iret2;

	message1 = "Thread 1";
	message2 = "Thread 2";
	iret1 = pthread_create(&thread1, NULL, show_msg, (void *) message1);
	iret2 = pthread_create(&thread2, NULL, show_msg, (void *) message2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Thread 1 retorna: %d\n", iret1);
	printf("Thread 2 retorna: %d\n", iret2);
	return (0);
}
