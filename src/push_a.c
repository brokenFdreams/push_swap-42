/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:55:52 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/02 13:44:05 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_a(int *a, int size);
void sort_b(t_ar *ar);

void	push_a(t_ar *ar)
{
	int i;

	while (ar->sizeb != 0)
	{
		if (ar->sizeb == 1 || ar->b[0] == ar->max[3])
		{
			if (/*ar->sizeb != 1 &&*/
				ar->max[5] == ar->max[3] && ar->max[4] == ar->max[3])
			{
				push_ab(ar, 'b');
				swap(ar->b, ar->sizeb, 2);
				push_ab(ar, 'a');
				sort_a(ar->a, ar->sizea);
				push_ab(ar, 'a');
				sort_a(ar->a, ar->sizea);
			}
			else
			{
				push_ab(ar, 'a');
				sort_a(ar->a, ar->sizea);
			}
			if (ar->sizeb > 0 && ar->max[4] == ar->max[3])
				ar->max[3] = ar->max[5] == ar->max[3] ? findnewmax(ar)
					: ar->max[5];
			else if (ar->sizeb > 0)
				ar->max[3] = ar->max[4];
			if (ar->sizeb > 1)
				ar->max[4] = findnewmax(ar);
			if (ar->sizeb > 2)
			{
				ar->max[5] = findnewmax(ar);
				ar->max[2] = ar->max[5];
			}
		}
		else
		{
			i = findindexmax(ar->b, ar->sizeb, ar->max[3]);
			if (i != -1 && i < ar->sizeb / 2)
				while (i > 0)
				{
					if ((ar->b[0] == ar->max[4] || ar->b[0] == ar->max[5])
						&& ar->b[0] < ar->max[3])
					{
						if ((ar->max[4] == ar->max[3] || ar->max[5] == ar->max[3])
							&& (ar->b[1] == ar->max[3] || ar->b[2] == ar->max[3]))
							swap(ar->b, ar->sizeb, 2);
						else if (ar->b[0] == ar->max[4])
							ar->max[4] = ar->max[3];
						else
							ar->max[5] = ar->max[3];
						if ((ar->b[0] == ar->max[4] || ar->b[0] == ar->max[5])
							&& ar->b[0] < ar->max[3])
							push_ab(ar, 'a');
					}
					if (ar->b[0] != ar->max[3])
						rotate(ar->b, ar->sizeb, 2);
					i--;
				}
			else if (i != -1)
				while (ar->b[0] != ar->max[3])
				{
					if ((ar->b[0] == ar->max[4] || ar->b[0] == ar->max[5])
						&& ar->b[0] < ar->max[3])
					{
						if (ar->b[0] == ar->max[4])
							ar->max[4] = ar->max[3];
						else if (ar->b[0] == ar->max[5])
							ar->max[5] = ar->max[3];
						push_ab(ar, 'a');
					}
					else if (ar->b[0] != ar->max[3])
						rrotate(ar->b, ar->sizeb, 2);
				}
		}
	}
}
