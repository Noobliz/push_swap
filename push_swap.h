/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:03 by lguiet            #+#    #+#             */
/*   Updated: 2024/12/12 16:20:57 by lguiet           ###   ########.fr       */
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
void				free_char_array(char **array);
long				upgraded_atol(const char *str);
int					stack_size(t_stack *stack);
//--------------------------------------------------PARSING
int					valid_param(char **argv);
int					is_sign(char c);
int					check_empty(char **argv);
int					duplicated_nb(t_stack *a);
int					ft_too_long(char *nptr);
int					is_sorted(t_stack *a);
char				*ft_concat_arg(int argc, char **argv);
int					calculate_total_length(int argc, char **argv);
int					over_min_max(long int result, int sign);
int					skip_whitespace_and_get_sign(const char *str, long *index);
long				parse_number(const char *str, long *index);
char				**parse_arguments(int argc, char **argv);
t_stack				*create_stack_from_args(char **args);
//-------------------------------------------------------------------ALGO
typedef struct s_cost
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	long int		total_cost;

}					t_cost;
void				push_swap(t_stack **a, t_stack **b);
void				execute_best_move(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
t_stack				*best_move(t_stack *a, t_stack *b);
t_cost				calculate_cost(t_stack *a, t_stack *b, int value);
int					get_insert_position(t_stack *b, int value);
int					value_index(t_stack *stack, int value);

int					max_op(int x, int y);
int					min_op(int x, int y);
void				init_struct(t_cost *data);
#endif