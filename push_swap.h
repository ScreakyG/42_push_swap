/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:24 by fgonzale          #+#    #+#             */
/*   Updated: 2023/02/01 23:21:41 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//Initialisation
t_stack		*fill_stack_numbers(int argc, char **argv);
void		assign_index(t_stack *stack_a, int stack_size);

//Sorting
int		is_sorted(t_stack *stack);
void	tiny_sort(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b);

//Position
void	get_target_position(t_stack **stack_a, t_stack **stack_b);

//Cost
void	get_cost(t_stack **stack_a, t_stack **stack_b);

//Operarations
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);

// Stack fonctions
int			get_stack_size(t_stack *stack_a);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*stack_new(int nb);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);

//Input check
int			is_correct_input(char **argv);
int			arg_is_number(char *argv);
int			check_doublons(char **argv);
int			nbstr_cmp(const char *argv1, const char *argv2);

//Utils
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *argv);
void		ft_putstr(char *str);
int			nb_abs(int nb);

//Error
void		exit_error(t_stack **stack_a, t_stack **stack_b);

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
int		get_lowest_index_position(t_stack **stack);
#endif
