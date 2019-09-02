/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:06:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/02 11:46:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findindexmax(int *b, int size, int max)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (b[i] == max)
			return (i);
		i++;
	}
	return (-1);
}

/*
** looking for new max
*/

int	findnewmax(t_ar *ar)
{
	int i;
	int max;

	i = 0;
	while ((max = ar->b[i]) >= ar->max[4])
		i++;
	while (i < ar->sizeb)
	{
		if (max < ar->b[i] && ar->b[i] < ar->max[4])
			max = ar->b[i];
		i++;
	}
	return (max);
}
