/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:58:17 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/24 15:58:18 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void fork_init(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	//deadlock
	philo->first_fork = &forks[(position + 1) % philo_nbr];
	philo->second_fork = &forks[position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = 0;
	while (i++ < table < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;

		fork_init(philo, table->forks, i);

	}
}

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->all_thread_rdy = false;
	table->philos = malloc_secure(table->philo_nbr * sizeof(t_philo));
	handle_secure_mutex(&table->table_mutex, INIT);
	handle_secure_mutex(&table->write_mutex, INIT);
	table->forks = malloc_secure(table->philo_nbr * sizeof(t_fork));
	while (i++ < table->philo_nbr)
	{
		handle_secure_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}