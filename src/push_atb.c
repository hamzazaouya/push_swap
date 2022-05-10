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
	t_psnode *temp;

	while (*swap_len < *swap_max)
	{
		if (psdata->stack_a->index < *swap_max)
		{
			ft_push_b(&psdata->stack_a, &psdata->stack_b);
			if (psdata->stack_b->index < (*swap_max - *facture / 2) \
					&& psdata->len_b > 5)
				ft_rotate_b(&psdata->stack_b);
			if (psdata->stack_b->next \
					&& psdata->stack_b->next->index > \
					psdata->stack_b->index && psdata->len_b > 5)
				ft_swap_b(&psdata->stack_b);
			(*swap_len)++;
			psdata->len_a--;
			psdata->len_b++;
		}
		else
		{
			temp = psdata->stack_a;
			while(temp->next)
				temp = temp->next;
			if(temp->index < *swap_max)
				ft_rra(&psdata->stack_a);
			else
				ft_rotate_a(&psdata->stack_a);
		}
	}
}

int	ft_is_sorted(t_psnode *stack_a)
{
	while(stack_a)
	{
		if(stack_a->next && (stack_a->index > stack_a->next->index))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_push_atb(t_pushswap_data *psdata)
{
	int	swap_len;
	int	swap_max;
	int	facture;

	swap_len = 0;
	while (psdata->len_a > 3 && ft_is_sorted(psdata->stack_a))
	{
		ft_get_facture(psdata);
		swap_max = ((psdata->len_a - 2) / psdata->facture) + swap_len + 1;
		facture = swap_max - swap_len;
		ft_push_atb_aid(psdata, &swap_len, &swap_max, &facture);
	}
	while(ft_is_sorted(psdata->stack_a))
	{
		if((psdata->stack_a->index > psdata->stack_a->next->index))
			ft_swap_a(&psdata->stack_a);
		if(ft_is_sorted(psdata->stack_a))
			ft_rra(&psdata->stack_a);
	}
}