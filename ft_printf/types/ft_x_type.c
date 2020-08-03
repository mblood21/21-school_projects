/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:23:01 by mblood            #+#    #+#             */
/*   Updated: 2020/07/26 18:32:02 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_x_type_out_width_is_pos(int len, int nb_len, char *str_nb, int w)
{
	while (w-- > 0)
		ft_putchar_fd(' ', 1);
	while (len-- - nb_len > 0)
		ft_putchar_fd('0', 1);
	while (nb_len-- > 0)
		ft_putchar_fd(*(str_nb++), 1);
}

static void	ft_x_type_out_width_is_neg(int len, int nb_len, char *str_nb, int w)
{
	while (len-- - nb_len > 0)
		ft_putchar_fd('0', 1);
	while (nb_len-- > 0)
		ft_putchar_fd(*(str_nb++), 1);
	while (w-- > 0)
		ft_putchar_fd(' ', 1);
}

static int	ft_x_type_find_len(int prec, int nb_len)
{
	if (prec >= 0)
		return ((prec <= nb_len) ? nb_len : prec);
	else
		return (nb_len);
}

int			ft_x_type(va_list argc, int width, int prec, int flag_x)
{
	char			*str_nb;
	int				len;
	int				nb_len;
	int				w;
	unsigned int	nb;

	w = ft_abs(width);
	nb = va_arg(argc, unsigned int);
	str_nb = ft_hexadecimal_notation(nb, flag_x);
	if (prec == 0 && nb == 0)
		nb_len = 0;
	else
		nb_len = ft_strlen(str_nb);
	len = ft_x_type_find_len(prec, nb_len);
	w -= len;
	if (width < 0)
	{
		ft_x_type_out_width_is_neg(len, nb_len, str_nb, w);
	}
	else
		ft_x_type_out_width_is_pos(len, nb_len, str_nb, w);
	free(str_nb);
	return ((w > 0) ? w + len : len);
}
