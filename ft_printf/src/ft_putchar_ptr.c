/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:44:31 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/22 15:38:53 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_hexa_p(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_intlen_bis(uintptr_t address)
{
	int	i;

	if (address == 0)
		return (1);
	i = 0;
	while (address)
	{
		address /= 16;
		i++;
	}
	return (i);
}

int	ft_hexa_ptr(uintptr_t address)
{
	int		i;
	int		value;
	int		x;
	char	*str;

	i = ft_intlen_bis(address);
	x = 0;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (-1);
	str[i--] = '\0';
	while (address != 0)
	{
		x = address % 16;
		address = address / 16;
		if (x <= 9)
			str[i] = x + '0';
		else
			str[i] = (x - 10) + 'a';
		i--;
	}
	value = ft_putchar_hexa_p(str);
	free(str);
	return (value);
}

int	ft_putchar_ptr(void *ptr)
{
	int	value;
	int	old_value;

	value = write(1, "0x", 2);
	if (value < 0)
		return (-1);
	old_value = value;
	if (ptr == 0)
		value += write(1, "0", 1);
	else
		value += ft_hexa_ptr((uintptr_t)ptr);
	if (value < old_value)
		return (-1);
	return (value);
}
