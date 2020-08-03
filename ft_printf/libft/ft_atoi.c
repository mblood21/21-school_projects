/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblood <mblood@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:47:23 by mblood            #+#    #+#             */
/*   Updated: 2020/05/23 15:43:54 by mblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int				i;
	long long int	res_num;
	long long int	is_neg;

	i = 0;
	res_num = 0;
	is_neg = 1;
	if (!nptr[i])
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res_num = (res_num * 10) + (long long int)(nptr[i] - '0');
		i++;
	}
	return (res_num * is_neg);
}
