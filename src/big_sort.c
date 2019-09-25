/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:50:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/25 13:43:50 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Push all elements > avg + avg / 2 to stack b
** all element bigger we rotate to the and of a
** If we got minimum, then we're rotate it to the end of stack a
** if we didn't rotate anything else
*/

static void	push_b_third(t_ar *ar, int avg)
{
	int count;
	int rra;
	int max;
	int av;

	rra = 0;
	av = avg > 0 ? avg + avg / 2 : avg - avg / 2;
	count = count_avg(ar->a, ar->sizea, avg, 2);
	while (count > 0)
		if (ar->a[0] > avg && ar->a[0] <= av && count--)
			push_ab(ar, 'b');
		else if (++rra)
			rotate(ar->a, ar->sizea, 1);
	max = ar->b[get_max(ar->b, ar->sizeb)];
	while (rra-- > 0)
		if (ar->b[0] != max)
			rrotate_ab(ar, 1);
		else
			rrotate(ar->a, ar->sizea, 1);
}

/*
** Push b all elememnts <= avg
** Then we're push back all elemts is bigger then avg / 2
** if we got minimum, then we're push it to a and rotate
*/

static void	push_b_first(t_ar *ar, int avg, int *min, int *cnt)
{
	int count;
	int av;

	count = count_avg(ar->a, ar->sizea, avg, 0);
	while (count > 0)
		if (ar->a[0] <= avg && count--)
			push_ab(ar, 'b');
		else
			rotate(ar->a, ar->sizea, 1);
	av = avg > 0 ? avg / 2 : avg + avg / 2;
	count = count_avg(ar->b, ar->sizeb, av, 1);
	while (count > 0)
		if (ar->b[0] > av && count--)
			push_ab(ar, 'a');
		else if (ar->b[0] == min[0] && ++(*cnt))
		{
			push_ab(ar, 'a');
			if (ar->b[0] <= av)
				rotate_ab(ar, 1);
			else
				rotate(ar->a, ar->sizea, 1);
			min = get_mins(ar->b, ar->sizeb, min);
		}
		else
			rotate(ar->b, ar->sizeb, 2);
}

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
	int av;

	count = 0;
	if (flag)
		av = avg > 0 ? avg / 4 * 3 : avg + avg / 4;
	else
		av = avg > 0 ? avg + avg / 4 * 3 : avg / 4;
	while ((flag && ar->a[0] <= avg) || (!flag && ar->a[0] > avg))
		if (ar->a[0] > av && ++count)
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
//	print(ar->a, ar->sizea, "pb1AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pb1BBBBBBBBBBB");
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea, "pa1AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pa1BBBBBBBBBBB");
	push_b_second(ar, avg, 1);
//	print(ar->a, ar->sizea, "pb2AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pb2BBBBBBBBBBB");
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea, "pa2AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pa2BBBBBBBBBBB");
	push_b_fourth(ar, avg, 1);
//	print(ar->a, ar->sizea, "pb3AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pb3BBBBBBBBBBB");
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea, "pa3AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pa3BBBBBBBBBBB");
	push_b_third(ar, avg);
//	print(ar->a, ar->sizea, "pb4AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pb4BBBBBBBBBBB");
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea, "pa4AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pa4BBBBBBBBBBB");
	push_b_second(ar, avg, 0);
//	print(ar->a, ar->sizea, "pb5AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pb5BBBBBBBBBBB");
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				 get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea, "pa5AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pa5BBBBBBBBBBB");
	push_b_fourth(ar, avg, 0);
//	print(ar->a, ar->sizea, "pb6AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pb6BBBBBBBBBBB");
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
//	print(ar->a, ar->sizea, "pa6AAAAAAAAAAA");
//	print(ar->b, ar->sizeb, "pa6BBBBBBBBBBB");
	free(min);
}
