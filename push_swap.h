/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:03 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/06 16:16:21 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long int		content;
	struct s_stack	*next;
}					t_stack;
//-----------------------------------------OPERATORS
void				swap_top(t_stack **stack);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

//-----------------------------------------UTILS
t_stack				*create_node(int value);
void				add_node(t_stack **stack, int value);
void				print_stack(t_stack *stack);
void				n_lstclear(t_stack **lst);
long				upgraded_atol(const char *str);
//--------------------------------------------------PARSING
int					valid_param(char **argv);
int					duplicated_nb(t_stack *a);
int					ft_too_long(char *nptr);
int					is_sorted(t_stack *a);
char				*ft_concat_arg(int argc, char **argv);

#endif