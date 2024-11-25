/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:39:16 by lguiet            #+#    #+#             */
/*   Updated: 2024/11/25 17:44:32 by lguiet           ###   ########.fr       */
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
void	sa(t_list **a)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next; // save pointeur du 2e noeud
		(*a)->next = tmp->next;
		// 1er noeud saute 2e noeud pour pointer directmnt vers 3e
		tmp->next = *a; // fait pointer 2e noeud vers 1er
		*a = tmp;       // met la tete de liste sur l'ex 2e noeud
	}
}
void	sb(t_list **b)
{
	t_list	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
}
void	ss(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	tmp = NULL;
	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*b && (*b)->next)
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
	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
}
void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*new_head;

	if (*a && (*a)->next)
	{
		new_head = (*a)->next;
		tmp = (*a);
		while ((*a)->next)
			*a = (*a)->next;
		tmp->next = NULL;
		(*a)->next = tmp;
		*a = new_head;
	}
}
void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*new_head;

	if (*b && (*b)->next)
	{
		new_head = (*b)->next;
		tmp = (*b);
		while ((*b)->next)
			*b = (*b)->next;
		tmp->next = NULL;
		(*b)->next = tmp;
		*b = new_head;
	}
}
void	rr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*new_head;

	if (*a && (*a)->next)
	{
		new_head = (*a)->next;
		tmp = (*a);
		while ((*a)->next)
			*a = (*a)->next;
		tmp->next = NULL;
		(*a)->next = tmp;
		*a = new_head;
	}
	if (*b && (*b)->next)
	{
		new_head = (*b)->next;
		tmp = (*b);
		while ((*b)->next)
			*b = (*b)->next;
		tmp->next = NULL;
		(*b)->next = tmp;
		*b = new_head;
	}
}

// void(t_list **a, int mode) mode = 0 A, mode = 1 stack b,
// 							mode = 2 les 2

// 	void rrr(t_list * *a, t_list **b)
// {
// 	reverse_rotate(a);
// 	reverse_rotate(b);
// }

void	reverse_rotate(t_list **a)
{
	t_list	*tmp;
	t_list	*prev;

	if (!a)
		return ;
	tmp = *a;
	if (!tmp && !tmp->next)
		return ;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a;
	prev->next = NULL;
	*a = tmp;
	// t_list	*tmp2;
	// {
	// 	sec_node = (*a)->next;
	// 	tmp = (*a);
	// 	while (tmp->next)
	// 		tmp = tmp->next;
	// 	*a = tmp;
	// 	(*a)->next = sec_node;
	// }
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
