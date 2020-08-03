/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:00:45 by mblood            #+#    #+#             */
/*   Updated: 2020/06/21 19:33:58 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "unistd.h"
# include "stdlib.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
int					get_next_line(const int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *str, int c);
void				ft_strlcpy(char *dst, const char *src, size_t size);

#endif
