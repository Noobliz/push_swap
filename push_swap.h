/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:03 by lguiet            #+#    #+#             */
/*   Updated: 2024/11/28 16:28:26 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;
//-----------------------------------------OPERATORS
void				swap_top(t_list **stack);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				rotate(t_list **stack);
void				rr(t_list **a, t_list **b);
void				reverse_rotate(t_list **stack);
void				rrr(t_list **a, t_list **b);

//-----------------------------------------UTILS
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
t_list				*create_node(int value);
void				add_node(t_list **stack, int value);
void				print_stack(t_list *stack);

#endif