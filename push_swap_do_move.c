/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_do_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:11:25 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/05 22:40:12 by aboukdid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

void	rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

void	rotate_a(t_list **a, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

void	rotate_b(t_list **b, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}
