/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:21:11 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:44:13 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	data->rra = 0;
	data->rrb = 0;
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
