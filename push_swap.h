/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:03 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/17 13:28:17 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;
typedef struct s_cost
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				total_cost;

}					t_cost;
//-----------------------------------------OPERATORS
void				swap_top(t_stack **stack);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a, int n);
void				rb(t_stack **b, int n);
void				rr(t_stack **a, t_stack **b, int n);
void				rra(t_stack **a, int n);
void				rrb(t_stack **b, int n);
void				rrr(t_stack **a, t_stack **b, int n);

//-----------------------------------------UTILS
void				init_struct(t_cost *data);
t_stack				*create_node(int value);
void				add_node(t_stack **stack, int value);
void				print_stack(t_stack *stack);
void				n_lstclear(t_stack **lst);
void				free_char_array(char **array);
long				upgraded_atol(const char *str);
int					stack_size(t_stack *stack);
//--------------------------------------------------PARSING UTILS
int					check_empty(char **argv);
int					is_sign(char c);
int					is_sorted(t_stack *a);
int					calculate_total_length(int argc, char **argv);
int					over_min_max(long int result);
int					valid_param(char **argv);

//----------------------------------------------------PARSING
int					duplicated_nb(t_stack *a);
int					ft_too_long(char *nptr);
char				*ft_concat_arg(int argc, char **argv);
int					skip_whitespace_and_get_sign(const char *str, long *index);
long				parse_number(const char *str, long *index);
char				**parse_arguments(int argc, char **argv);
t_stack				*create_stack_from_args(char **args);
//-------------------------------------------------------------------ALGO
void				push_swap(t_stack **a, t_stack **b);
int					execute_best_move(t_stack **a, t_stack **b);
void				sort_upto_five(t_stack **a, t_stack **b, int size);
void				sort_three(t_stack **stack);
t_stack				*best_move(t_stack *a, t_stack *b);
t_cost				calculate_cost(t_stack *a, t_stack *b, int value);
int					get_insert_position(t_stack *b, int value);
int					value_index(t_stack *stack, int value);
//-------------------------------------------------------------------ALGO UTILS
int					max_op(int x, int y);
int					min_op(int x, int y);
int					ft_max(t_stack *stack);
int					ft_min(t_stack *stack);

#endif