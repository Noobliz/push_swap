/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:05:17 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:44:55 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_index(t_stack *stack, int value)
{
	int	index;

	if (value == stack->content)
		return (0);
	index = 0;
	while (stack)
	{
		if (stack->content == value)
		{
			return (index);
		}
		index++;
		stack = stack->next;
	}
	return (-1);
}

static int	get_insert_position(t_stack *b, int value)
{
	int		pos;
	int		size;
	t_stack	*current;
	t_stack	*tail;

	size = stack_size(b);
	current = b;
	tail = b;
	while (tail->next)
		tail = tail->next;
	pos = 1;
	if ((!current) || (value > current->content && value < tail->content))
		return (0);
	if (value > ft_max(b) || value < ft_min(b))
		return (value_index(b, ft_max(b)));
	while (current->next)
	{
		if (value < current->content && value > current->next->content)
			break ;
		pos++;
		current = current->next;
	}
	return (pos);
}

t_cost	calculate_cost(t_stack *a, t_stack *b, int value)
{
	t_cost	cost;
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	cost.ra = value_index(a, value);
	cost.rra = (size_a)-cost.ra;
	cost.rb = get_insert_position(b, value);
	cost.rrb = (size_b)-cost.rb;
	cost.total_cost = min_op(max_op(cost.ra, cost.rb), max_op(cost.rra,
				cost.rrb));
	return (cost);
}

t_stack	*best_move(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*best;
	t_cost	cost;
	int		best_cost;

	best_cost = 2147483647;
	current = a;
	while (current)
	{
		cost = calculate_cost(a, b, current->content);
		if (cost.total_cost < best_cost)
		{
			best = current;
			best_cost = cost.total_cost;
		}
		current = current->next;
	}
	return (best);
}
