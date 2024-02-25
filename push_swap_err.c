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

int	checker(int ac, char **av)
{
	char	**str;
	int		i;

	i = 1;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		if (!check_is_number(str))
			return (free_arr(str),ft_putendl_fd("Error", 2), 0);
		free_arr(str);
		i++;
	}
	if (!is_double(ac, av))
			return (ft_putendl_fd("Error", 2), 0);
	if (!check_is_sorted(av + 1, alloc_len(av)))
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
