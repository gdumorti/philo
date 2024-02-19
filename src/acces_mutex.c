/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acces_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:12:58 by gdumorti          #+#    #+#             */
/*   Updated: 2024/02/19 16:13:00 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*

- module containing setters_getters

*/

// bool
void	set_bool(t_mutex *mutex, bool *dest, bool value)
{
	handle_secure_mutex(mutex, LOCK);
	*dest = value;
	handle_secure_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *value)
{
	bool	ret;

	handle_secure_mutex(mutex, LOCK);
	//reading
	ret = *value;
	handle_secure_mutex(mutex, UNLOCK);
	return (ret);
}

// long
long	get_long(t_mutex *mutex, long *value)
{
	long	ret;

	handle_secure_mutex(mutex, LOCK);
	ret = *value;
	handle_secure_mutex(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mutex *mutex, long *dest, long *value)
{
	handle_secure_mutex(mutex, LOCK);
	*dest = value;
	handle_secure_mutex(mutex, UNLOCK);
}
/*
redundant ?
*/
bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
