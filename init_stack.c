/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:17 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 18:59:51 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(char **av)
{
	char	*temp;
	char	*str;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (av[i])
	{
		temp = ft_strjoin(av[i], " ");
		str = ft_strjoin(str, temp);
		free(temp);
		i++;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
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
		j = -1;
		while (tokens[++j] != NULL)
		{
			nb = ft_atoi(tokens[j]);
			free(tokens[j]);
			if (stack_a == NULL)
				stack_a = lstnew((int)nb);
			else
				lstadd_back(&stack_a, lstnew((int)nb));
		}
		free(tokens);
	}
	return (stack_a);
}
