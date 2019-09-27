/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:50:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/27 16:10:12 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push all elements > avg + avg / 2 to stack b
** all element bigger we rotate to the and of a
** If we got minimum, then we're rotate it to the end of stack a
** if we didn't rotate anything else
*/

static void	push_b_third(t_ar *ar, int av, int avg)
{
	int count;
	int rra;
	int max;

	rra = 0;
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
	av = get_avg(ar->b, ar->sizeb);
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

static void	push_b_second(t_ar *ar, int av, int avg, int flag)
{
	int count;
	int max;

	count = 0;
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
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_second(ar, get_avg2(ar->a, ar->sizea - cnt, avg, 0), avg, 1);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, avg, 1);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_third(ar, get_avg2(ar->a, ar->sizea - cnt, avg, 1), avg);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_second(ar, get_avg2(ar->a, ar->sizea - cnt, avg, 2), avg, 0);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, avg, 0);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
				get_mins(ar->b, ar->sizeb, min), &cnt);
	free(min);
}
