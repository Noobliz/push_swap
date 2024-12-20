/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:33:17 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 13:44:34 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

int	ft_too_long(char *nptr)
{
	int	i;
	int	len;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] == '0')
		i++;
	len = 0;
	while (nptr[i + len])
	{
		if (nptr[i + len] < '0' || nptr[i + len] > '9')
			return (0);
		len++;
	}
	if (len > 10)
		return (0);
	return (1);
}

int	valid_param(char **argv)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	while (argv[i])
	{
		digit = 0;
		j = 0;
		while (argv[i][j])
		{
			if ((is_sign(argv[i][j])) && (j > 0 && argv[i][j - 1] != ' '))
				return (0);
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
			if (ft_isdigit(argv[i][j]))
				digit++;
			j++;
		}
		if (digit == 0)
			return (0);
		i++;
	}
	return (1);
}

int	not_duplicated(t_stack *a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = a;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->content == tmp->content)
			{
				n_lstclear(&a);
				write(2, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}

int	skip_whitespace_and_get_sign(const char *str, long *index)
{
	int	sign;

	sign = 1;
	while (str[*index] == ' ' || (str[*index] >= 9 && str[*index] <= 13))
		(*index)++;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	if (!ft_isdigit(str[*index]))
		return (0);
	return (sign);
}
