#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

int		my_is_digit(char *str);
int		check_is_number(char **av);
long	ft_atoi(char *str);
int		is_double(int ac, char **av);
void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
int		check_doubles(int *arr, int size);

#endif