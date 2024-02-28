/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:44:31 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/02 17:07:49 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	long	b;

	i = 0;
	a = 1;
	b = 0;
	if (str[i] != '\0')
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				a = -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			b = b * 10 + str[i++] - 48;
			if (b < 0 && a == 1)
				return (-1);
			if (b < 0 && a == -1)
				return (0);
		}
		return (b * a);
	}
	return (0);
}
