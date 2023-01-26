/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:24 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/27 00:08:04 by fgonzale         ###   ########.fr       */
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

// Stack fonctions
int			get_stack_size(stack_a);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*stack_new(int nb);
t_stack		*get_stack_bottom(t_stack *stack);

//Input check
int			is_correct_intput(char **argv);
int			arg_is_number(char *argv);
int			check_doublons(char **argv);
int			nbstr_cmp(const char *argv1, const char *argv2);

//Utils
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *argv);

//Error
void		exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
