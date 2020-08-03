/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:48:19 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 20:52:57 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_string_type_out(char *str_f, int width, int len, int w)
{
	if (width < 0)
	{
		while (len-- > 0)
		{
			ft_putchar_fd(*str_f, 1);
			str_f++;
		}
		while (w-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (w-- > 0)
			ft_putchar_fd(' ', 1);
		while (len-- > 0)
		{
			ft_putchar_fd(*str_f, 1);
			str_f++;
		}
	}
}

static int	ft_string_type_find_len(int prec, int len_str)
{
	if (prec >= 0)
		return ((prec < len_str) ? prec : len_str);
	else
		return (len_str);
}

int			ft_string_type(va_list argc, int width, int prec)
{
	char	*str_f;
	int		len_str;
	int		len;
	int		w;

	if (!(str_f = va_arg(argc, char *)))
		str_f = "(null)";
	len_str = ft_strlen(str_f);
	len = ft_string_type_find_len(prec, len_str);
	w = ft_abs(width) - len;
	ft_string_type_out(str_f, width, len, w);
	return ((w > 0) ? w + len : len);
}
