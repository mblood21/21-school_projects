/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:24:05 by mblood            #+#    #+#             */
/*   Updated: 2020/05/21 16:58:58 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t n)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	if (lit[0] == '\0')
		return ((char *)&big[pos]);
	while (big[pos] && pos < n)
	{
		i = 0;
		while (big[pos + i] == lit[i] && pos + i < n && lit[i] != '\0')
			i++;
		if (lit[i] == '\0')
			return ((char *)&big[pos]);
		pos++;
	}
	return (0);
}
