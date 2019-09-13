/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:50:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/13 15:51:16 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_fourth(t_ar *ar, int *min, int *cnt)
{
	while (ar->sizea > *cnt)
		if (ar->a[0] == min[0] &&
			min[0] > ar->b[get_min(ar->b, ar->sizeb)] && ++(*cnt))
		{
			rotate(ar->a, ar->sizea, 1);
			min = get_mins(ar->a, ar->sizea - *cnt, min);
		}
		else
			push_ab(ar, 'b');
}

/*
** Push all elements <= avg on the top of a
** if we got minimum, then we're rotate it to end of stack a
*/

static void	push_b_second(t_ar *ar, int avg, int *min, int *cnt)
{
	while (ar->a[0] <= avg)
		if (ar->a[0] == min[0] &&
			min[0] > ar->b[get_min(ar->b, ar->sizeb)] && ++(*cnt))
		{
			rotate(ar->a, ar->sizea, 1);
			min = get_mins(ar->a, ar->sizea - *cnt, min);
		}
		else
			push_ab(ar, 'b');
}

/*
** Sort for 10-... elements
*/

void		big_sort(t_ar *ar, int avg)
{
	int *min;
	int cnt;

	cnt = 0;
	min = (int*)malloc(sizeof(int) * 3);
	push_b_first(ar, avg, get_mins(ar->a, ar->sizea, min), &cnt);
	push_a_first(ar, avg / 4, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_second(ar, avg, get_mins(ar->a, ar->sizea - cnt, min), &cnt);
	push_a_first(ar, avg / 4 * 3, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_third(ar, avg);
	push_a_first(ar, avg + avg / 4, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, get_mins(ar->a, ar->sizea - cnt, min), &cnt);
	push_a_first(ar, avg + avg / 4 * 3,
				get_mins(ar->b, ar->sizeb, min), &cnt);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);
	free(min);
}
