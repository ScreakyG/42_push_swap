/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:54:51 by fgonzale          #+#    #+#             */
/*   Updated: 2023/02/01 01:52:01 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Calcul le cout dans cost_b pour remonter l'element au sommet de la stack b.
	Calcul le cout dans cost_a pour positioner l'element B dans la stack a.

	Si l'element se trouve a plus de la moitie de la pile on le passe en negative (pour utiliser les reverses moves).
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while(tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->cost_b > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	int	cheapest;
	int	cost_a;
	int	cost_b;

	tmp = *stack_b;
	while(tmp)
	{

	}
}
