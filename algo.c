/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:54 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/16 17:19:26 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_ra_rb(t_cost *cost, t_stack **a, t_stack **b, int *count)
{
	while (cost->ra > 0 && cost->rb > 0)
	{
		rr(a, b);
		write(1, "rr\n", 3);
		cost->ra--;
		cost->rb--;
		count++;
	}
	while (cost->ra > 0)
	{
		ra(a);
		write(1, "ra\n", 3);
		cost->ra--;
		count++;
	}
	while (cost->rb > 0)
	{
		rb(b);
		write(1, "rb\n", 3);
		cost->rb--;
		count++;
	}
}
void	execute_ra_rrb(t_cost *cost, t_stack **a, t_stack **b, int *count)
{
	while (cost->ra > 0)
	{
		ra(a);
		write(1, "ra\n", 3);
		cost->ra--;
		count++;
	}
	while (cost->rrb > 0)
	{
		rrb(b);
		write(1, "rrb\n", 4);
		cost->rrb--;
		count++;
	}
}
void	execute_rra_rb(t_cost *cost, t_stack **a, t_stack **b, int *count)
{
	while (cost->rra > 0)
	{
		rra(a);
		write(1, "rra\n", 4);
		cost->rra--;
		count++;
	}
	while (cost->rb > 0)
	{
		rb(b);
		write(1, "rb\n", 3);
		cost->rb--;
		count++;
	}
}
void	execute_rra_rrb(t_cost *cost, t_stack **a, t_stack **b, int *count)
{
	while (cost->rra > 0 && cost->rrb > 0)
	{
		rrr(a, b);
		write(1, "rrr\n", 4);
		cost->rra--;
		cost->rrb--;
		count++;
	}
	while (cost->rra > 0)
	{
		rra(a);
		write(1, "rra\n", 4);
		cost->rra--;
		count++;
	}
	while (cost->rrb > 0)
	{
		rrb(b);
		write(1, "rrb\n", 4);
		cost->rrb--;
		count++;
	}
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
		execute_ra_rb(&cost, a, b, &count);
	else if (cost.ra <= cost.rra && cost.rb >= cost.rrb)
		execute_ra_rrb(&cost, a, b, &count);
	else if (cost.ra >= cost.rra && cost.rb <= cost.rrb)
		execute_rra_rb(&cost, a, b, &count);
	else if (cost.ra >= cost.rra && cost.rb >= cost.rrb)
		execute_rra_rrb(&cost, a, b, &count);
	pb(a, b);
	count++;
	printf("stack b after pushing : ");
	print_stack(*b);
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
			rb(b);
			index--;
			count++;
			write(1, "rb\n", 3);
		}
	}
	else if (index > (size / 2))
	{
		index = size - index;
		while (index > 0)
		{
			rrb(b);
			index--;
			count++;
			write(1, "rrb\n", 4);
		}
	}
	return (count);
}
int	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tail;
	t_stack	*current_a;
	int		count;
	int		max;

	tail = *a;
	current_a = *a;
	count = 0;
	max = ft_max(*a);
	while (tail->next)
		tail = tail->next;
	if ((*b)->content < (*a)->content && (*b)->content < tail->content)
	{
		pa(a, b);
		count += 1;
	}
	else if ((*b)->content > (*a)->content && (*b)->content > tail->content)
	{
		pa(a, b);
		ra(a);
		count += 2;
	}
	else if ((*b)->content > (*a)->content && (*b)->content < tail->content)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
		count += 3;
	}
	return (count);
}
void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	int count = 0; // NE PAS OUBLIER DENLEVER
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
	while ((*b))
	{
		count += push_back_to_a(a, b);
	}
	printf("\nNombres de coups : %d\n", count);
	print_stack(*a);
}
