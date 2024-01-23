/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:31:57 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/16 17:10:56 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_putchar(int a)
{
	return (write(1, &a, 1));
}

int	ft_conv(va_list args, char conv)
{
	int	value;

	value = -1;
	if (conv == 'c')
		value = ft_putchar(va_arg(args, int));
	else if (conv == 's')
		value = ft_print_string(va_arg(args, char *));
	else if (conv == 'p')
		value = ft_putchar_ptr(va_arg(args, void *));
	else if (conv == 'd' || conv == 'i')
		value = ft_digit(va_arg(args, int));
	else if (conv == 'u')
		value = ft_unsigned(va_arg(args, unsigned int));
	else if (conv == 'x' || conv == 'X')
		value = ft_hexa_uplow(va_arg(args, unsigned int), conv);
	else if (conv == '%')
		value = ft_percent();
	return (value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		value;
	int		old_value;

	i = 0;
	value = 0;
	va_start(args, str);
	while (str[i])
	{
		old_value = value;
		if (str[i] == '%')
			value += ft_conv(args, str[++i]);
		else
			value += ft_putchar(str[i]);
		if (value < old_value)
			return (-1);
		i++;
	}
	va_end(args);
	return (value);
}
