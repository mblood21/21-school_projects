/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:26:51 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 20:52:38 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	out_with_posw(int len, char *hex_p, int w, int prec)
{
	if (w == 0)
		prec -= 2;
	while (w-- - 2 > 0)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	while (prec-- - len > 0)
		ft_putchar_fd('0', 1);
	if (len > 0)
		ft_putstr_fd(hex_p, 1);
}

static void	out_with_negw(int len, char *hex_p, int w, int prec)
{
	if (w == 0)
		prec -= 2;
	ft_putstr_fd("0x", 1);
	while (prec-- - len > 0)
		ft_putchar_fd('0', 1);
	if (len > 0)
		ft_putstr_fd(hex_p, 1);
	while (w-- - 2 > 0)
		ft_putchar_fd(' ', 1);
}

static int	ft_find_res(size_t p, int len, int w, int prec)
{
	if (w > 0)
	{
		if (p == 0)
			if (len == 0)
				return (w);
			else
				return ((w < 2) ? len + 2 : w + len);
		else
			return (w + len);
	}
	else
	{
		if (p == 0)
			return ((len == 0) ? 2 : len + 2);
		else
			return ((prec > len) ? prec + 2 : len + 2);
	}
}

int			ft_pointer_type(va_list argc, int width, int prec)
{
	size_t	p;
	char	*hex_p;
	int		len;
	int		w;

	w = ft_abs(width);
	p = va_arg(argc, size_t);
	hex_p = ft_hexadecimal_notation(p, 32);
	if (p == 0 && prec == 0)
		len = 0;
	else
		len = ft_strlen(hex_p);
	w -= len;
	if (width > 0)
		out_with_posw(len, hex_p, w, prec);
	else
		out_with_negw(len, hex_p, w, prec);
	free(hex_p);
	return (ft_find_res(p, len, w, prec));
}
