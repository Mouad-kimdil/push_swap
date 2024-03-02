/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:17:58 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/02 03:31:34 by mkimdil          ###   ########.fr       */
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
		return;
	}
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

void	print_index(t_list *stack, int state)
{
	if (state == 0)
		printf("index_a: ");
	else if (state == 1)
		printf("index_b: ");
	if (!stack)
	{
		printf("is empty\n");
		return;
	}
	while (stack)
	{
		printf("%d ", stack->idx);
		stack = stack->next;
	}
	printf("\n");
}

void	print_pos(t_list *stack, int state)
{
	if (state == 0)
		printf("pos_a: ");
	else if (state == 1)
		printf("pos_b: ");
	if (!stack)
	{
		printf("is empty\n");
		return;
	}
	while (stack)
	{
		printf("%d ", stack->pos);
		stack = stack->next;
	}
	printf("\n");
}

void	print_target(t_list *stack, int state)
{
	if (state == 0)
		printf("target_a: ");
	else if (state == 1)
		printf("target_b: ");
	if (!stack)
	{
		printf("is empty\n");
		return;
	}
	while (stack)
	{
		printf("%d ", stack->target_pos);
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
	if (!stack)
	{
		printf("is empty\n");
		return;
	}
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

int final_sort(t_list *stack_a)
{
    while (stack_a && stack_a->next)
    {
        if (stack_a->data > stack_a->next->data)
            return 0;
        stack_a = stack_a->next;
    }
    return 1;
}

int main(int ac, char **av)
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
	while (!final_sort(stack_a))
		rra(&stack_a);
	return (0);
}
