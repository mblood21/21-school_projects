/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_notation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:28:28 by mblood            #+#    #+#             */
/*   Updated: 2020/07/28 21:51:14 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hexadecimal_notation(size_t nb, int flag)
{
	size_t	x;
	int		len;
	char	*arr;

	x = nb;
	len = 0;
	while (x >= 16)
	{
		len++;
		x /= 16;
	}
	if ((x / 16) % 16 == x / 16)
		len++;
	arr = (char *)malloc(sizeof(char) * len + 1);
	arr[len] = '\0';
	while (--len >= 0)
	{
		arr[len] = (nb % 16 < 10) ? nb % 16 + '0' :
		(nb % 16 - 10) + ('A' + flag);
		nb /= 16;
	}
	return (arr);
}
