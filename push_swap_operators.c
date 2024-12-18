/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:22 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/17 12:26:48 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next; // save pointeur du 2e noeud
		(*stack)->next = tmp->next;
		// 1er noeud saute 2e noeud pour pointer directmnt vers 3e
		tmp->next = *stack; // fait pointer 2e noeud vers 1er
		*stack = tmp;       // met la tete de liste sur l'ex 2e noeud
	}
	write(1, "sa\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top(a);
	swap_top(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = (*b)->next; // save future nouvelle tete
		(*b)->next = *a;  // fait pointer next de b vers l'ancienne tete de a
		*a = *b;          // new tete de a
		*b = tmp;         // new tete de b
	}
	write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	write(1, "pb\n", 3);
}
void	ra(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (*a && (*a)->next)
	{
		new_head = (*a)->next;
		tmp = (*a);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;    // attache l'ancienne tete à la fin
		(*a)->next = NULL; // coupe le lien
		*a = new_head;
	}
	if (n == 0)
		write(1, "ra\n", 3);
}
void	rb(t_stack **b, int n)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (*b && (*b)->next)
	{
		new_head = (*b)->next;
		tmp = (*b);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;    // attache l'ancienne tete à la fin
		(*b)->next = NULL; // coupe le lien
		*b = new_head;
	}
	if (n == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int n)
{
	ra(a, 1);
	rb(b, 1);
	if (n == 1)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a;
	prev->next = NULL;
	*a = tmp;
	if (n == 0)
		write(1, "rra\n", 4);
}
void	rrb(t_stack **b, int n)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *b;
	prev->next = NULL;
	*b = tmp;
	if (n == 0)
		write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b, int n)
{
	rra(a, 1);
	rrb(b, 1);
	if (n == 1)
		write(1, "rrr\n", 4);
}