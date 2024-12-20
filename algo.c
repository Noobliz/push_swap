/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:54 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 15:25:22 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_best_move(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_cost	cost;

	init_struct(&cost);
	best = best_move(*a, *b);
	cost = calculate_cost(*a, *b, best->content);
	if (cost.ra <= cost.rra && cost.rb <= cost.rrb)
		execute_ra_rb(&cost, a, b);
	else if (cost.ra <= cost.rra && cost.rb >= cost.rrb)
		execute_ra_rrb(&cost, a, b);
	else if (cost.ra >= cost.rra && cost.rb <= cost.rrb)
		execute_rra_rb(&cost, a, b);
	else if (cost.ra >= cost.rra && cost.rb >= cost.rrb)
		execute_rra_rrb(&cost, a, b);
	pb(a, b);
}

static void	place_big_to_top(t_stack **b)
{
	int	size;
	int	index;

	size = stack_size(*b);
	index = value_index(*b, ft_max(*b));
	if (index <= (size / 2))
	{
		while (index > 0)
		{
			rb(b, 0);
			index--;
		}
	}
	else if (index > (size / 2))
	{
		index = size - index;
		while (index > 0)
		{
			rrb(b, 0);
			index--;
		}
	}
}

static void	place_small_to_top(t_stack **a)
{
	int	size;
	int	index;

	size = stack_size(*a);
	index = value_index(*a, ft_min(*a));
	if (index <= (size / 2))
	{
		while (index > 0)
		{
			ra(a, 0);
			index--;
		}
	}
	else if (index > (size / 2))
	{
		index = size - index;
		while (index > 0)
		{
			rra(a, 0);
			index--;
		}
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tail;
	t_stack	*current_a;
	int		min_a;

	tail = *a;
	current_a = *a;
	min_a = ft_min(*a);
	while (tail->next)
		tail = tail->next;
	if ((*b)->content < min_a)
	{
		place_small_to_top(a);
		pa(a, b);
	}
	else if ((*b)->content < (*a)->content && (*b)->content > tail->content)
		pa(a, b);
	else if ((*b)->content > tail->content)
		pa(a, b);
	else
		rra(a, 0);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	pb(a, b);
	pb(a, b);
	size_a = stack_size(*a);
	while (size_a > 3)
	{
		execute_best_move(a, b);
		size_a--;
	}
	place_big_to_top(b);
	sort_three(a);
	while ((*b))
	{
		push_back_to_a(a, b);
	}
	place_small_to_top(a);
}
