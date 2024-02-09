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

int	check_is_number(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!my_is_digit(arr[i]))
			return (0);
		i++;
	}
	return (1);
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
