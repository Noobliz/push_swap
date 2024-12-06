/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:39:16 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/06 17:25:34 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	if (!(*stack && (*stack)->next && (*stack)->next->next))
		return ;
	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	while (!(first < second && second < third))
	{
		first = (*stack)->content;
		second = (*stack)->next->content;
		third = (*stack)->next->next->content;
		if (first > second && first > third)
			ra(stack);
		if (first < second && second > third)
		{
			swap_top(stack);
			ra(stack);
		}
		if (first > second && second < third)
			swap_top(stack);
	}
}
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
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(stack);
			pos--;
		}
	}
}
void	sort_four(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_smallest(*a);
	move_small_to_top(a, pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}
void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_smallest(*a);
	move_small_to_top(a, pos);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_upto_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	if (size == 5)
		sort_five(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 3)
		sort_three(a);
	else
	{
		pos = find_smallest(*a);
		move_small_to_top(a, pos);
	}
}
void	free_conc(char **s1, int x)
{
	while (x >= 0)
	{
		free(s1[x]);
		x--;
	}
	free(s1);
}
int	main(int argc, char **argv)
{
	int		i;
	char	**conc_argv;
	t_stack	*alpha;
	t_stack	*beta;
	int		x;

	x = 0;
	i = 0;
	alpha = NULL;
	beta = NULL;
	conc_argv = ft_split(ft_concat_arg(argc, argv), ' ');
	// if (!(conc_argv))
	// {
	// 	write(1, "Error\n", 6);
	// 	return (0);
	// }
	i = 0;
	while (conc_argv[x])
	{
		printf("argument %d : %s\n", x, conc_argv[x]);
		x++;
	}
	if (argc > 1)
	{
		if (valid_param(conc_argv) == 0)
			return (0);
		while (conc_argv[i])
		{
			if (!(ft_too_long(conc_argv[i]) == 1))
				return (0);
			if (upgraded_atol(conc_argv[i]) == 0)
				return (0);
			add_node(&alpha, upgraded_atol(conc_argv[i]));
			i++;
		}
		if (!(duplicated_nb(alpha)))
			return (0);
		if (is_sorted(alpha))
		{
			print_stack(alpha);
			return (0);
		}
		printf("avant\n");
		print_stack(alpha);
		sort_upto_five(&alpha, &beta, i);
		printf("\napres\n");
		print_stack(alpha);
		n_lstclear(&alpha);
		n_lstclear(&beta);
	}
}
//________________________________________TEST SORT_THREE
// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*b;
// 	int		i;
// 	int		*arr;
// 	int		j;

// 	if (argc > 1)
// 	{
// 		if (argc == 1)t_stack
// 			return (0);
// 		if (!(valid_param(argv) == 1))
// 			return (0);
// 		b = NULL;
// 		stack_a = NULL;
// 		i = 1;
// 		while (argv[i])
// 		{
// 			add_node(&stack_a, ft_atoi(argv[i]));
// 			i++;
// 		}
// 		if (!(duplicated_nb(stack_a) == 1))
// 			return (0);
// 		if (is_sorted(stack_a) == 1)
// 		{
// 			printf("is sorted\n");
// 			print_stack(stack_a);
// 			n_lstclear(&stack_a);
// 			return (0);
// 		}
// 		// if (!(not_overflow(stack_a) == 1))
// 		// 	return (0);
// 		i = i - 1;
// 		printf("stack_a before sorting :\n");
// 		print_stack(stack_a);
// 		sort_upto_five(&stack_a, &b, i);
// 		printf("stack_a after sorting :\n");
// 		print_stack(stack_a);
// 		n_lstclear(&stack_a);
// 		n_lstclear(&b);
// 		stack_a = NULL;
// 		b = NULL;
// 	}
// 	return (0);
// }
//__________________________________________________TEST PA/PB
// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	// STACK A
// 	add_node(&stack_a, 5);
// 	add_node(&stack_a, 2);
// 	add_node(&stack_a, 10);
// 	add_node(&stack_a, 11);
// 	// STACK B
// 	// add_node(&stack_b, 54);
// 	// add_node(&stack_b, 666);
// 	// add_node(&stack_b, 154);
// 	// add_node(&stack_b, -2);
// 	printf("stack_a avant rrr : \n");
// 	print_stack(stack_a);
// 	printf("stack_b avant rrr : \n");
// 	print_stack(stack_b);
// 	// USE OF PA/PB
// 	pb(&stack_a, &stack_b);
// 	printf("stack_a apres rrr : \n");
// 	print_stack(stack_a);
// 	printf("stack_b apres rrr : \n");
// 	print_stack(stack_b);
// 	return (0);
// }
//________________________________________________________ TEST SS
// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	add_node(&stack_a, 5);
// 	add_node(&stack_a, 2);
// 	add_node(&stack_a, 10);
// 	add_node(&stack_b, 54);
// 	add_node(&stack_b, 666);
// 	add_node(&stack_b, 154);
// 	printf("stack_a avant ss : \n");
// 	print_stack(stack_a);
// 	printf("stack_b avant ss : \n");
// 	print_stack(stack_b);
// 	ss(&stack_a, &stack_b);
// 	printf("stack_a apres ss : \n");
// 	print_stack(stack_a);
// 	printf("stack_b apres ss : \n");
// 	print_stack(stack_b);
// 	return (0);
// }
//______________________________________________________ TEST SA/RA
// int	main(void)
// {
// 	t_stack	*stack_a;

// 	stack_a = NULL;
// 	add_node(&stack_a, 5);
// 	add_node(&stack_a, 2);
// 	add_node(&stack_a, 10);
// 	add_node(&stack_a, 554);
// 	add_node(&stack_a, -4578);
// 	add_node(&stack_a, 10);
// 	printf("stack_a avant rra : \n");
// 	print_stack(stack_a);
// 	rra(&stack_a);
// 	printf("stack_a apres rra : \n");
// 	print_stack(stack_a);
// 	return (0);
// }
