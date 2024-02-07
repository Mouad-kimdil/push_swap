#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

int	my_is_digit(char *str)
{
	int		i;
	long	temp;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	temp = ft_atoi(str);
	if (temp > 2147483647 || temp < -2147483648)
		return (0);
	return (1);
}

int	check_is_number(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!my_is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_double(int ac, char **av)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc(sizeof(int) * ac + 1);
	i = 1;
	j = 0;
	while (av[i])
	{
		arr[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	if (!check_doubles(arr, ac - 1))
		return (free(arr), 0);
	return (free(arr), 1);
}

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

	bubble_sort(arr, size);
	i = 1;
	while (i < size)
	{
		if (arr[i - 1] == arr[i])
			return (0);
		i++;
	}
	return (1);
}
