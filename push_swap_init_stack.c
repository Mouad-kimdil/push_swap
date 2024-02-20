/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:33:04 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/20 14:48:58 by mkimdil          ###   ########.fr       */
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

void	initialize_stack(t_list *stack, char **av)
{
	int		i;
	char	*str;
	char	**res;
	t_list	*new;

	str = join_args(av);
	res = ft_split(str, ' ');
	printf("%s\n", str);
	free(str);
	i = 0;
	while (res[i])
	{
		new = lstnew(ft_atoi(res[i]));
		lstadd_back(&stack, new);
		i++;
	}
}
