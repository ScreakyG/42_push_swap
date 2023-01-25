/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:43:23 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/25 23:03:36 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* nbstr_cmp:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
int	nbstr_cmp(const char *argv1, const char *argv2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = i;

	if (argv1[i] == '+')
	{
		if (argv2[j] != '+')
			i++;
	}
	else
	{
		if (argv2[j] == '+')
			j++;
	}
	while (argv1[i] && argv2[j] && argv1[i] == argv2[j])
	{
		i++;
		j++;
	}
	return (argv1[i] - argv2[j]);
}
