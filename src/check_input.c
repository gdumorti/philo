/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:52:56 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/24 15:52:58 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*		  		 ms		 ms		 ms
./philo 5		800		200		200		[5]

1) actual numbers
2) not > INT_MAX
3) timestamps > 60ms
USLEEP -> ms
*/

long	ft_atol(const char *str)
{
	int	i;
	long num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		ft_error(GRAS"Error: Please use positive value", str);
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + str[i++] - 48;
		if (num > INT_MAX)	//eviter overflow
			ft_error(GRAS"Error: value is too big", str);
		if (num < 0)			//overflow
			ft_error(GRAS"Error: value is too big", str);
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i])
		ft_error(GRAS"Error: not valid integer", str);
	return (num);
}


void	check_input(t_table *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000 || 
	table->time_to_sleep < 60000)
		ft_error(GRAS"Error: use bigger timestamps (>60ms)", NULL);
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;

	ft_putstr_fd("OK\n", 1);
	//ft_printf(GRAS GREEN"OK\n");

}
