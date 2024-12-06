/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:36:38 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/06 16:38:10 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

int	valid_param(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			while (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (j > 0 && argv[i][j - 1] != ' ')
				{
					write(1, "Error\n", 6);
					return (0);
				}
				j++;
			}
			if (argv[i][j] != ' ' && !(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
int	duplicated_nb(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*current;

	current = a;
	tmp = current->next;
	while (current)
	{
		while (tmp)
		{
			if (current->content == tmp->content)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		current = current->next;
		if (current->next == NULL)
			break ;
		tmp = current->next;
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
int	ft_too_long(char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		i++;
		if ((nptr[0] != '-' && i > 10) || (nptr[0] == '-' && i > 11))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

//_________________________________________________________concat all args ensemble
char	*ft_concat_arg(int argc, char **argv)
{
	int		i;
	int		j;
	int		l;
	int		digit;
	char	*big_str;

	i = 1;
	j = 0;
	l = 0;
	digit = 0;
	while (argv[i])
	{
		l += ft_strlen(argv[i]);
		i++;
	}
	big_str = malloc(sizeof(char) * (l + argc));
	i = 1;
	while (argv[i])
	{
		digit = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				digit++;
			}
			j++;
		}
		i++;
	}
	if (digit == 0)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		big_str = ft_strcat(big_str, argv[i]);
		big_str = ft_strcat(big_str, " ");
		i++;
	}
	i = 0;
	printf("big_str= %s\n", big_str);
	return (big_str);
}
