/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:25 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 05:01:25 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !*lst)
		return ;
	last = lstlast(*lst);
	if (!lst)
	{
		*lst = new;
		return ;
	}
	last->next = new;
}

void	lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !*lst)
		return ;
	new->next = *lst;
	*lst = new;
}

int	lstsize(t_list	*head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_list	*lstnew(int num)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->data = num;
	ptr->idx = 0;
	ptr->pos = -1;
	ptr->target_pos = -1;
	ptr->cost_a = -1;
	ptr->cost_b = -1;
	ptr->next = NULL;
	return (ptr);
}
