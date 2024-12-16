/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:17:33 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/16 13:08:44 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char **conc_argv;
	t_stack *alpha;
	t_stack *beta;
	t_cost data;

	alpha = NULL;
	beta = NULL;
	init_struct(&data);
	if (argc > 1)
	{
		// Parsing du tableau
		conc_argv = parse_arguments(argc, argv);
		if (!conc_argv)
			return (0);
		// Parsing de la liste
		alpha = create_stack_from_args(conc_argv);
		free_char_array(conc_argv); // Libère `conc_argv` après son utilisation
		if (!alpha)
			return (0);
		if (is_sorted(alpha))
		{
			print_stack(alpha);
			n_lstclear(&alpha);
			return (0);
		}
		// while (argv[i])
		// 	{
		// 		add_node(&alpha, atoi(argv[i]));
		// 		i++;
		// 	}
		printf("avant\n");
		print_stack(alpha);

		push_swap(&alpha, &beta);
		// printf("\napres\n");
		// print_stack(alpha);
		n_lstclear(&alpha);
		n_lstclear(&beta);
		return (0);
	}
}