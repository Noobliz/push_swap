/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:02:39 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/13 14:04:38 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_op(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}
int	max_op(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
int	ft_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
		}
		stack = stack->next;
	}
	return (min);
}
int	ft_max(t_stack *stack)
{
	int max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
		}
		stack = stack->next;
	}
	return (max);
}