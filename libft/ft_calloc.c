/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:30:21 by mblood            #+#    #+#             */
/*   Updated: 2020/05/20 19:41:05 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*space;
	size_t	len;

	len = nmemb * size;
	if (!(space = (char *)malloc(len)))
		return (0);
	ft_bzero(space, len);
	return (space);
}
