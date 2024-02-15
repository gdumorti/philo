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