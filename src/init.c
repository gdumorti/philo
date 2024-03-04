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
	printf("OK5\n");
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		printf("OK6.0.1 --> %ld et %d\n", table->philo_nbr, i);

		//philo = malloc(sizeof (t_philo)); //PAS NET TOUT CA
		philo->id = i + 1; //GROS PROB ICI SEG FAULT!!! PROB D'ALLOC MEM
		printf("OK6.0.2\n");
		
		philo->full = false;
		printf("OK6.0.3\n");
		
		philo->meals_counter = 0;
		philo->table = table;
		printf("OK6.1.%d\n", i + 1);
		
		handle_secure_mutex(&philo->philo_mutex, INIT);
		printf(GREEN"OK6.2.%d\n"DEF, i + 1);

		fork_init(philo, table->forks, i);
		i++;
	}
	printf("OK6.3\n");
}

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->all_thread_rdy = false;
	table->threads_running_nbr = 0;
	printf("philo_nbr = %ld\n", table->philo_nbr);
	table->philos = malloc_secure(table->philo_nbr * sizeof(t_philo));
	table->forks = malloc_secure(table->philo_nbr * sizeof(t_fork));
	handle_secure_mutex(&table->table_mutex, INIT);
	handle_secure_mutex(&table->write_mutex, INIT);
	while (i < table->philo_nbr)
	{
		handle_secure_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
	printf("OK4\n");
	philo_init(table);
}
