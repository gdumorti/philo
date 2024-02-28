/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:48:42 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/02 17:18:27 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t c)
{
	size_t			n;
	char			*a;
	const char		*b;

	if (!c || dest == src)
		return (dest);
	n = 0;
	a = (char *)dest + c;
	b = (const char *)src + c;
	if (dest <= src)
	{
		while (c--)
		{
			*((char *)dest + n) = *((const char *)src + n);
			n++;
		}
	}
	else
		while (c--)
			*--a = *--b;
	return (dest);
}
