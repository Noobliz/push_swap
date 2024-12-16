/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:54 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/16 12:51:06 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_best_move(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_cost	cost;

	int count = 0; // NE PAS OUBLIER DENLEVER
	init_struct(&cost);
	best = best_move(*a, *b);
	cost = calculate_cost(*a, *b, best->content);
	printf("the value considered the best is : %d\n", best->content);
	printf("it's cost is : \n");
	printf("ra = %d\n", cost.ra);
	printf("rb = %d\n", cost.rb);
	printf("rra = %d\n", cost.rra);
	printf("rrb = %d\n", cost.rrb);
	if (cost.ra <= cost.rra && cost.rb <= cost.rrb)
	{
		while (cost.ra > 0 && cost.rb > 0)
		{
			rr(a, b);
			write(1, "rr\n", 3);
			cost.ra--;
			cost.rb--;
			count++;
		}
		while (cost.ra > 0)
		{
			ra(a);
			write(1, "ra\n", 3);
			cost.ra--;
			count++;
		}
		while (cost.rb > 0)
		{
			rb(b);
			write(1, "rb\n", 3);
			cost.rb--;
			count++;
		}
	}
	else if (cost.ra <= cost.rra && cost.rb >= cost.rrb)
	{
		while (cost.ra > 0)
		{
			ra(a);
			write(1, "ra\n", 3);
			cost.ra--;
			count++;
		}
		while (cost.rrb > 0)
		{
			rrb(b);
			write(1, "rrb\n", 4);
			cost.rrb--;
			count++;
		}
	}
	else if (cost.ra >= cost.rra && cost.rb <= cost.rrb)
	{
		while (cost.rra > 0)
		{
			rra(a);
			write(1, "rra\n", 4);
			cost.rra--;
			count++;
		}
		while (cost.rb > 0)
		{
			rb(b);
			write(1, "rb\n", 3);
			cost.rb--;
			count++;
		}
	}
	else if (cost.ra >= cost.rra && cost.rb >= cost.rrb)
	{
		while (cost.rra > 0 && cost.rrb > 0)
		{
			rrr(a, b);
			write(1, "rrr\n", 4);
			cost.rra--;
			cost.rrb--;
			count++;
		}
		while (cost.rra > 0)
		{
			rra(a);
			write(1, "rra\n", 4);
			cost.rra--;
			count++;
		}
		while (cost.rrb > 0)
		{
			rrb(b);
			write(1, "rrb\n", 4);
			cost.rrb--;
			count++;
		}
	}
	pb(a, b);
	count++;
	printf("stack b after pushing : ");
	print_stack(*b);
	return (count);
}
void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	int count = 2; // NE PAS OUBLIER DENLEVER
	size_a = stack_size(*a);
	pb(a, b);
	pb(a, b);
	printf("stack b after the two first push: ");
	print_stack(*b);
	while (size_a > 2)
	{
		count += execute_best_move(a, b);
		size_a--;
	}
	printf("count = %d\n", count);
	printf("stack b :");
	print_stack(*b);
	sort_three(a);
	// while (*b)
	// {
	// 	pa(a, b);
	// }
}
