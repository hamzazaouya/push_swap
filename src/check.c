#include "../includes/push_swap.h"

void ft_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

int	*ft_get_numbers(int argc, char **argv)
{
	int i;
	int *numbers;

	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (numbers == NULL)
		exit(0);
	i = 1;
	while (i < argc)
	{
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (numbers);
}

void	ft_check_numbers(int *numbers, int len)
{
	int	i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
				ft_error();
			j++;
		}
		i++;
	}
}

int	*ft_check_input(int argc, char **argv)
{
	int *numbers;
	int i;

	i = 0;
	if (argc == 1)
		exit(0);
	numbers = ft_get_numbers(argc, argv);
	ft_check_numbers(numbers, argc - 1);
	return numbers;
}