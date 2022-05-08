/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:44:44 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 11:10:33 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(int argc, char **argv, t_pushswap_data *psdata)
{
	psdata->argc = argc;
	psdata->stack_a = ft_stack_a(argc, argv);
	psdata->stack_b = NULL;
	psdata->stack_a->index = -1;
	psdata->len_a = argc - 1;
	psdata->len_b = 0;
	psdata->maxs_len = 2;
	psdata->maxs = (t_maxs *)malloc(sizeof(t_maxs) * psdata->maxs_len);
}

int	main(int argc, char **argv)
{
	t_pushswap_data	psdata;

	ft_check_input(argc, argv);
	ft_init(argc, argv, &psdata);
	ft_index_stack_a(&psdata);
	ft_push_atb(&psdata);
	ft_push_bta(&psdata);
}
