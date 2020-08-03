/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 15:59:28 by mblood            #+#    #+#             */
/*   Updated: 2020/07/20 21:26:29 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		rec(char **line, char *buff, char *n, size_t len)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!(new_str = (char *)malloc(len)))
		return (-1);
	while ((new_str[i] = (*line)[i]))
		i++;
	if (n)
		ft_strlcpy(&(new_str[i]), buff, (size_t)(n - buff));
	else
		ft_strlcpy(&(new_str[i]), buff, len);
	if (n && n[1])
		ft_strlcpy(buff, n + 1, BUFFER_SIZE + 1);
	else
		*buff = '\0';
	free(*line);
	*line = new_str;
	if (n)
		return (1);
	else
		return (0);
}

static int		supplement(char **line, char *buff)
{
	size_t	len;
	char	*n;

	len = ft_strlen(*line) + 1;
	n = ft_strchr(buff, '\n');
	if (!n)
		len += ft_strlen(buff);
	else
		len += (size_t)(n - buff);
	return (rec(line, buff, n, len));
}

int				get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE] = {0};
	int			conclusion;

	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char))))
		return (0);
	**line = '\0';
	while (1)
	{
		if ((conclusion = supplement(line, buff)))
			return (conclusion);
		if ((conclusion = read(fd, &buff, BUFFER_SIZE)) <= 0)
			return (conclusion);
		buff[conclusion] = '\0';
	}
	return (0);
}
