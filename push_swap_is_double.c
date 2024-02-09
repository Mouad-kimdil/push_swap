#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i - 1] > arr[i])
		{
			swap(&arr[i - 1], &arr[i]);
			i = 0;
		}
		i++;
	}
}

int check_doubles(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i - 1] == arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	alloc_len(char **av)
{
	int	len;
	int i;

	len = 0;
	i = 1;
	while (av[i])
	{
		len += countword(av[i], ' ');
		i++;
	}
	return (len);
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

int	is_double(int ac, char **av)
{
	int		*arr;
	char	**res;
	int		i;
	int		idx;

	i = 1;
	arr = malloc(sizeof(int) * alloc_len(av) + 1);
	idx = 0;
	while (i < ac)
	{
		res = ft_split(av[i], ' ');
		fill_arr(res, arr, &idx);
		free_arr(res);
		i++;
	}
	bubble_sort(arr, idx);
	if (!check_doubles(arr, idx))
		return (free(arr), 0);
	return (free(arr), 1);
}
