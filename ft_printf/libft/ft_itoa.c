/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:36:32 by gdumorti          #+#    #+#             */
/*   Updated: 2023/04/28 16:18:21 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_malsize(long long int nl)
{
	int	i;

	i = 1;
	if (nl < 0)
		nl = nl * -1;
	while (nl >= 10)
	{
		nl = nl / 10;
		i++;
	}
	return (i);
}

static char	*ft_n_to_char(char *str, long long int nl, int len_str)
{
	int	start;

	start = 0;
	if (nl < 0)
	{
		nl = nl * -1;
		start = 1;
		str[0] = '-';
	}
	str[len_str] = '\0';
	len_str--;
	while (len_str >= start)
	{
		str[len_str] = nl % 10 + 48;
		nl = nl / 10;
		len_str--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char				*str;
	int					len_str;
	long long int		nl;

	nl = n;
	len_str = ft_get_malsize(nl);
	if (nl < 0)
		len_str = len_str + 1;
	str = (char *)malloc((len_str + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_n_to_char(str, nl, len_str);
	return (str);
}
