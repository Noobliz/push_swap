/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:26:10 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:46:25 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ra(stack, 0);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(stack, 0);
			pos--;
		}
	}
}
