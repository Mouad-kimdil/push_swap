#include "push_swap.h"

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	cheker(int ac, char **av)
{
	char	**arr;
	int		i;

	i = 1;
	while (av[i])
	{
		arr = ft_split(av[i], ' ');
		if (!check_is_number(arr))
			return (free_arr(arr), 0);
		free_arr(arr);
		i++;
	}
	if (!is_double(ac, av))
			return (0);
	return (1);
}

int	*fill_arr(char **res, int *arr, int *idx)
{
	int	i;

	i = 0;
	while (res[i])
	{
		arr[*idx] = ft_atoi(res[i]);
		i++;
		*idx = *idx + 1;
	}
	return (arr);
}