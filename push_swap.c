
#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac < 4)
		return (printf("ko 1"), 0);
	if (!check_is_number(av))
		return (printf("ko 2"),0);
	if (!is_double(ac, av))
		return (printf("ko 3"), 0);
	printf("ok");
	return (0);
}