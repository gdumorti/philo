/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:46:46 by gdumorti          #+#    #+#             */
/*   Updated: 2024/02/19 15:46:47 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*

- Wait all philos create
- endless loop philo


*/

void	*meal_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo	*)data;

	wait_philo_created(philo->table);

	// set last meal time
	while (!(simulation_finished(philo->table)))
	{
		// 1) am i full?
		if (philo->full) // thread safe ?
			break ;
		// 2) eat
		eat(philo);
		// 3) sleep -> write_status & precise usleep
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);

		// 4) thinking

	}



	return (NULL);
}


/*

input: ./philo 5 800 200 200 [5]

- if no meals, STOP [0]
if 1 philo ad hoc
- create threads
- create monitor thread
- synchro begin
- JOIN everyone

*/

void	meal_start(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		;// later0
	else
	{	
		while (i < table->philo_nbr)
		{
			handle_secure_thread(&table->philos[i].thread_id, meal_simulation, &table->philos[i], CREATE);
			i++;
		}
	}
	//start
	table->start_simulation = get_time(MILLISECONDS);

	// all threads are ready
	set_bool(&table->table_mutex, table->all_thread_rdy, true);
	// wait for everyone
	i = 0;
	while (i < table->philo_nbr)
	{
		handle_secure_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	// if we managed to reach this line, philos are FULL !




}