/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:11:29 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/16 17:18:08 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_get_num_len(unsigned int a)
{
	int	len;

	len = 0;
	while (a != 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int a)
{
	int		len;
	int		len_tab;
	char	*udigit;

	len = ft_get_num_len(a);
	len_tab = len - 1;
	udigit = (char *)malloc((len + 1) * sizeof(char));
	if (!udigit)
		return (NULL);
	udigit[len] = '\0';
	while (a != 0)
	{
		udigit[len_tab] = a % 10 + '0';
		a = a / 10;
		len_tab--;
	}
	return (udigit);
}

int	ft_unsigned(unsigned int a)
{
	int		value;
	char	*udigit;

	if (a == 0)
		return (write(1, "0", 1));
	else
	{
		udigit = ft_unsigned_itoa(a);
		if (!udigit)
			return (-1);
		value = ft_print_string(udigit);
		free(udigit);
	}
	return (value);
}
