/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:43:21 by mblood            #+#    #+#             */
/*   Updated: 2020/07/26 15:15:14 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_char_type(va_list argc, int width)
{
	char	c;
	int		w;
	int		res;

	w = ft_abs(width);
	c = (unsigned char)va_arg(argc, int);
	res = (w > 0) ? w : 1;
	if (width)
	{
		if (width < 0)
		{
			ft_putchar_fd(c, 1);
			while (--w > 0)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (--w > 0)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(c, 1);
		}
	}
	else
		ft_putchar_fd(c, 1);
	return (res);
}
