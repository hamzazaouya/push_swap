/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aid_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:06:44 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 12:07:07 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_fill_arr(t_pushswap_data *psdata)
{
	int			*arr;
	int			i;
	t_psnode	*temp;

	arr = (int *)malloc(sizeof(int) * psdata->len_a);
	temp = psdata->stack_a;
	i = -1;
	while (++i < psdata->len_a)
	{
		arr[i] = temp->num;
		temp = temp->next;
	}
	return (arr);
}

void	ft_sort_arr(int *arr, int len)
{
	int	i;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
			continue ;
		}
		i++;
	}
}

int	ft_serch_arr(int *arr, int num)
{
	int	i;

	i = 0;
	while (1)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
}

void	ft_check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				exit(0);
			j++;
		}
		i++;
	}
}
