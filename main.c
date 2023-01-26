/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:10 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/26 23:36:43 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!is_correct_input(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_numbers(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
}
