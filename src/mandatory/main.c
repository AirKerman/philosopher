/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:56:50 by rkerman           #+#    #+#             */
/*   Updated: 2025/05/02 16:59:00 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>


typedef struct t_test
{
	int	test;
}	t_t;

int	main(int argc, char **argv)
{
	t_t						test;
	pthread_t				thread1;
	int						t1;

	t.test = 1;
	t1 = pthread_create(&thread1, NULL, start_routine, &test);

	return (0);

}
