/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:22 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:45:17 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (*a && (*a)->next)
	{
		new_head = (*a)->next;
		tmp = (*a);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		(*a)->next = NULL;
		*a = new_head;
	}
	if (n == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int n)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (*b && (*b)->next)
	{
		new_head = (*b)->next;
		tmp = (*b);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		(*b)->next = NULL;
		*b = new_head;
	}
	if (n == 0)
		write(1, "rb\n", 3);
}

void	rra(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a;
	prev->next = NULL;
	*a = tmp;
	if (n == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int n)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *b;
	prev->next = NULL;
	*b = tmp;
	if (n == 0)
		write(1, "rrb\n", 4);
}
