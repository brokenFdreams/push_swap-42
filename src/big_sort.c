/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:01:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/12 13:56:35 by fsinged          ###   ########.fr       */
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

static int	count_avg(int *a, int size, int avg, int flag)
{
	int count;

	count = 0;
	while (--size >= 0)
		if ((flag == 1 && a[size] <= avg / 2) ||
			(flag == 4 && a[size] > avg + avg / 2) ||
			(flag == 2 && a[size] > avg / 2 && a[size] <= avg) ||
			(flag == 3 && a[size] > avg && a[size] <= avg + avg / 2))
			count++;
	return (count);
}

/*
** Split array on 4 stack: first call split first 25%, then next 25%
*/

static void	split_array(t_ar *ar, int avg, int flag, int av)
{
	int count;
	int countrotate;

	count = count_avg(ar->a, ar->sizea, avg, flag);
	countrotate = 0;
	avg = flag == 1 ? avg / 2 : avg;
	avg = flag == 3 ? avg + avg / 2 : avg;
	while (count > 0)
		if ((flag == 4 && ar->a[0] > avg) || (flag != 4 && ar->a[0] <= avg))
		{
			push_ab(ar, 'b');
			count--;
			if (count != 0 && sort_help(ar, avg, flag, av) == 1)
				countrotate++;
			else if (count != 0 && ar->sizeb > 2 && ar->b[0] > av)
				rotate(ar->b, ar->sizeb, 2);
		}
		else if (++countrotate)
			rotate(ar->a, ar->sizea, 1);
	while (flag != 1 && countrotate-- > 0)
		rrotate(ar->a, ar->sizea, 1);
}

/*
** Sort for 10-... elements
*/

void		big_sort(t_ar *ar, int avg)
{
	split_array(ar, avg, 1, avg / 4);
	join_array(ar);
	split_array(ar, avg, 2, avg / 4 * 3);
	join_array(ar);
	split_array(ar, avg, 3, avg + avg / 4);
	join_array(ar);
	split_array(ar, avg, 4, avg + avg / 4 * 3);
	join_array(ar);
}
