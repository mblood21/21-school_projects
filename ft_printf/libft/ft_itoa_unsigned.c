/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:29:45 by mblood            #+#    #+#             */
/*   Updated: 2020/07/24 23:26:53 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*str_fill_unsigned(char *str, int nbnum, size_t n)
{
	size_t	n2;
	int		finish;

	n2 = n;
	finish = 1;
	str[nbnum] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0 && nbnum > 0)
	{
		n2 = n % 10;
		n /= 10;
		str[nbnum - 1] = finish * n2 + '0';
		nbnum--;
	}
	return (str);
}

char		*ft_itoa_unsigned(size_t n)
{
	char	*str;
	int		nbnum;
	size_t	n2;

	n2 = n;
	nbnum = 0;
	if (n == 0)
		nbnum = 1;
	while (n2 > 0)
	{
		n2 /= 10;
		nbnum++;
	}
	if (!(str = (char *)malloc(sizeof(char) * nbnum + 1)))
		return (0);
	str = str_fill_unsigned(str, nbnum, n);
	return (str);
}
