/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:51:45 by gdumorti          #+#    #+#             */
/*   Updated: 2024/02/19 16:51:47 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_philo_created(t_table *table)
{
	while (!(get_bool(&table->table_mutex, &table->all_thread_rdy)))
		;
}

/*

Monitor busy waits until all thread are not running

*/
bool	all_threads_running(t_mutex *mutex, long *threads, long philo_nbr)
{
	bool	ret;

	ret = false;
	handle_secure_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	handle_secure_mutex(mutex, UNLOCK);
	return (ret);
}

/*
increase threads running
to synchro with the monitor
*/

void	increase_long(t_mutex *mutex, long *value)
{
	handle_secure_mutex(mutex, LOCK);
	(*value)++;
	handle_secure_mutex(mutex, UNLOCK);
}

/*
make the system fair
*/
void	unsynchronize_philos(t_philo *philo)
{
	if (philo->table->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(30000, philo->table);
	}
	else
	{
		if (philo->id % 2 != 0)
			thinking(philo, true);
	}
}