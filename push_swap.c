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


int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2 || !checker(ac, av))
		return (printf("error"), 0);
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack(&stack_a, av);
	print_stack(stack_a, 0);
	sa(&stack_a);
	print_stack(stack_a, 0);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, 0);
	print_stack(stack_b, 1);
	ra(&stack_a);
	rb(&stack_b);
	print_stack(stack_a, 0);
	print_stack(stack_b, 1);
	rra(&stack_a);
	rrb(&stack_b);
	print_stack(stack_a, 0);
	print_stack(stack_b, 1);
	sa(&stack_a);
	print_stack(stack_a, 0);
	print_stack(stack_b, 1);
	pa(&stack_b, &stack_a);
	pa(&stack_b, &stack_a);
	pa(&stack_b, &stack_a);
	print_stack(stack_a, 0);
	print_stack(stack_b, 1);

	return (0);

}
