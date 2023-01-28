/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:41:29 by fgonzale          #+#    #+#             */
/*   Updated: 2023/01/28 06:02:25 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Regarde si l'argument contient un signe '-' ou '+' , ensuite verifie si l'argument de contient que des chiffres.
int	arg_is_number(char *argv)
{
	unsigned int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1] != '\0')
		i++;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//Compare chaques arguments dans la fonction nbstr_cmp pour trouver si il y a des doublons. Si nbstr renvoie 0 cela veut dire que c'est un doublon.
int	check_doublons(char **argv)
{
	unsigned int 	i;
	unsigned int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
	Check si les arguments sont bien des nombres , et qu'il y a pas de doublons.
	Return 1 si les arguments sont valides , autrement 0.
*/
int	is_correct_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!arg_is_number(argv[i]))
			return (0);
		i++;
	}
	if (check_doublons(argv) == 1)
		return (0);
	return (1);
}
