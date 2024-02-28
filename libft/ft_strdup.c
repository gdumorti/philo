/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:01:35 by gdumorti          #+#    #+#             */
/*   Updated: 2023/04/24 17:19:41 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_clone;

	str_clone = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (str_clone == NULL)
		return (NULL);
	ft_memcpy(str_clone, str, (ft_strlen(str) + 1));
	return (str_clone);
}
