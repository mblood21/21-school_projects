/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:10:10 by mblood            #+#    #+#             */
/*   Updated: 2020/06/21 18:57:56 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char		*ft_strchr(const char *str, int c)
{
	unsigned int i;

	i = 0;
	while (str[i] != c)
	{
		if (!str[i])
			return (0);
		i++;
	}
	return ((char *)&str[i]);
}

void		ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	if (!dst || !src)
		return ;
	i = -1;
	while (++i < (int)size && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
}
