/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:09:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/06 14:31:44 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push all element from statck b to stack a
*/

static void	push_a(t_ar *ar, int *max)
{
	int flag;

	max = get_maxs(ar->b, ar->sizeb, max);
	flag = 0;
	while (ar->sizeb > 0)
	{
		if (ar->b[0] == max[0])
		{
			push_ab(ar, 'a');
			if (flag)
				swap(ar->a, ar->sizea, 1);
			flag = 0;
			max = get_maxs(ar->b, ar->sizeb, max);
		}
		else if (ar->b[0] == max[1])
		{
			push_ab(ar, 'a');
			flag = 1;
		}
	}
}

/*
** Push elements to stack b
*/

static void	push_b(t_ar *ar, int *max)
{
	while (ar->sizea > 3)
		if (ar->a[0] < max[2])
			push_ab(ar, 'b');
		else
			rotate(ar->a, ar->sizea, 1);
}

/*
** Sort for 3-10 elements
*/

void		sort(t_ar *ar)
{
	int *max;

	max = (int*)malloc(sizeof(int) * 3);
	max = get_maxs(ar->a, ar->sizea, max);
	push_b(ar, max);
	small_sort(ar->a, ar->sizea);
	push_a(ar, max);
	free(max);
}
