/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:39:48 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/05 14:26:07 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *ar, int size, int h)
{
	int tmp;
	int b;
	int i;

	if (h == 1)
		write(1, "ra\n", 3);
	else if (h == 2)
		write(1, "rb\n", 3);
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

void	rotate_ab(t_ar *ar, int h)
{
	if (h == 1)
		write(1, "rr\n", 3);
	rotate(ar->a, ar->sizea, 0);
	rotate(ar->b, ar->sizeb, 0);
}

void	rrotate(int *ar, int size, int h)
{
	int tmp;
	int b;
	int i;

	if (h == 1)
		write(1, "rra\n", 4);
	else if (h == 2)
		write(1, "rrb\n", 4);
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

void	rrotate_ab(t_ar *ar, int h)
{
	if (h == 1)
		write(1, "rrr\n", 4);
	rrotate(ar->a, ar->sizea, 0);
	rrotate(ar->b, ar->sizeb, 0);
}
