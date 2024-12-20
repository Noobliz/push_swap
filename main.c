/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:17:33 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 14:29:09 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(t_stack *alpha)
{
	if (!not_duplicated(alpha))
		return (0);
	if (is_sorted(alpha))
	{
		n_lstclear(&alpha);
		return (0);
	}
	return (1);
}

static void	clear_all(t_stack **alpha, t_stack **beta)
{
	n_lstclear(alpha);
	n_lstclear(beta);
}

static void	sort_to_five_and_clear(t_stack **alpha, t_stack **beta, int size)
{
	sort_upto_five(alpha, beta, size);
	clear_all(alpha, beta);
}

int	main(int argc, char **argv)
{
	char	**conc_argv;
	t_stack	*alpha;
	t_stack	*beta;
	int		size;

	alpha = NULL;
	beta = NULL;
	if (argc < 2)
		return (0);
	conc_argv = parse_arguments(argc, argv);
	if (!conc_argv)
		return (0);
	alpha = create_stack_from_args(conc_argv);
	free_char_array(conc_argv);
	if (!alpha || !is_valid(alpha))
		return (0);
	size = stack_size(alpha);
	if (size < 6)
	{
		sort_to_five_and_clear(&alpha, &beta, size);
		return (0);
	}
	push_swap(&alpha, &beta);
	clear_all(&alpha, &beta);
	return (0);
}
