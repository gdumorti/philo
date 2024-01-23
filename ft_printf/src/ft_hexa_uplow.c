/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_uplow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:10:29 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/22 15:37:41 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_put_str(char *str, int i, char conv, int x)
{
	if (conv == 'x')
		str[i] = (x - 10) + 'a';
	else if (conv == 'X')
		str[i] = (x - 10) + 'A';
	return (str);
}

int	ft_putchar_hexa(char *str, int i)
{
	return (write(1, str, i));
}

int	ft_intlen(unsigned int a)
{
	int	i;

	if (a == 0)
		return (1);
	i = 0;
	while (a)
	{
		a /= 16;
		i++;
	}
	return (i);
}

int	ft_convert_hexa(unsigned int a, char conv)
{
	int		i;
	int		value;
	int		x;
	char	*str;

	i = ft_intlen(a);
	value = i;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (-1);
	str[i--] = '\0';
	while (a != 0)
	{
		x = a % 16;
		a = a / 16;
		if (x <= 9)
			str[i] = x + '0';
		else
			str = ft_put_str(str, i, conv, x);
		i--;
	}
	value = ft_putchar_hexa(str, value);
	free(str);
	return (value);
}

int	ft_hexa_uplow(unsigned int a, char conv)
{
	int				value;

	value = 0;
	if (a == 0)
		return (write(1, "0", 1));
	else
		value = ft_convert_hexa(a, conv);
	return (value);
}
