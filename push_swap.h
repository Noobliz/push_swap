/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:03 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/19 15:27:57 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

void				sa(t_stack **stack);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a, int n);
void				rb(t_stack **b, int n);
void				rr(t_stack **a, t_stack **b, int n);
void				rra(t_stack **a, int n);
void				rrb(t_stack **b, int n);
void				rrr(t_stack **a, t_stack **b, int n);

void				init_struct(t_cost *data);
t_stack				*create_node(int value);
void				add_node(t_stack **stack, int value);
void				n_lstclear(t_stack **lst);
void				free_char_array(char **array);
long				upgraded_atol(const char *str);
int					stack_size(t_stack *stack);

int					check_empty(char **argv);
int					is_sign(char c);
int					is_sorted(t_stack *a);
int					calculate_total_length(int argc, char **argv);
int					over_min_max(long int result);
int					valid_param(char **argv);

int					not_duplicated(t_stack *a);
int					ft_too_long(char *nptr);
char				*ft_concat_arg(int argc, char **argv);
int					skip_whitespace_and_get_sign(const char *str, long *index);
long				parse_number(const char *str, long *index);
char				**parse_arguments(int argc, char **argv);
t_stack				*create_stack_from_args(char **args);

void				push_swap(t_stack **a, t_stack **b);

void				sort_upto_five(t_stack **a, t_stack **b, int size);
void				sort_three(t_stack **stack);
t_stack				*best_move(t_stack *a, t_stack *b);
t_cost				calculate_cost(t_stack *a, t_stack *b, int value);
int					value_index(t_stack *stack, int value);
void				execute_ra_rb(t_cost *cost, t_stack **a, t_stack **b);
void				execute_ra_rrb(t_cost *cost, t_stack **a, t_stack **b);
void				execute_rra_rb(t_cost *cost, t_stack **a, t_stack **b);
void				execute_rra_rrb(t_cost *cost, t_stack **a, t_stack **b);

int					max_op(int x, int y);
int					min_op(int x, int y);
int					ft_max(t_stack *stack);
int					ft_min(t_stack *stack);
int					find_smallest(t_stack *stack);
void				move_small_to_top(t_stack **stack, int pos);

#endif
