/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:02:08 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/15 02:26:30 by mkimdil          ###   ########.fr       */
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

int	process_string(char *str, int *ind, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	*ind = i;
	return (i);
}

int	my_is_digit(char *str)
{
	int		ind;
	int		sn;
	int		i;

	sn = 1;
	i = process_string(str, &ind, &sn);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (ft_strlen(str + ind) > 10)
		return (0);
	else if (ft_strlen(str + ind) == 10)
	{
		if (!((sn == 1 && ft_strcmp("2147483647", (str + ind)) >= 0)
				|| (sn == -1 && ft_strcmp("2147483648", (str + ind)) >= 0)))
			return (0);
	}
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

int	check_is_sorted(char **av, int size)
{
	int		*arr;
	char	**res;
	int		i;
	int		j;

	i = -1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (*av)
	{
		res = ft_split(*av, ' ');
		if (!res)
			return (free(arr), 0);
		j = -1;
		while (res[++j])
			arr[++i] = ft_atoi(res[j]);
		free_arr(res);
		av++;
	}
	if (is_sorted(arr, size))
		return (free(arr), 0);
	return (free(arr), 1);
}
