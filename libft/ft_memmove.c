/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:00:16 by mblood            #+#    #+#             */
/*   Updated: 2020/05/23 15:34:50 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!src || !dest)
		return (0);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d)
		while (i++ < n)
			d[n - i] = s[n - i];
	else
		while (i < n)
		{
			*d++ = *s++;
			i++;
		}
	return (dest);
}
