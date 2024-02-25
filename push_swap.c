#include "push_swap.h"

void print_stack(t_list *stack, int state)
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

void print_index(t_list *stack, int state)
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
        printf("%d ", stack->idx);
        stack = stack->next;
    }
    printf("\n");
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
	print_stack(stack_a, 0);
	print_stack(stack_b, 1);
	indexing(&stack_a, av, ac);
	print_index(stack_a, 0);
	return (0);
}
