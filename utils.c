/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:02:08 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 05:02:11 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (str[i] == ' ')
		i++;
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

int	check_is_number(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!my_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i - 1] > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_is_sorted(char **av, int size)
{
	int		*arr;
	char	**res;
	int		i;
	int		j;

	i = 0;
	arr = malloc(sizeof(int) * size);
	while (*av)
	{
		res = ft_split(*av, ' ');
		j = 0;
		while (res[j])
		{
			arr[i] = ft_atoi(res[j]);
			j++;
			i++;
		}
		free_arr(res);
		av++;
	}
	if (is_sorted(arr, size))
		return (free(arr), 0);
	return (free(arr), 1);
}