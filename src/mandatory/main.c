/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:56:50 by rkerman           #+#    #+#             */
/*   Updated: 2025/05/13 15:35:36 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <pthread.h>
#include <stdio.h>
/*
typedef struct t_test
{
	int	test;
}	t_t;

void	*start_routine1(void *arg)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		//printf("thread 1 : %s\n", (char *)arg);
		i++;
	}
	pthread_exit(arg);
}
*/

#include <unistd.h>
#include <errno.h>
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t	cond = PTHREAD_COND_INITIALIZER;

void    *start_routine1(void *arg)
{
	int	i;
	char	*p = "Hello sir!\n";

	i = 0;
	//pthread_mutex_lock(&mutex);
	pthread_cond_wait(&cond, &mutex);
	while (i < 11)
	{
		fprintf(stderr ,"%c", p[i]);
		usleep(100000);
		i++;
	}
	printf("finish\n");
	//pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}
void    *start_routine2(void *arg)
{
	int	i;
	char	*p = "Goodbye sir!\n";

	i = 0;
	usleep(50);
	//pthread_mutex_lock(&mutex);
	//pthread_cond_wait(&cond, &mutex);
	while (i < 13)
	{
		fprintf(stderr, "%c", p[i]);
		usleep(100000);
		i++;
	}
	printf("finish\n");
	pthread_cond_signal(&cond);
	//pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&thread1, NULL, start_routine1, NULL);
	pthread_create(&thread2, NULL, start_routine2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);

}
