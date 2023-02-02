/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:24:19 by fgonzale          #+#    #+#             */
/*   Updated: 2023/02/02 00:47:09 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack_a, stack_b);
	}
}

static void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stack_a, stack_b);
	}
}

static void rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			do_rra(stack_a);
			(*cost_a)++;
		}
	}
}

static void rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(stack_b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}
