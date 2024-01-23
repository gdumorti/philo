/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:11:17 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/15 13:11:19 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"

int		ft_putchar(int a);
int		ft_conv(va_list args, const char conv);
int		ft_printf(const char *str, ...);
int		ft_print_string(char *str);
int		ft_digit(int a);
int		ft_unsigned(unsigned int a);
int		ft_hexa_uplow(unsigned int a, char conv);
int		ft_putchar_ptr(void *ptr);
int		ft_intlen(unsigned int a);
char	*ft_put_str(char *str, int i, char conv, int x);
int		ft_putchar_hexa(char *str, int i);

#endif