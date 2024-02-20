#include "push_swap.h"

void print_stack(t_list *stack)
{
    while (stack)
	{
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
	t_list	stack_a;
	// t_list	stack_b;

	if (ac < 2 || !checker(ac, av))
		return (printf("error"), 0);
	initialize_stack(&stack_a, av);
	print_stack(&stack_a);
	// sa(&stack_a);
	// print_stack(&stack_a);
	// pa(&stack_a, &stack_b);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	return (printf("all good"), 0);
}
