/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:10:12 by mblood            #+#    #+#             */
/*   Updated: 2020/05/23 15:45:57 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1)))
		return (0);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
		str[len_s1++] = s2[i++];
	str[len_s1] = '\0';
	return ((char *)str);
}
