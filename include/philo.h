/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:43:00 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/23 15:43:01 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

typedef pthread_mutex_t t_mutex;

/*----- FORK -----*/

typedef struct s_fork
{
	t_mutex fork;
	int			fork_id;
}							t_fork;


/*----- PHILO -----*/
// ./philo 5 800 200 200 [5]

typedef struct s_philo
{
	int	id;
	long meals_counter;
	bool full;
	long last_meal_time; // time passed from last meal
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id;

}			t_philo;

/*----- TABLE -----*/
// ./philo 5 800 200 200 [5]

typedef struct s_table
{
	long philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals; // [5] FLAG if -1
	long	start_simulation;
	bool	end_simulation; // a philo dies or all philo full
	t_fork	*forks; // array forks
	t_philo	*philos; // array philosophers
}							t_table;


#endif