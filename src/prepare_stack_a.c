#include "../includes/push_swap.h"

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

void	ft_prepare_stack_a(t_pushswap_data *psdata, int *numbers)
{
	t_psnode	*temp;

	temp = psdata->stack_a;
	ft_sort_arr(numbers, psdata->len_a);
	while (temp)
	{
		temp->index = ft_serch_arr(numbers, temp->num);
		temp = temp->next;
	}
	free(numbers);
}