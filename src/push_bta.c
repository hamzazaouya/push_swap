/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:19:24 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 10:19:50 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_getpos_max(t_pushswap_data *psdata, t_psnode *temp, int i, int j)
{
	if (j == 1 && psdata->len_b == 1)
			psdata->maxs[j].pos = 0;
	else if (temp->index == psdata->maxs[j].num)
	{
		//printf("i = %d\n", i);
		if (i > psdata->len_b / 2)
		{
			psdata->maxs[j].pos = psdata->len_b - (i - 1);
			psdata->maxs[j].side = 2;
		}
		else
		{
			psdata->maxs[j].pos = i;
			psdata->maxs[j].side = 1;
		}
	}
}

void	ft_getpos(t_pushswap_data *psdata)
{
	int			i;
	int			j;
	t_psnode	*temp;

	i = 1;
	temp = psdata->stack_b;
	while (temp)
	{
		j = 0;
		while (j < psdata->maxs_len)
		{
			ft_getpos_max(psdata, temp, i, j);
			j++;
		}
		i++;
		temp = temp->next;
	}
}

t_maxs	*ft_getmov(t_pushswap_data *psdata)
{
	int		i;
	t_maxs	*min_pos;

	i = 0;
	while (1)
	{
		if (psdata->maxs[i].pos != 0)
		{
			min_pos = &psdata->maxs[i];
			break ;
		}
		i++;
	}
	i = 0;
	while (i < psdata->maxs_len)
	{
		if (psdata->maxs[i].pos != 0 && (psdata->maxs[i].pos <= min_pos->pos))
			min_pos = &psdata->maxs[i];
		i++;
	}
	min_pos->pos = 0;
	return (min_pos);
}

void	ft_push_bta_pusher(t_pushswap_data *psdata, t_maxs *pusher)
{
	while (psdata->stack_b)
	{
		if (psdata->stack_b->next \
				&& psdata->stack_b->next->index == pusher->num)
			ft_swap_b(&psdata->stack_b);
		if (psdata->stack_b->index == pusher->num)
		{
			ft_push_a(&psdata->stack_a, &psdata->stack_b);
			if (psdata->len_a \
					&& psdata->stack_a->index > psdata->stack_a->next->index)
				ft_swap_a(&psdata->stack_a);
			break ;
		}
		else if (pusher->side == 1)
			ft_rotate_b(&psdata->stack_b);
		else
			ft_rrb(&psdata->stack_b);
	}
}

void	ft_push_bta(t_pushswap_data *psdata)
{
	int		i;
	t_maxs	*pusher;

	while (psdata->len_b)
	{
		ft_get_maxes(psdata);
		i = 0;
		while (i < psdata->maxs_len && psdata->len_b)
		{
			ft_getpos(psdata);
			pusher = ft_getmov(psdata);
			ft_push_bta_pusher(psdata, pusher);
			i++;
			psdata->len_b--;
			psdata->len_a++;
		}
	}
}
