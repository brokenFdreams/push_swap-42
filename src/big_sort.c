/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:01:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/11 15:38:13 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Join array: all elements get back to stack a
** firstly push all elements and then rotate in stack a
** Call, if stack b sorted 4 3 2 1
*/

static void	join_smart(t_ar *ar)
{
	int count;

	count = ar->sizeb;
	while (ar->sizeb > 0)
		push_ab(ar, 'a');
	while (!(issorted(ar->a, ar->sizea, 'a')) && count > 0)
	{
		rotate(ar->a, ar->sizea, 1);
		count--;
	}
}

/*
** Join array: all elements get back to stack a, first min and rotate it in a
*/

static void	join_array(t_ar *ar)
{
	int min;
	int indexmin;

	while (ar->sizeb > 0)
	{
		if (issorted(ar->b, ar->sizeb, 'b'))
		{
			join_smart(ar);
			return ;
		}
		indexmin = get_min(ar->b, ar->sizeb);
		min = ar->b[indexmin];
		if (indexmin != 0 && indexmin > ar->sizeb / 2)
			while (ar->b[0] != min)
				rrotate(ar->b, ar->sizeb, 2);
		else if (indexmin != 0)
			while (ar->b[0] != min)
				rotate(ar->b, ar->sizeb, 2);
		push_ab(ar, 'a');
		rotate(ar->a, ar->sizea, 1);
	}
}

/*
** Count all element less/bigger then avg
*/

static int	count_avg(int *a, int size, int avg)
{
	int count;

	count = 0;
	while (--size >= 0)
		if (a[size] <= avg)
			count++;
	return (count);
}

/*
** Split array on 4 stack: first call split first 25%, then next 25%
*/

static void	split_array(t_ar *ar, int avg, int flag)
{
	int count;

	count = count_avg(ar->a, ar->sizea, avg);
	count = flag == 1 ? count : ar->sizea - count;
	while (count > 0)
	{
		if ((flag == 1 && ar->a[0] <= avg) || (flag == 2 && ar->a[0] > avg))
		{
			push_ab(ar, 'b');
			count--;
		}
		else
			rotate(ar->a, ar->sizea, 1);
		if (flag == 1 && ar->b[0] > avg / 3 && ar->a[0] > avg)
			rotate_ab(ar, 1);
		if ((ar->sizeb > 2 && flag == 1 && ar->b[0] > avg / 3) ||
			(ar->sizeb > 2 && flag == 2 && ar->b[0] < avg + avg / 3))
			rotate(ar->b, ar->sizeb, 2);
		if (count > 1 && ar->sizeb > 1 && ar->a[0] > ar->a[1] &&
			ar->b[0] > ar->b[1])
			swap_ab(ar, 1);
	}
}

/*
** Sort for 10-... elements
*/

void		big_sort(t_ar *ar, int avg)
{
	split_array(ar, avg, 1);
	join_array(ar);
	split_array(ar, avg, 2);
	join_array(ar);
}
