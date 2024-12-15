/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:00:52 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/13 19:05:42 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}
void	add_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

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
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}
void	n_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst));
		*lst = temp;
	}
}
void	init_struct(t_cost *data)
{
	data->ra = 0;
	data->rb = 0;
	data->rr = 0;
	data->rra = 0;
	data->rrb = 0;
	data->rrr = 0;
	data->total_cost = 0;
}
void	free_char_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
