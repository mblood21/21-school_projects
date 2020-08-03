/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:45:29 by mblood            #+#    #+#             */
/*   Updated: 2020/05/20 20:13:06 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *fordel;

	if (!del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			fordel = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = fordel;
		}
	}
}
