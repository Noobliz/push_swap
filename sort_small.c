/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:39:16 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/13 13:18:39 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

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
		ra(stack);
		write(2, "ra\n", 3);
	}
	else if (second > first && second > third)
	{
		rra(stack);
		write(2, "rra\n", 4);
	}
	first = (*stack)->content;
	second = (*stack)->next->content;
	if (first > second)
		swap_top(stack);
}

int	find_smallest(t_stack *stack)
{
	int	min;
	int	i;
	int	pos;

	min = stack->content;
	i = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
void	move_small_to_top(t_stack **stack, int pos)
{
	t_stack	*tmp;
	int		size;

	tmp = *stack;
	size = 0;
	if (pos == 0)
		return ;
	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(stack);
			pos--;
		}
	}
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
	int	pos;

	if (size == 5)
		sort_five(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 3)
		sort_three(a);
	else
	{
		pos = find_smallest(*a);
		move_small_to_top(a, pos);
	}
}
