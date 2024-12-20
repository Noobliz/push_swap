/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:14:45 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:47:02 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b, int n)
{
	ra(a, 1);
	rb(b, 1);
	if (n == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, int n)
{
	rra(a, 1);
	rrb(b, 1);
	if (n == 1)
		write(1, "rrr\n", 4);
}

void	sa(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	write(1, "pb\n", 3);
}
