/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:44:31 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/02 17:07:49 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_lst;
	t_list	*ptr_new;

	if (!lst || !f || !del)
		return (NULL);
	ptr_lst = ft_lstnew(f(lst->content));
	if (!(ptr_lst))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		ptr_new = ft_lstnew(f(lst->content));
		if (!(ptr_new))
		{
			ft_lstclear(&ptr_new, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr_lst, ptr_new);
		lst = lst->next;
	}
	return (ptr_lst);
}
