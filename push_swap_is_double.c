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

int	is_double(char **str)
{
	int	*arr;
	int	i;
	int	size;

	size = 0;
	while (str[size])
		size++;
	arr = malloc(sizeof(int) * size + 1);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi(str[i]);
		i++;
	}
	bubble_sort(arr, size);
	if (!check_doubles(arr, size))
		return (free(arr), 0);
	return (free(arr), 1);
}
