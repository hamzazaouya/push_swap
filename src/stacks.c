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

t_psnode	*ft_stack_a(int len, int *numbres)
{
	int			i;
	t_psnode	*head;
	t_psnode	*temp;

	head = NULL;
	head = ft_create_node();
	temp = head;
	i = 0;
	while (i < len)
	{
		temp->num = numbres[i];
		if (i + 1 != len)
			temp->next = ft_create_node();
		temp = temp->next;
		i++;
	}
	return (head);
}

