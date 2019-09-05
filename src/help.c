/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:36:41 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/05 15:39:52 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Get average element
*/

int	get_avg(int *a, int size)
{
	double	count;
	int		i;

	i = 0;
	count = 0;
	while (i < size)
		count += a[i++];
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
		index = b[size] < b[index] ? size : index;
	return (index);
}

/*
** Get 3 maximum element
*/

int	*get_maxs(int *ar, int size, int *max)
{
	int i;

	i = 1;
	max[0] = ar[0];
	max[1] = ar[get_min(ar, size)];
	max[2] = max[1];
	while (i < size)
	{
		if (max[0] < ar[i])
		{
			max[2] = max[1];
			max[1] = max[0];
			max[0] = ar[i];
		}
		else if (max[1] < ar[i])
		{
			max[2] = max[1];
			max[1] = ar[i];
		}
		else if (max[2] < ar[i])
			max[2] = ar[i];
		i++;
	}
	return (max);
}
