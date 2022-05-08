/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:11:07 by hazaouya          #+#    #+#             */
/*   Updated: 2022/05/08 12:20:12 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

typedef struct ps_node
{
	int				num;
	int				index;
	struct ps_node	*next;
}	t_psnode;

typedef struct maxs
{
	int	num;
	int	pos;
	int	side;
}	t_maxs;

typedef struct push_swap
{
	int			argc;
	int			len_a;
	int			len_b;
	int			facture;
	int			maxs_len;
	t_maxs		*maxs;
	t_psnode	*stack_a;
	t_psnode	*stack_b;
}	t_pushswap_data;

t_psnode	*ft_stack_a(int argc, char **argv);
int			ft_atoi(const char *str);
void		ft_swap_a(t_psnode **stack_a);
void		ft_swap_b(t_psnode **stack_b);
void		ft_swap_ss(t_pushswap_data *psdata);
void		ft_push_b(t_psnode **stack_a, t_psnode **stack_b);
t_psnode	*ft_create_node(void);
void		ft_add_front(t_psnode **list, t_psnode **node);
void		ft_add_back(t_psnode **list);
int			ft_node_len(t_psnode *node);
void		ft_push_a(t_psnode **stack_a, t_psnode **stack_b);
void		ft_push_b(t_psnode **stack_a, t_psnode **stack_b);
void		ft_rotate(t_psnode **list);
void		ft_rotate_a(t_psnode **stack_a);
void		ft_rotate_b(t_psnode **stack_b);
void		ft_rra(t_psnode **stack_a);
void		ft_reverse_rotate(t_psnode **list);
void		ft_rrb(t_psnode **stack_b);
void		ft_rrr(t_psnode **stack_a, t_psnode **stack_b);
void		ft_push_atb(t_pushswap_data *psdata);
void		ft_push_bta(t_pushswap_data *psdata);
void		ft_getpos(t_pushswap_data *psdata);
int			ft_strcmp(char *str1, char *str2);
void		ft_rr(t_psnode **stack_a, t_psnode **stack_b);
void		ft_get_maxes(t_pushswap_data *psdata);
int			ft_serch_arr(int *arr, int num);
void		ft_sort_arr(int *arr, int len);
int			*ft_fill_arr(t_pushswap_data *psdata);
void		ft_index_stack_a(t_pushswap_data *psdata);
void		ft_check_input(int argc, char **argv);
#endif
