/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:12:36 by mblood            #+#    #+#             */
/*   Updated: 2020/05/17 23:34:29 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*newlist;

	list = NULL;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		if (!(newlist = ft_lstnew((*f)(lst->content))))
		{
			while (list)
			{
				newlist = list->next;
				(*del)(list->content);
				free(list);
				list = newlist;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&list, newlist);
		lst = lst->next;
	}
	return (list);
}
