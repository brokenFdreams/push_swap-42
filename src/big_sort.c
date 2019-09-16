/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:50:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/16 12:50:21 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_fourth(t_ar *ar, int avg, int flag)
{
	while ((flag && ar->a[0] <= avg) || (!flag && ar->a[0] > avg))
		push_ab(ar, 'b');
}

/*
** Push all elements <= avg on the top of a
** if we got minimum, then we're rotate it to end of stack a
*/

static void	push_b_second(t_ar *ar, int avg, int flag)
{
	int count;
	int max;

	count = 0;
	while ((flag && ar->a[0] <= avg) || (!flag && ar->a[0] > avg))
		if (((flag && ar->a[0] > avg / 4 * 3) ||
			 (!flag && ar->a[0] > avg + avg / 4 * 3)) && ++count)
			rotate(ar->a, ar->sizea, 1);
		else
			push_ab(ar, 'b');
	max = ar->b[get_max(ar->b, ar->sizeb)];
	while (count-- > 0)
		if (ar->b[0] == max)
			rrotate(ar->a, ar->sizea, 1);
		else
			rrotate_ab(ar, 1);
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
	print(ar->a, ar->sizea);
	printf("_____________B___________\n");
	print(ar->b, ar->sizeb);
	push_a_first(ar, avg / 4, get_mins(ar->b, ar->sizeb, min), &cnt);
	print(ar->a, ar->sizea);
	printf("_____________B___________\n");
	print(ar->b, ar->sizeb);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);
	print(ar->a, ar->sizea);
	printf("_____________B___________\n");
	print(ar->b, ar->sizeb);

	push_b_second(ar, avg, 1);
	push_a_first(ar, avg / 4 * 3, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, avg, 1);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);

	push_b_third(ar, avg);
	push_a_first(ar, avg + avg / 4, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);

	push_b_second(ar, avg, 0);
	push_a_first(ar, avg + avg / 4 * 3, get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, avg, 0);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea);
	free(min);
}
