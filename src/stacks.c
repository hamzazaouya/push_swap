/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 09:00:26 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 09:05:42 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_maxes(t_pushswap_data *psdata)
{
	psdata->maxs[0].num = psdata->len_b - 1;
	if (psdata->len_b > 1)
		psdata->maxs[1].num = psdata->len_b - 2;
}

t_psnode	*ft_create_node(void)
{
	t_psnode	*node;

	node = (t_psnode *)malloc(sizeof(t_psnode));
	node->next = NULL;
	return (node);
}

t_psnode	*ft_stack_a(int argc, char **argv)
{
	int			i;
	t_psnode	*head;
	t_psnode	*temp;

	head = NULL;
	if (argc > 1)
	{
		head = ft_create_node();
		temp = head;
		i = 1;
		while (i < argc)
		{
			temp->num = ft_atoi(argv[i]);
			if (i != argc - 1)
				temp->next = ft_create_node();
			temp = temp->next;
			i++;
		}
	}
	return (head);
}

void	ft_index_stack_a(t_pushswap_data *psdata)
{
	int			*aide_arr;
	t_psnode	*temp;

	temp = psdata->stack_a;
	aide_arr = ft_fill_arr(psdata);
	ft_sort_arr(aide_arr, psdata->len_a);
	while (temp)
	{
		temp->index = ft_serch_arr(aide_arr, temp->num);
		temp = temp->next;
	}
	free(aide_arr);
}

void	ft_rrr(t_psnode **stack_a, t_psnode **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
