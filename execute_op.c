/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:24:13 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:48:03 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_ra_rb(t_cost *cost, t_stack **a, t_stack **b)
{
	while (cost->ra > 0 && cost->rb > 0)
	{
		rr(a, b, 1);
		cost->ra--;
		cost->rb--;
	}
	while (cost->ra > 0)
	{
		ra(a, 0);
		cost->ra--;
	}
	while (cost->rb > 0)
	{
		rb(b, 0);
		cost->rb--;
	}
}

void	execute_ra_rrb(t_cost *cost, t_stack **a, t_stack **b)
{
	while (cost->ra > 0)
	{
		ra(a, 0);
		cost->ra--;
	}
	while (cost->rrb > 0)
	{
		rrb(b, 0);
		cost->rrb--;
	}
}

void	execute_rra_rb(t_cost *cost, t_stack **a, t_stack **b)
{
	while (cost->rra > 0)
	{
		rra(a, 0);
		cost->rra--;
	}
	while (cost->rb > 0)
	{
		rb(b, 0);
		cost->rb--;
	}
}

void	execute_rra_rrb(t_cost *cost, t_stack **a, t_stack **b)
{
	while (cost->rra > 0 && cost->rrb > 0)
	{
		rrr(a, b, 1);
		cost->rra--;
		cost->rrb--;
	}
	while (cost->rra > 0)
	{
		rra(a, 0);
		cost->rra--;
	}
	while (cost->rrb > 0)
	{
		rrb(b, 0);
		cost->rrb--;
	}
}
