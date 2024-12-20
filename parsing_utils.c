/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:27:18 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:47:33 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	over_min_max(long int result)
{
	if ((result) > 2147483647 || (result) < -2147483648)
		return (0);
	return (1);
}

int	check_empty(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	if (!a)
		return (0);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	calculate_total_length(int argc, char **argv)
{
	int	i;
	int	total_len;

	i = 1;
	total_len = 0;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (total_len);
}
