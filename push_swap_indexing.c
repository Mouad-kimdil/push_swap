/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 04:35:36 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/02 22:07:44 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_help(int *arr, t_list **stack, int count)
{
	t_list	*curr;
	int		i;

	curr = *stack;
	while (curr)
	{
		i = 0;
		while (i < count)
		{
			if (curr->data == arr[i])
			{
				curr->idx = i + 1;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

void	handle_multiple_args(t_list **stack, char **av, int argc, int *arr)
{
	int	i;

	arr = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (av[++i])
		arr[i - 1] = ft_atoi(av[i]);
	bubble_sort(arr, argc - 1);
	indexing_help(arr, stack, argc - 1);
	free(arr);
}

void	handle_single_arg(t_list **stack, char **av, char **numbers, int *arr)
{
	int	i;
	int	count;

	numbers = ft_split(av[1], ' ');
	count = 0;
	while (numbers[count])
		count++;
	arr = malloc(sizeof(int) * count);
	i = -1;
	while (numbers[++i])
		arr[i] = ft_atoi(numbers[i]);
	bubble_sort(arr, count);
	indexing_help(arr, stack, count);
	free(arr);
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

void	indexing(t_list **stack, char **av, int argc)
{
	int		*arr;
	char	**numbers;

	arr = NULL;
	numbers = NULL;
	if (argc > 2)
		handle_multiple_args(stack, av, argc, arr);
	else
		handle_single_arg(stack, av, numbers, arr);
}
