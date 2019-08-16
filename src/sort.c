/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:40:51 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/16 15:44:35 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_ar *ar)
{
	if (ar->b[0] == ar->max[3] || issorted(ar->b, ar->sizeb, 'b'))
		return ;
	if ((ar->b[0] < ar->b[1] && ar->b[0] < ar->b[ar->sizeb - 1] &&
		ar->b[0] < ar->b[2]) || ar->b[0] < (ar->max[5] - ar->sizeb / 10))
	{
		if (ar->a[0] > ar->a[1] && ar->a[0] > ar->a[2]
			&& ar->a[0] > ar->a[ar->sizea - 1])
			rotate_ab(ar, 1);
		else
			rotate(ar->b, ar->sizeb, 2);
	}
	if (ar->b[0] < ar->b[1] && ar->b[0] > ar->b[ar->sizeb - 1])
	{
		if (ar->a[0] > ar->a[1] && ar->a[0] < ar->a[ar->sizea - 1])
			swap_ab(ar, 1);
		else
			swap(ar->b, ar->sizeb, 2);
	}
	else if (ar->b[ar->sizeb - 1] > ar->b[0] && ar->b[ar->sizeb - 1] > ar->b[1])
	{
		if (ar->a[ar->sizea - 1] < ar->a[0] && ar->a[ar->sizea - 1] < ar->a[1])
			rrotate_ab(ar, 1);
		else
			rrotate(ar->b, ar->sizeb, 2);
	}
}

/*
** Sort stack a
*/

static void	sort_a(int *a, int size)
{
	while (!(issorted(a, size, 'a')))
	{
		if (a[0] > a[1] && a[0] > a[2] && a[0] > a[size - 1])
			rotate(a, size, 1);
		else if (a[0] > a[1] && a[0] < a[size - 1])
			swap(a, size, 1);
		else if (a[size - 1] < a[0] && a[size - 1] < a[1])
			rrotate(a, size, 1);
	}
}

/*
** Push all numbers from stack b back to stack a
*/

static void	push_a(t_ar *ar)
{
	int i;

	while (ar->sizeb != 0)
	{
		if (ar->sizeb == 1 || ar->b[0] == ar->max[3])
		{
			push_ab(ar, 'a');
			sort_b(ar);
			sort_a(ar->a, ar->sizea);
			if (ar->sizeb > 0)
				ar->max[3] = ar->max[4] == ar->max[3] ? ar->max[5] : ar->max[4];
			if (ar->sizeb > 1)
			{
				ar->max[4] = ar->max[5];
				ar->max[4] = ar->max[4] == ar->max[3] ? findnewmax(ar) : ar->max[4];
			}
			if (ar->sizeb > 2)
				ar->max[5] = findnewmax(ar);
		}
		else
		{
			i = findindexmax(ar->b, ar->sizeb, ar->max[3]);
			if (i != -1 && i < ar->sizeb / 2)
				while (i > 0)
				{
					if (ar->b[0] == ar->max[4] && ar->max[4] < ar->max[3])
					{
						push_ab(ar, 'a');
						ar->max[4] = ar->max[3];
					}
					if (ar->b[0] != ar->max[3])
						rotate(ar->b, ar->sizeb, 2);
					i--;
				}
			else if (i != -1)
				while (ar->b[0] != ar->max[3])
				{
					if (ar->b[0] == ar->max[4] && ar->max[4] < ar->max[3])
					{
						push_ab(ar, 'a');
						ar->max[4] = ar->max[3];
					}
					rrotate(ar->b, ar->sizeb, 2);
				}
		}
	}
}

/*
** Push all numbers to stack b wich is smalles then max[2]
*/

static void	push_b(t_ar *ar)
{
	while (ar->sizea > 3)
	{
		if (ar->a[0] < ar->max[2])
		{
			push_ab(ar, 'b');
			sort_b(ar);
		}
		else
			rotate(ar->a, ar->sizea, 1);
	}
}

void		sort(t_ar *ar)
{
	while (!(ar->sizeb == 0 && issorted(ar->a, ar->sizea, 'a')))
	{
		push_b(ar);
		sort_a(ar->a, ar->sizea);
		push_a(ar);
		if (ar->a[0] > ar->a[1])
			swap(ar->a, ar->sizea, 1);
	}
}
