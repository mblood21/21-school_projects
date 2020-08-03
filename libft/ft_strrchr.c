/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:00:28 by mblood            #+#    #+#             */
/*   Updated: 2020/05/21 16:59:40 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*last;

	i = 0;
	last = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			last = (char *)&str[i];
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		last = (char *)&str[i];
	return (last);
}
