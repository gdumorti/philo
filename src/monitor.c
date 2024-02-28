/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:52:50 by gdumorti          #+#    #+#             */
/*   Updated: 2024/02/20 18:52:52 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
                 time_die
- last_meal____________________last_meal
- maybe philo is full
*/

static  bool philo_died(t_philo *philo)
{
    long    passed;
    long    time_to_die;

    if (get_bool(&philo->philo_mutex, &philo->full))
        return (false);
    passed = get_time(MILLISECONDS) - get_long(&philo->philo_mutex, &philo->last_meal_time);
    //convert back to milliseconds
    time_to_die = philo->table->time_to_die / 1000;

    if (passed > time_to_die)
        return (true);
    return (false);
}

void    *monitor_meal(void *data)
{
    int i;

    t_table *table;

    table = (t_table *)data;

    //make sure all philo running
    while (!all_threads_running(&table->table_mutex, &table->threads_running_nbr, table->philo_nbr))
       ;
    while (!simulation_finished(table))
    {
        i = 0;
        while (i < table->philo_nbr && !simulation_finished(table))
        {
            if (philo_died(table->philos + i))
            {
                set_bool(&table->table_mutex, &table->end_simulation, true);
                write_status(DIED, table->philos + i, DEBUG_MODE);
            }
            i++;
        }
    }
    return (NULL);

}