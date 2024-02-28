/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:19 by gdumorti          #+#    #+#             */
/*   Updated: 2024/02/19 17:59:20 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo, long passed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf(WHI"%6ld"DEF" %d has taken the 1° fork 🍽""\t\t\tn°"BLUE"[🍴 %d 🍴]\n"DEF, passed, philo->id, philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf(WHI"%6ld"DEF" %d has taken the 2° fork 🍽""\t\t\tn°"BLUE"[🍴 %d 🍴]\n"DEF, passed, philo->id,
			philo->second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf(WHI"%6ld"CYA" %d is eating 🍝""\t\t\t"YEL"[🍝 %ld 🍝]\n"DEF, passed, philo->id, philo->meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf(WHI"%6ld"DEF" %d is sleeping 😴\n", passed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf(WHI"%6ld"DEF" %d is thinking 🤔\n", passed, philo->id);
	else if (DIED == status)
		printf(RED"\t\t💀💀💀 %6ld %d died   💀💀💀\n"DEF, passed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	passed;

	passed == get_time(MILLISECONDS) - philo->table->start_simulation;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	handle_secure_mutex(&philo->table->write_mutex, LOCK);

	if (debug)
		write_status_debug(status, philo, passed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status) && !simulation_finished(philo->table))	//inverser egalite si ca marche
			printf(WHI"%-6ld"DEF"	%d has taken a fork\n", passed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf(WHI"%-6ld"CYA"	%d is eating\n"DEF, passed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf(WHI"%-6ld"DEF"	%d is sleeping\n", passed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf(WHI"%-6ld"DEF"	%d is thinking\n", passed, philo->id);
		else if (DIED == status)
			printf(RED"%-6ld	%d died\n"DEF, passed, philo->id);
	}

	handle_secure_mutex(&philo->table->write_mutex, UNLOCK);
}
