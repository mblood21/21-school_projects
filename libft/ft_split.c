/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:46:19 by mblood            #+#    #+#             */
/*   Updated: 2020/05/24 13:54:08 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	letter_count(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static size_t	lines_count(char const *s, char c)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	if (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i - 1] != c) ||
		(i != 0 && s[i + 1] == '\0' && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static void		*let_me_free(char **arr, size_t line)
{
	size_t i;

	i = 0;
	while (i < line)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char		**arr_filling(char const *s, size_t nblines, char c, char **arr)
{
	size_t i;
	size_t line;
	size_t letters;
	size_t index_s;

	index_s = 0;
	line = 0;
	while (line < nblines && s[index_s] != '\0')
	{
		while (s[index_s] == c)
			index_s++;
		letters = letter_count(s + index_s, c);
		if (!(arr[line] = (char *)malloc(sizeof(char) * (letters + 1))))
			return (let_me_free(arr, line));
		i = -1;
		while (++i < letters && s[i + index_s] != '\0')
			arr[line][i] = s[i + index_s];
		arr[line][i] = '\0';
		index_s += letters;
		line++;
	}
	arr[line] = NULL;
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	nblines;

	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	nblines = lines_count(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (nblines + 1))))
		return (0);
	return (arr_filling(s, nblines, c, arr));
}
