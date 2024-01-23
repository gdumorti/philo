/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:10:16 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/02 17:21:31 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t b)
{
	size_t	i;
	size_t	n;
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (b == 0)
		return (srclen);
	destlen = ft_strlen(dest);
	n = destlen;
	i = 0;
	if (destlen > b)
		return (srclen + b);
	while ((destlen + i) < b && src[i] != '\0')
		dest[n++] = src[i++];
	if ((destlen + i) == b && destlen < b)
		dest[--n] = '\0';
	else
		dest[n] = '\0';
	return (srclen + destlen);
}
