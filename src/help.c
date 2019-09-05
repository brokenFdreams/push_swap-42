/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:36:41 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/05 12:17:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Get average element
*/

int	get_avg(int *a, int size)
{
	double count;
	int i;

	count = 0;
	while (i < size)
		count += a[i];
	return ((int)(count / size + 0.5));
}

/*
** Finding index of minumun element
*/

int	get_min(int *b, int size)
{
	int index;

	index = 0;
	while (--size > 0)
		index = ar->b[size] < ar->b[index] ? size : index;
	return (index);
}
