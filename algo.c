/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:54 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/12 17:38:41 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
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
	int	max;

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
int	value_index(t_stack *stack, int value)
{
	int	index;

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
	return (-1); // si value pas trouvee
}
int	get_insert_position(t_stack *b, int value)
{
	int		pos;
	int		size;
	t_stack	*current;

	size = stack_size(b);
	current = b;
	pos = 1;
	if (!current)
		return (0); // si stack vide on insere a la pos 0
	// if (value < ft_min(b))
	// 	return (size);
	// // si value est plus petite que tous les elements on l'insere a la fin
	// if (value > ft_max(b))
	// 	return (0); // si plus grand que tout on insere au debut
	if (value > ft_max(b) || value < ft_min(b))
		return (value_index(b, ft_max(b)));
	while (current->next)
	{
		if (value < current->content && value > current->next->content)
			// si bonne position break
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
	cost.rra = size_a - cost.ra; // size - index
	cost.rb = get_insert_position(b, value);
	cost.rrb = size_b - cost.rb;
	cost.total_cost = min_op(max_op(cost.ra, cost.rb), max_op(cost.rra,
				cost.rrb));
	return (cost);
}
t_stack	*best_move(t_stack *a, t_stack *b)
{
	t_stack		*current;
	t_stack		*best;
	t_cost		cost;
	long int	best_cost;

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
