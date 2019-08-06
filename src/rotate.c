/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:39:48 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 16:00:58 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *ar, int size)
{
	int tmp;
	int b;
	int i;

	if (size > 1)
	{
		b = ar[size - 1];
		ar[size - 1] = ar[0];
		i = size - 2;
		while (i >= 0)
		{
			tmp = ar[i];
			ar[i] = b;
			b = tmp;
			i--;
		}
	}
}

void	rotate_ab(t_ar *ar)
{
	rotate(ar->a, ar->sizea);
	rotate(ar->b, ar->sizeb);
}

void	rrotate(int *ar, int size)
{
	int tmp;
	int b;
	int i;

	if (size > 1)
	{
		b = ar[0];
		ar[0] = ar[size - 1];
		i = 1;
		while (i < size)
		{
			tmp = ar[i];
			ar[i] = b;
			b = tmp;
			i++;
		}
	}
}

void	rrotate_ab(t_ar *ar)
{
	rrotate(ar->a, ar->sizea);
	rrotate(ar->b, ar->sizeb);
}
