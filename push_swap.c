#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("ko 1"), 0);
	if (cheker(ac, av) == 0)
		return (printf("ko 2"), 0);
	printf("ok");
	return (0);
}
