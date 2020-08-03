/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:07:57 by mblood            #+#    #+#             */
/*   Updated: 2020/07/29 20:53:10 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_args
{
	int				width;
	int				prec;
	int				res;
	int				percent;
	const char		*frmt;
}					t_args;

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
void				*ft_memset(void *s, int c, size_t n);
void				ft_strlcpy_ch(char *dst, const char *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_itoa(int n);
char				*ft_itoa_unsigned(size_t n);
int					ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_abs(int nb);
int					ft_nblen(int nb);
int					ft_printf(const char *format, ...);
int					ft_check_format(const char *format, va_list argc);
int					ft_int_type(va_list argc, int width, int prec);
int					ft_char_type(va_list argc, int width);
int					ft_string_type(va_list argc, int width, int prec);
int					ft_unsigned_int_type(va_list argc, int width, int prec);
int					ft_x_type(va_list argc, int width, int prec, int flag_x);
char				*ft_hexadecimal_notation(size_t nb, int flag);
int					ft_pointer_type(va_list argc, int width, int prec);
int					ft_new_conversions(const char *format, va_list argc,
										int width, int prec);
void				ft_parser(t_args *parsed, const char *format, va_list argc);
int					ft_print_percent(int width, int prec);

#endif
