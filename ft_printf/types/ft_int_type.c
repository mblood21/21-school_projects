/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:33:54 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 19:55:17 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_int_type_out_width_is_neg(int nb, int w, int len, int nb_len)
{
	if (nb < 0)
		ft_putchar_fd('-', 1);
	while (len-- - nb_len > 0)
		ft_putchar_fd('0', 1);
	if (nb > -2147483648)
	{
		if (nb_len != 0)
			ft_putnbr_fd(ft_abs(nb), 1);
	}
	else
		ft_putstr_fd("2147483648", 1);
	while (w-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_int_type_out_width_is_pos(int nb, int w, int len, int nb_len)
{
	while (w-- > 0)
		ft_putchar_fd(' ', 1);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
	}
	while (len-- - nb_len > 0)
		ft_putchar_fd('0', 1);
	if (nb > -2147483648)
	{
		if (nb_len != 0)
			ft_putnbr_fd(ft_abs(nb), 1);
	}
	else
		ft_putstr_fd("2147483648", 1);
}

static int	ft_int_type_find_len(int prec, int nb_len)
{
	if (prec >= 0)
		return ((prec <= nb_len) ? nb_len : prec);
	else
		return (nb_len);
}

static int	ft_int_type_find_res(int nb, int w, int len)
{
	if (w > 0)
		return ((nb < 0) ? len + w + 1 : len + w);
	else
		return ((nb < 0) ? len + 1 : len);
}

int			ft_int_type(va_list argc, int width, int prec)
{
	int		w;
	int		nb;
	int		nb_len;
	int		len;

	nb = va_arg(argc, int);
	nb_len = ft_nblen(ft_abs(nb));
	if (prec == 0 && nb == 0)
		nb_len = 0;
	len = ft_int_type_find_len(prec, nb_len);
	w = ft_abs(width) - len;
	if (w > 0 && nb < 0)
		w--;
	else if (w == 0 && nb < 0 && nb_len != len)
		len--;
	if (width < 0)
		ft_int_type_out_width_is_neg(nb, w, len, nb_len);
	else if (width >= 0)
		ft_int_type_out_width_is_pos(nb, w, len, nb_len);
	return (ft_int_type_find_res(nb, w, len));
}
