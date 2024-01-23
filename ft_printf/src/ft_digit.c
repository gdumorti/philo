/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:03:55 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/16 16:47:04 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_digit(int a)
{
	int		len;
	char	*digit;

	digit = ft_itoa(a);
	if (!digit)
		return (-1);
	len = ft_print_string(digit);
	free(digit);
	return (len);
}
