/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:58:38 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/30 23:00:01 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Parcours la stack et recherche le plus gros index qui
correspond donc au plus gros nombre.
*/
static int	find_highest_number(t_stack *stack)
{
	int	highest_index;

	highest_index = stack->index;
	while(stack)
	{
		if (stack->index > highest_index)
			highest_index = stack->index;
		stack = stack->next;
	}
	return (highest_index);
}

/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_stack **stack_a)
{
	int	highest_number;

	highest_number = find_highest_number(*stack_a);
	if ((*stack_a)->index == highest_number)
		do_ra(stack_a);
	else if ((*stack_a)->next->index == highest_number)
		do_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}
