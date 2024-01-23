/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:19:58 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/23 17:19:59 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
./philo 5 800 200 200 [5]

1) actual numbers
2) not > INT_MAX
3) timestamps > 60ms
*/

/*static bool	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
}

static const char	*valid_input(const char *str)
{
	int					len;
	const char	*number;

	len = 0;
	while ()
}

static long	ft_atoi(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
}*/

long	ft_atol(const char *str)
{
	int	i;
	int sign;
	long num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (str[i - 1] == '-')
			return (-1);
		num = num * 10 + str[i++] - 48;
		if (num < 0 && sign == 1)
			return (-1);
		if (num < 0 && sign == -1)
			return (-1);
	}
	if (str[i] != '\0')
		return (ft_error(), 0);
	return (num);
}



void	parse_intput(t_table *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
}