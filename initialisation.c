/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:08:18 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/26 23:53:11 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rempli la stack_a avec les nombres, verifie egalement si les nombres ne sont pas en dehors de l'int max et min.
t_stack	*fill_stack_numbers(int argc, char **argv)
{
	t_stack	*stack_a;
	unsigned int	i;
	long	nb;

	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i = 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* assign_index:
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		number;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		number = INT_MIN;
		highest = NULL;
		while(ptr)
		{
			if (ptr->number == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->number > number && ptr->index == 0)
			{
				number = ptr->number;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			ptr->index = stack_size;
	}
}
