/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:17 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 05:01:20 by mkimdil          ###   ########.fr       */
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
		i++;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

t_list	*initialize_stack(int ac, char **av)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			stack_a = lstnew((int)nb);
		else
			stack_add_bottom(&stack_a, lstnew((int)nb));
		i++;
	}
	return (stack_a);
}
