/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:27:38 by fgonzale          #+#    #+#             */
/*   Updated: 2023/02/01 22:10:01 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free la stack envoyee en parametre.
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}


//Free les stacks 'a' et 'b' et ecrit "Error" sur le standart output.
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

// Converti un char string en un long int.
long int	ft_atoi(const char *argv)
{
	int				i;
	int				signe;
	long int		resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			signe *= -1;
		i++;
	}
	while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
	{
		resultat = (resultat * 10) + (argv[i] - '0');
		i++;
	}
	return (resultat * signe);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb *= -1);
	return (nb);
}
