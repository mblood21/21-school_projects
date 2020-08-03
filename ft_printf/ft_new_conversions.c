/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:51:12 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 14:42:00 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_new_conversions(const char *format, va_list argc,
								int width, int prec)
{
	int flag_x;

	flag_x = 0;
	if (*format == 's')
		return (ft_string_type(argc, width, prec));
	if (*format == 'd' || *format == 'i')
		return (ft_int_type(argc, width, prec));
	if (*format == 'c')
		return (ft_char_type(argc, width));
	if (*format == 'p')
		return (ft_pointer_type(argc, width, prec));
	if (*format == 'x' || *format == 'X')
	{
		if (*format == 'x')
			flag_x = 32;
		return (ft_x_type(argc, width, prec, flag_x));
	}
	if (*format == 'u')
		return (ft_unsigned_int_type(argc, width, prec));
	if (*format == '%')
		return (ft_print_percent(width, prec));
	return (0);
}
