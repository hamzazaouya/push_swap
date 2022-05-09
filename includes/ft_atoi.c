/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:16:03 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/22 13:44:50 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_num(const char *str, int sign)
{
	long long	nb;	
	int			i;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
		if((nb > 2147483647 && sign > 0) || (nb > 2147483648 && sign < 0))
			ft_error();
	}
	if(str[i])
		ft_error();
	return (nb);
}

int	ft_check(char sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	nb;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		nb = ft_num(str + i, sign);
	else
		ft_error();
	if (nb < 0)
		return (ft_check(sign));
	return ((int )nb * sign);
}
