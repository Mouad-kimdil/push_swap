/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:17 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/15 02:40:42 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
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

char	*join_args(char **av)
{
	char	*temp;
	char	*str;
	int		i;

	i = 1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (av[i])
	{
		temp = ft_strjoin(av[i], " ");
		if (!temp)
			return (free(str), NULL);
		str = ft_strjoin(str, temp);
		if (!str)
			return (free(temp), NULL);
		free(temp);
		i++;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

void	do_init(t_list **stack_a, int nb)
{
	if (*stack_a == NULL)
		*stack_a = lstnew(nb);
	else
		lstadd_back(stack_a, lstnew(nb));
}

t_list	*initialize_stack(int ac, char **av)
{
	t_list	*stack_a;
	long	nb;
	int		i;
	int		j;
	char	**tokens;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (++i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!tokens)
			return (NULL);
		j = -1;
		while (tokens[++j] != NULL)
		{
			nb = ft_atoi(tokens[j]);
			free(tokens[j]);
			do_init(&stack_a, nb);
		}
		free(tokens);
	}
	return (stack_a);
}
