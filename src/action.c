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

*/
void	thinking(t_philo *philo, bool pre_simulation)
{
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;

	if (!pre_simulation)
		write_status(THINKING, philo, DEBUG_MODE);
	//if the system is even we don't care, system already fair
	if (philo->table->philo_nbr % 2 == 0)
		return ;
	//if nt even, not always fair
	time_to_eat = philo->table->time_to_eat;
	time_to_sleep = philo->table->time_to_sleep;
	time_to_think = (time_to_eat * 2) - time_to_sleep; //available time to think 
	if (time_to_think < 0)
		time_to_think = 0;
	//precise control i wanna make on philo
	precise_usleep(time_to_think * 0.42, philo->table);
}

/*
same algo but...

- fake to lock the fork
- sleep until the monitor will bust it
*/
void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_philo_created(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!(simulation_finished(philo->table)))
		usleep(240);
	return (NULL);
	
}

/*
- grab forks (first and second)
- eating: write eat, update last meal, update meals counter
- release de forks
*/

static void	eat(t_philo *philo)
{
	static int	meals_limit;

	meals_limit = philo->table->nbr_limit_meals;
	//1
	handle_secure_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	handle_secure_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	
	//2
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	philo->meals_counter++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (meals_limit > 0 && philo->meals_counter == meals_limit)
		set_bool(&philo->philo_mutex, &philo->full, true);
	
	//3
	handle_secure_mutex(&philo->first_fork->fork, UNLOCK);
	handle_secure_mutex(&philo->second_fork->fork, UNLOCK);
}

/*

- Wait all philos create
- endless loop philo


*/

void	*meal_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;

	wait_philo_created(philo->table);
	// set time last meal
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECONDS));
	//synchro with monitor
	//increase a table variable counter, with all threads running
	increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
	unsynchronize_philos(philo);
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
		thinking(philo, false);

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
		handle_secure_thread(&table->philos[0].thread_id, lone_philo, &table->philos[0], CREATE);// later0
	else
	{	
		while (i < table->philo_nbr)
		{
			handle_secure_thread(&table->philos[i].thread_id, meal_simulation, &table->philos[i], CREATE);
			i++;
		}
	}
	//monitor thread
	handle_secure_thread(&table->monitor, monitor_meal, table, CREATE);
	//start
	table->start_simulation = get_time(MILLISECONDS);

	// all threads are ready
	set_bool(&table->table_mutex, &table->all_thread_rdy, true);
	// wait for everyone
	i = 0;
	while (i < table->philo_nbr)
	{
		handle_secure_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	// if we managed to reach this line, philos are FULL !
	set_bool(&table->table_mutex, &table->end_simulation, true);

	handle_secure_thread(&table->monitor, NULL, NULL, JOIN);



}
