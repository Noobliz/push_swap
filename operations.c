/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:39:16 by lguiet            #+#    #+#             */
/*   Updated: 2024/11/26 10:22:07 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*create_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}
void	add_node(t_list **stack, int value)
{
	t_list	*new_node;
	t_list	*last;

	last = NULL;
	new_node = create_node(value);
	if (!*stack)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}
void	swap_top(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next; // save pointeur du 2e noeud
		(*stack)->next = tmp->next;
		// 1er noeud saute 2e noeud pour pointer directmnt vers 3e
		tmp->next = *stack; // fait pointer 2e noeud vers 1er
		*stack = tmp;       // met la tete de liste sur l'ex 2e noeud
	}
}

void	ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = (*b)->next; // save future nouvelle tete
		(*b)->next = *a;  // fait pointer next de b vers l'ancienne tete de a
		*a = *b;          // new tete de a
		*b = tmp;         // new tete de b
	}
}
void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
}
void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_head;

	if (*stack && (*stack)->next)
	{
		new_head = (*stack)->next;
		tmp = (*stack);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack; //attache l'ancienne tete à la fin
		(*stack)->next = NULL; // coupe le lien
		*stack = new_head;
	}
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}


void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*prev;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	prev->next = NULL;
	*stack = tmp;
}
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}
//__________________________________________________TEST PA/PB
// int	main(void)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	// STACK A
// 	add_node(&stack_a, 5);
// 	add_node(&stack_a, 2);
// 	add_node(&stack_a, 10);
// 	add_node(&stack_a, 11);
// 	// STACK B
// 	add_node(&stack_b, 54);
// 	add_node(&stack_b, 666);
// 	add_node(&stack_b, 154);
// 	add_node(&stack_b, -2);
// 	printf("stack_a avant pa : \n");
// 	print_stack(stack_a);
// 	printf("stack_b avant pa : \n");
// 	print_stack(stack_b);
// 	// USE OF PA/PB
// 	pa(&stack_a, &stack_b);
// 	printf("stack_a apres pa : \n");
// 	print_stack(stack_a);
// 	printf("stack_b apres pa : \n");
// 	print_stack(stack_b);
// 	return (0);
// }
//________________________________________________________ TEST SS
// int	main(void)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;

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
int	main(void)
{
	t_list	*stack_a;

	stack_a = NULL;
	add_node(&stack_a, 5);
	add_node(&stack_a, 2);
	add_node(&stack_a, 10);
	add_node(&stack_a, 554);
	add_node(&stack_a, -4578);
	add_node(&stack_a, 10);
	printf("stack_a avant rra : \n");
	print_stack(stack_a);
	rra(&stack_a);
	printf("stack_a apres rra : \n");
	print_stack(stack_a);
	return (0);
}
