/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:54 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/13 14:06:18 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

void	execute_best_move(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_cost	cost;

	init_struct(&cost);
	best = best_move(*a, *b);
	cost = calculate_cost(*a, *b, best->content);
	if (cost.ra < cost.rra || cost.rb < cost.rrb)
	{
		while (cost.ra > 0 && cost.rb > 0)
		{
			rr(a, b);
			write(1, "rr\n", 3);
			cost.ra--;
			cost.rb--;
		}
		while (cost.ra > 0)
		{
			ra(a);
			write(1, "ra\n", 3);
			cost.ra--;
		}
		while (cost.rb > 0)
		{
			rb(b);
			write(1, "rb\n", 3);
			cost.rb--;
		}
	}
	else
	{
		while (cost.rra > 0 && cost.rrb > 0)
		{
			rrr(a, b);
			write(1, "rrr\n", 4);
			cost.rra--;
			cost.rrb--;
		}
		while (cost.rra > 0)
		{
			rra(a);
			write(1, "rra\n", 4);
			cost.rra--;
		}
		while (cost.rrb > 0)
		{
			rrb(a);
			write(1, "rrb\n", 4);
			cost.rrb--;
		}
	}
	pb(a, b);
}
void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	pb(a, b);
	pb(a, b);
	if (is_sorted(*b))
		swap_top(b);
	while (size_a > 5)
	{
		execute_best_move(a, b);
		size_a--;
	}
	printf("stack b :");
	print_stack(*b);
	sort_three(a);
	// while (*b)
	// {
	// 	pa(a, b);
	// }
}
