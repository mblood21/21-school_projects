/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:44:43 by mblood            #+#    #+#             */
/*   Updated: 2020/07/26 15:17:57 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_strlcpy_ch(char *dst, const char *src, size_t n)
{
	if (!dst || !src)
		return ;
	if (n != 0)
	{
		while (*src && n-- > 0)
			*dst++ = *src++;
	}
}