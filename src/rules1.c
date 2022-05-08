/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:29:47 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 08:54:18 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_psnode **stack_a)
{
	t_psnode	*temp;
	int			node_len;

	node_len = ft_node_len(*(stack_a));
	if (node_len >= 2)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_psnode **stack_b)
{
	t_psnode	*temp;
	int			node_len;

	node_len = ft_node_len(*(stack_b));
	if (node_len >= 2)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_pushswap_data *psdata)
{
	ft_swap_a(&psdata->stack_a);
	ft_swap_b(&psdata->stack_b);
	write(1, "ss\n", 3);
}

void	ft_push_b(t_psnode **stack_a, t_psnode **stack_b)
{
	t_psnode	*temp;
	int			node_len;

	node_len = ft_node_len(*stack_a);
	if (node_len)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_add_front(stack_b, &temp);
	}
	write(1, "pb\n", 3);
}

void	ft_push_a(t_psnode **stack_a, t_psnode **stack_b)
{
	t_psnode	*temp;
	int			node_len;

	node_len = ft_node_len(*stack_b);
	if (node_len)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_add_front(stack_a, &temp);
	}
	write(1, "pa\n", 3);
}
