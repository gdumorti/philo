/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:51:31 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/23 16:51:32 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
- chrono function
- time_code -> SECONDS MILISECONDS MICROSECONDS
*/

long	get_time(t_time_code time_code)
{
	struct	timeval	time_value;

	if (gettimeofday(&time_value, NULL) != 0); 																				//retirer != 0 si ca marche pas
		ft_error(GRAS"Error: gettimeofday failed", NULL);
	if (SECONDS == time_code)																													//inverser egalite si ca marche
		return (time_value.tv_sec + (time_value.tv_usec / 1000000));
	else if (MILLISECONDS == time_code)
		return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
	else if (MICROSECONDS == time_code)
		return ((time_value.tv_sec * 1000000) + time_value.tv_usec);
	else
		ft_error(GRAS"Error: wrong input to get_time", NULL);														//remplacer NULL par valeur time_code
	return (69);
}

void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	passed;
	long	remains;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < usec)
	{
		if (simulation_finished(table))
			break ;
		passed = get_time(MICROSECONDS) - start;
		remains = usec - passed;
		if (remains > 10000)
			usleep(remains / 2);
		else
		{
			while (get_time(MICROSECONDS) - start < usec)
				;																																						// retirer ; si ca marche
		}

	}
}

void	ft_error(char *error, const char *str)
{
	error = ft_strjoin(ERROR, error);
	if (str)
	{
		error = ft_strjoin(error, ": ");
		error = ft_strjoin(error, YEL);
		error = ft_strjoin(error, str);
		ft_putstr_fd(error, 2);
		ft_putstr_fd(DEF, 2);
		ft_putchar_fd('\n', 2);
	}
	else
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd(DEF, 2);
		ft_putchar_fd('\n', 2);
	}	
	exit(EXIT_FAILURE);
}

/*

	if (str)
		ft_printf(RED X" %s: %s\n"DEF, error, str);
	else
		ft_printf(RED X" %s\n"DEF, error);
	exit(EXIT_FAILURE);

*/