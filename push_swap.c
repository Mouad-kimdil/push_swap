/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:29 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 08:10:39 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack, int state)
{
	if (state == 0)
		printf("stack_a: ");
	else if (state == 1)
		printf("stack_b: ");
	if (!stack)
	{
		printf("is empty\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		data;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		data = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->idx == 0)
				ptr->idx = 1;
			if (ptr->data > data && ptr->idx == 0)
			{
				data = ptr->data;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->idx = stack_size;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (ac < 2 || !checker(ac, av))
		return (0);
	stack_b = NULL;
	stack_a = initialize_stack(ac, av);
	size = lstsize(stack_a);
	assign_index(stack_a, size + 1);
	if (lstsize(stack_a) == 3 || lstsize(stack_a) == 2)
		sort_three(&stack_a);
	else if (lstsize(stack_a) > 3)
		sort(&stack_a, &stack_b);
	print_stack(stack_a, 0);
	return (0);
}
