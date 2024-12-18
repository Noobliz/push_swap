/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:54 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/18 12:08:51 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_ra_rb(t_cost *cost, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (cost->ra > 0 && cost->rb > 0)
	{
		rr(a, b, 1);
		cost->ra--;
		cost->rb--;
		count++;
	}
	while (cost->ra > 0)
	{
		ra(a, 0);
		cost->ra--;
		count++;
	}
	while (cost->rb > 0)
	{
		rb(b, 0);
		cost->rb--;
		count++;
	}
	return (count);
}
int	execute_ra_rrb(t_cost *cost, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (cost->ra > 0)
	{
		ra(a, 0);
		cost->ra--;
		count++;
	}
	while (cost->rrb > 0)
	{
		rrb(b, 0);
		cost->rrb--;
		count++;
	}
	return (count);
}
int	execute_rra_rb(t_cost *cost, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (cost->rra > 0)
	{
		rra(a, 0);
		cost->rra--;
		count++;
	}
	while (cost->rb > 0)
	{
		rb(b, 0);
		cost->rb--;
		count++;
	}
	return (count);
}
int	execute_rra_rrb(t_cost *cost, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (cost->rra > 0 && cost->rrb > 0)
	{
		rrr(a, b, 1);
		cost->rra--;
		cost->rrb--;
		count++;
	}
	while (cost->rra > 0)
	{
		rra(a, 0);
		cost->rra--;
		count++;
	}
	while (cost->rrb > 0)
	{
		rrb(b, 0);
		cost->rrb--;
		count++;
	}
	return (count);
}
int	execute_best_move(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_cost	cost;

	int count = 0; // NE PAS OUBLIER DENLEVER
	init_struct(&cost);
	best = best_move(*a, *b);
	cost = calculate_cost(*a, *b, best->content);
	if (cost.ra <= cost.rra && cost.rb <= cost.rrb)
		count += execute_ra_rb(&cost, a, b);
	else if (cost.ra <= cost.rra && cost.rb >= cost.rrb)
		count += execute_ra_rrb(&cost, a, b);
	else if (cost.ra >= cost.rra && cost.rb <= cost.rrb)
		count += execute_rra_rb(&cost, a, b);
	else if (cost.ra >= cost.rra && cost.rb >= cost.rrb)
		count += execute_rra_rrb(&cost, a, b);
	pb(a, b);
	count++;
	// printf("stack b after pushing : ");
	// print_stack(*b);
	// printf("%d\n", count);
	return (count);
}
int	place_big_to_top(t_stack **b)
{
	int	size;
	int	index;
	int	count;

	count = 0;
	size = stack_size(*b);
	index = value_index(*b, ft_max(*b));
	if (index <= (size / 2))
	{
		while (index > 0)
		{
			rb(b, 0);
			index--;
			count++;
		}
	}
	else if (index > (size / 2))
	{
		index = size - index;
		while (index > 0)
		{
			rrb(b, 0);
			index--;
			count++;
		}
	}
	return (count);
}
int	place_small_to_top(t_stack **a)
{
	int	size;
	int	index;
	int	count;

	count = 0;
	size = stack_size(*a);
	index = value_index(*a, ft_min(*a));
	if (index <= (size / 2))
	{
		while (index > 0)
		{
			ra(a, 0);
			index--;
			count++;
		}
	}
	else if (index > (size / 2))
	{
		index = size - index;
		while (index > 0)
		{
			rra(a, 0);
			index--;
			count++;
		}
	}
	return (count);
}
int	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tail;
	t_stack	*current_a;
	int		count;
	int		min_a;
	int		min_b;

	tail = *a;
	current_a = *a;
	count = 0;
	min_a = ft_min(*a);
	min_b = ft_min(*b);
	while (tail->next)
		tail = tail->next;
	if ((*b)->content < min_a)
	{
		count += place_small_to_top(a);
		pa(a, b);
		count++;
	}
	else if ((*b)->content < (*a)->content && (*b)->content > tail->content)
	{
		pa(a, b);
		count++;
	}
	else if ((*b)->content > tail->content)
	{
		pa(a, b);
		count++;
	}
	else
	{
		rra(a, 0);
		count++;
	}
	return (count);
}
void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	int count = 2; // NE PAS OUBLIER DENLEVER
	pb(a, b);
	pb(a, b);
	size_a = stack_size(*a);
	while (size_a > 3)
	{
		count += execute_best_move(a, b);
		size_a--;
	}
	count += place_big_to_top(b);
	sort_three(a);
	// printf("STACK B SORTED :\n");
	// print_stack(*b);
	// printf("STACK A with 3 numbers :\n");
	// print_stack(*a);
	while ((*b))
	{
		count += push_back_to_a(a, b);
	}
	count += place_small_to_top(a);
	printf("TOTAL COUNT : %d\n", count);
	printf("STACK A after the push_back_to_a :\n");
	print_stack(*a);
}
