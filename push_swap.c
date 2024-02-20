#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac < 2 || !checker(ac, av))
		return (printf("num of args less than 2 or checker"),0);
	return (printf("all good"), 0);
}
