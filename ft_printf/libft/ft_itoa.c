/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:28:43 by mblood            #+#    #+#             */
/*   Updated: 2020/07/17 22:36:52 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*str_fill(char *str, int nbnum, int n)
{
	int n2;
	int finish;

	n2 = n;
	finish = 1;
	str[nbnum] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		finish = -1;
	}
	if (n == 0)
		str[0] = '0';
	while ((n > 0 && nbnum > 0) || (n < 0 && nbnum > 1))
	{
		n2 = n % 10;
		n /= 10;
		str[nbnum - 1] = finish * n2 + '0';
		nbnum--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nbnum;
	int		n2;

	n2 = n;
	nbnum = 0;
	if (n == 0)
		nbnum = 1;
	while ((n > 0 && n2 > 0) || (n < 0 && n2 < 0))
	{
		n2 /= 10;
		nbnum++;
	}
	if (n < 0)
		nbnum++;
	if (!(str = (char *)malloc(sizeof(char) * nbnum + 1)))
		return (0);
	str = str_fill(str, nbnum, n);
	return (str);
}
