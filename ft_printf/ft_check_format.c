/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:06:41 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 16:09:58 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_parsed(t_args *parsed)
{
	parsed->width = 0;
	parsed->prec = -1;
	parsed->frmt = NULL;
}

int			ft_check_format(const char *format, va_list argc)
{
	t_args	parsed;

	parsed.res = 0;
	while (*format)
	{
		while (*format && *format != '%')
		{
			++parsed.res;
			ft_putchar_fd(*format++, 1);
		}
		if (*format == '%')
		{
			format++;
			ft_init_parsed(&parsed);
			ft_parser(&parsed, format, argc);
			format = parsed.frmt;
		}
	}
	return (parsed.res);
}
