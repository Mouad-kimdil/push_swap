
#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac < 4)
		return (0);
	if (!check_is_number(av))
		return (0);
	if (!is_double(ac, av))
		return (printf("ko"), 0);
	printf("ok");
	return (0);
}