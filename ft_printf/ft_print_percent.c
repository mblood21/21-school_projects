/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:15:19 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 17:35:01 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_percent(int width, int prec)
{
	int		w;
	int		res;

	w = ft_abs(width);
	res = (w > 0) ? w : 1;
	if (prec < w || w < prec)
		prec = 0;
	w = (prec > 0) ? w -= prec : w;
	if (width < 0)
	{
		while (prec-- - 1 > 0)
			ft_putchar_fd('0', 1);
		ft_putchar_fd('%', 1);
		while (--w > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--w > 0)
			ft_putchar_fd(' ', 1);
		while (prec-- - 1 > 0)
			ft_putchar_fd('0', 1);
		ft_putchar_fd('%', 1);
	}
	return (res);
}
