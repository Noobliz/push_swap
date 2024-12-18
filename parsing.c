/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:36:38 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/16 15:37:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

int	duplicated_nb(t_stack *a)
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
				return (0);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_too_long(char *nptr)
{
	int	i;
	int	len;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		// Ignorer les espaces
		i++;
	if (nptr[i] == '-' || nptr[i] == '+') // Ignorer le signe
		i++;
	while (nptr[i] == '0') // Ignorer les zéros en début
		i++;
	len = 0;
	while (nptr[i + len]) // Compter la longueur réelle des chiffres
	{
		if (nptr[i + len] < '0' || nptr[i + len] > '9') // Caractère non valide
			return (0);
		len++;
	}
	if (len > 10) // Vérification si la longueur dépasse les limites
	{
		return (0);
	}
	return (1);
}

//_________________________________________________________concat all args ensemble

char	*ft_concat_arg(int argc, char **argv)
{
	int		i;
	char	*big_str;

	big_str = malloc(sizeof(char) * calculate_total_length(argc, argv) + 1);
	if (!big_str)
		return (NULL);
	big_str[0] = '\0'; // Initialisation pour `ft_strcat`
	i = 1;
	while (i < argc)
	{
		ft_strcat(big_str, argv[i]);
		ft_strcat(big_str, " ");
		i++;
	}
	if (ft_strlen(big_str) == 0)
	{
		free(big_str);
		return (NULL);
	}
	return (big_str);
}
//_________________________________________________________CHECK INT MAX MIN

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

long	parse_number(const char *str, long *index)
{
	long	result;

	result = 0;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (result);
}

long	upgraded_atol(const char *str)
{
	long	index;
	long	result;
	int		sign;

	index = 0;
	sign = skip_whitespace_and_get_sign(str, &index);
	result = parse_number(str, &index);
	return (result * sign);
}

char	**parse_arguments(int argc, char **argv)
{
	char	*concatenated;
	char	**conc_argv;

	concatenated = ft_concat_arg(argc, argv);
	if (!concatenated)
		return (NULL);
	conc_argv = ft_split(concatenated, ' ');
	free(concatenated);
	if (!conc_argv || !valid_param(conc_argv) || !check_empty(argv))
	{
		free_char_array(conc_argv);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (conc_argv);
}

t_stack	*create_stack_from_args(char **args)
{
	int		i;
	t_stack	*stack;
	long	value;

	stack = NULL;
	i = 0;
	while (args[i])
	{
		if (!ft_too_long(args[i]))
		{
			n_lstclear(&stack);
			write(2, "Error\n", 6);
			return (NULL);
		}
		value = upgraded_atol(args[i]);
		if (!over_min_max(value))
		{
			n_lstclear(&stack);
			write(2, "Error\n", 6);
			return (0);
		}
		add_node(&stack, value);
		i++;
	}
	if (!duplicated_nb(stack))
	{
		write(2, "Error\n", 6);
		n_lstclear(&stack);
		return (NULL);
	}
	return (stack);
}
