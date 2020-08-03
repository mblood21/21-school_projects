/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:08:26 by mblood            #+#    #+#             */
/*   Updated: 2020/07/26 18:36:34 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_un_int_type_out_width_is_pos(int prec,
				int nb_len, int w, char *str_nb)
{
	while (w-- > 0)
		ft_putchar_fd(' ', 1);
	while (prec-- - nb_len > 0)
		ft_putchar_fd('0', 1);
	while (nb_len-- > 0)
		ft_putchar_fd(*(str_nb++), 1);
}

static void	ft_un_int_type_out_width_is_neg(int prec,
				int nb_len, int w, char *str_nb)
{
	while (prec-- - nb_len > 0)
		ft_putchar_fd('0', 1);
	while (nb_len-- > 0)
		ft_putchar_fd(*(str_nb++), 1);
	while (w-- > 0)
		ft_putchar_fd(' ', 1);
}

static int	ft_un_int_type_find_len(int prec, int nb_len)
{
	if (prec >= 0)
		return ((prec <= nb_len) ? nb_len : prec);
	else
		return (nb_len);
}

int			ft_unsigned_int_type(va_list argc, int width, int prec)
{
	int				w;
	unsigned int	nb;
	int				len;
	int				nb_len;
	char			*str_nb;

	w = ft_abs(width);
	nb = va_arg(argc, unsigned int);
	str_nb = ft_itoa_unsigned((size_t)nb);
	if (prec == 0 && nb == 0)
		nb_len = 0;
	else
		nb_len = ft_strlen(str_nb);
	len = ft_un_int_type_find_len(prec, nb_len);
	w -= len;
	if (width < 0)
		ft_un_int_type_out_width_is_neg(prec, nb_len, w, str_nb);
	else if (width >= 0)
		ft_un_int_type_out_width_is_pos(prec, nb_len, w, str_nb);
	free(str_nb);
	return ((w > 0) ? w + len : len);
}
