#include "../includes/push_swap.h"

void	ft_rrr(t_psnode **stack_a, t_psnode **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}