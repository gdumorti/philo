/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:31:59 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/03 15:36:29 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len < 0)
		len = ft_strlen(str1);
	if ((str2 == NULL || str1 == NULL) && len == 0)
		return ((char *)str1);
	if (str2[j] == '\0')
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		while (str1[i + j] == str2[j] && str1[i + j] \
				&& str2[j] && (i + j) < len)
			j++;
		if (j == ft_strlen(str2))
			return ((char *)str1 + i);
		if (str1[i + j] != str2[j])
			j = 0;
		i++;
	}
	return (NULL);
}
