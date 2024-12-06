/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:00:52 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/06 17:05:43 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

int	over_min_max(long int result, int sign)
{
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		return (1);
}

long	upgraded_atol(const char *str)
{
	int			sign;
	long int	i;
	long int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (over_min_max(result, sign) == 0)
		return (0);
	return (result * sign);
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
		printf("%ld -> ", stack->content);
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
