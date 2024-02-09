#include <stdio.h>
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
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
	{
		if (str[i] >= '0' && str[i] <= '9')
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
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
			return (0);
		i++;
	}
	temp = ft_atoi(str);
	if (temp > 2147483647 || temp < -2147483648)
		return (0);
	return (1);
}

int	count(char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (av[i])
	{
		count += countword(av[i], ' ');
		i++;
	}
	return (count);
}

void	fill_arr(char **av, int *arr)
{
	int		i;
	int		j;
	char	**final;

	i = 1;
	while (av[i])
	{
		j = i - 1;
		final = ft_split(av[i], ' ');
		while (final[j])
		{
			arr[j] = ft_atoi(final[j]);
			j++;
		}
		i++;
	}
}

int	*is_doublee(char **str)
{
	int	i;
	int	j;
	int	*arr;
	int	len;

	len = 0;
	while (str[len])
		len++;
	arr = malloc(sizeof(int) * len + 1);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atoi(str[i]);
		i++;
	}
	return (arr);
}

int main(int ac, char **av)
{
	char *str[] = {"1", "2", "3", NULL};
	int *arr = is_doublee(str);
	int i = 0;
	while (i < 9)
	{
		printf("%d ", arr[i]);
		i++;
	}
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

void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);