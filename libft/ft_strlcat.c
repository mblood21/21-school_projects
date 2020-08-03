/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:55:45 by mblood            #+#    #+#             */
/*   Updated: 2020/05/20 20:32:55 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	count;

	if (dst == NULL || src == NULL)
		return (0);
	count = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		srclen += size;
	else
		srclen += dstlen;
	if (size != 0)
	{
		while (src[count] != '\0' && dstlen < size - 1)
			dst[dstlen++] = src[count++];
		dst[dstlen] = '\0';
	}
	return (srclen);
}
