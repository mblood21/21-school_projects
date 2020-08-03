/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:43:45 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 19:20:17 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_conv(char c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') ||
		(c == 'i') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

static void	ft_find_prec(t_args *parsed, const char *format, va_list argc)
{
	int	prec;

	if (*format == '*')
	{
		prec = va_arg(argc, int);
		format++;
	}
	else if (ft_isdigit(*format) == 1)
	{
		prec = ft_atoi(format);
		while (ft_isdigit(*format) == 1)
			format++;
	}
	else
		prec = 0;
	if (prec >= 0)
		parsed->prec = prec;
	parsed->frmt = format;
}

static void	ft_find_width_and_prec(t_args *parsed,
								const char *format, int flag_w, va_list argc)
{
	if (*format == '*')
	{
		parsed->width = va_arg(argc, int);
		if (parsed->width > 0 && flag_w < 0)
			parsed->width *= flag_w;
		if (*(format - 1) == '0')
			parsed->prec = parsed->width;
		format++;
	}
	else if (ft_isdigit(*format) == 1)
	{
		parsed->width = ft_atoi(format) * flag_w;
		if (*(format - 1) == '0')
			parsed->prec = parsed->width;
		while (ft_isdigit(*format) == 1)
			format++;
	}
	if (*format == '.')
	{
		format++;
		ft_find_prec(parsed, format, argc);
		format = parsed->frmt;
	}
	parsed->frmt = format;
}

static int	ft_find_to_conversions(const char *format,
						va_list argc, t_args *parsed)
{
	int i;

	i = 0;
	if (ft_is_conv(*format))
	{
		i = ft_new_conversions(format, argc, parsed->width,
									parsed->prec);
		format++;
	}
	if (*format == '%' && *(format - 1) == '%' && *(format + 1) != '%')
	{
		ft_putchar_fd(*(format++), 1);
		while (*format && *format != '%')
			ft_putchar_fd(*format++, 1);
	}
	parsed->frmt = format;
	return (i);
}

void		ft_parser(t_args *parsed, const char *format, va_list argc)
{
	int	flag_w;
	int i;

	flag_w = 1;
	while (*format == ' ')
	{
		parsed->res++;
		ft_putchar_fd(*format, 1);
		format++;
	}
	while (*format == '0')
		format++;
	while (*format == '-')
	{
		flag_w = -1;
		format++;
	}
	ft_find_width_and_prec(parsed, format, flag_w, argc);
	if ((i = ft_find_to_conversions(parsed->frmt, argc, parsed)) > 0)
		parsed->res += i;
	else
		parsed->res += 0;
	format = parsed->frmt;
}
