/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:52:25 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/02 17:08:52 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size_elem)
{
	void		*str;

	str = (void *)malloc(n_elem * size_elem);
	if (!str)
		return (NULL);
	ft_bzero(str, n_elem * size_elem);
	return (str);
}
