/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:39:16 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:49:11 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if (!is_sorted(*stack))
		sa(stack);
	else
		return ;
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	if (!(*stack && (*stack)->next && (*stack)->next->next))
		return ;
	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && first > third)
	{
		ra(stack, 0);
	}
	else if (second > first && second > third)
	{
		rra(stack, 0);
	}
	first = (*stack)->content;
	second = (*stack)->next->content;
	if (first > second)
		sa(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_smallest(*a);
	move_small_to_top(a, pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_smallest(*a);
	move_small_to_top(a, pos);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_upto_five(t_stack **a, t_stack **b, int size)
{
	if (size == 5)
		sort_five(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 3)
		sort_three(a);
	else if (size == 2)
		sort_two(a);
	else
		return ;
}
