/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:17:58 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/02 22:03:37 by mkimdil          ###   ########.fr       */
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

void	print_cost(t_list *stack, int state)
{
	if (state == 0)
		printf("cost_a: ");
	else if (state == 1)
		printf("cost_b: ");
	if (state == 0)
	{
		while (stack)
		{
			printf("%d ", stack->cost_a);
			stack = stack->next;
		}
	}
	else if (state == 1)
	{
		while (stack)
		{
			printf("%d ", stack->cost_b);
			stack = stack->next;
		}
	}
	printf("\n");
}

int	pre_final_sort(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	final_sort(t_list **stack_a)
{
	t_list	*curr;
	int		max;
	int		i;

	max = find_max(*stack_a);
	i = 0;
	curr = *stack_a;
	while (curr)
	{
		if (curr->data == max)
			break ;
		curr = curr->next;
		i++;
	}
	if (i < lstsize(*stack_a))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2 || !checker(ac, av))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack(&stack_a, av);
	if (lstsize(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else if (lstsize(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	if (lstsize(stack_a) == 3 || lstsize(stack_a) == 2)
		sort_three(&stack_a);
	if (lstsize(stack_a) > 5)
		sort(&stack_a, &stack_b);
	while (!pre_final_sort(stack_a))
	{
		if (final_sort(&stack_a) == 1)
			ra(&stack_a);
		else
			rra(&stack_a);
	}
	return (0);
}
