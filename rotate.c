/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:47:22 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/30 23:04:29 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Decale la position des elements d'une case vers le haut,
	le premier element deviens le dernier.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *stack;
	*stack = (*stack)->next;
	bottom = get_stack_bottom(*stack);
	tmp->next = NULL;
	bottom->next = tmp;
}

/*
	Envoi le premier element de la stack A en derniere position.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*
	Envoi le premier element de la stack B en derniere position.
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("ra\n");
}

/*
	Envoi le premier element de la stack A en derniere position.
	Envoi le premier element de la stack B en derniere position.
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
