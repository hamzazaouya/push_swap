/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:21:00 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 10:43:55 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_facture(t_pushswap_data *psdata)
{
	if (psdata->len_a <= 50)
			psdata->facture = 2;
	else if (psdata->len_a <= 100)
		psdata->facture = 3;
	else if (psdata->len_a <= 275)
		psdata->facture = 4;
	else if (psdata->len_a <= 350)
		psdata->facture = 5;
	else
			psdata->facture = 6;
}

void	ft_push_atb_aid(t_pushswap_data *psdata, int *swap_len, \
		int *swap_max, int *facture)
{
	while (*swap_len < *swap_max)
	{
		if (psdata->stack_a->index < *swap_max)
		{
			ft_push_b(&psdata->stack_a, &psdata->stack_b);
			if (psdata->stack_b->index < (*swap_max - *facture / 2) \
					&& psdata->len_b)
				ft_rotate_b(&psdata->stack_b);
			if (psdata->stack_b->next \
					&& psdata->stack_b->next->index > \
					psdata->stack_b->index)
				ft_swap_b(&psdata->stack_b);
			(*swap_len)++;
			psdata->len_a--;
			psdata->len_b++;
		}
		else
			ft_rotate_a(&psdata->stack_a);
	}
}

void	ft_push_atb(t_pushswap_data *psdata)
{
	int	swap_len;
	int	swap_max;
	int	facture;

	swap_len = 0;
	while (psdata->len_a)
	{
		ft_get_facture(psdata);
		swap_max = (psdata->len_a / psdata->facture) + swap_len + 1;
		facture = swap_max - swap_len;
		ft_push_atb_aid(psdata, &swap_len, &swap_max, &facture);
	}
}
