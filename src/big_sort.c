/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:18:02 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/05 13:05:49 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Count all element less/bigger then avg
*/

static int	count_avg(int *a, int size, int avg, int flag)
{
	int count;

	count = 0;
	while (--size >= 0)
		if (flag && a[i] <= avg)
			count++;
		else if (!flag && a[i] > avg)
			count++;
	return (count);
}

/*
** Join array: all elements get back to stack a
** firstly push all elements and then rotate in stack a
** Call, if stack b sorted 4 3 2 1
*/

static void	join_smart(t_ar *ar)
{
	int count = ar->sizeb;
	while (ar->sizeb > 0)
		push_ab(ar, 'a');
	while (!(issorted(ar->a, ar->sizea, 'a') && count > 0)
	{
		rotate(ar->a, ar->sizea, 1);
		count--;
	}
}

/*
** Join array: all elements get back to stack a, first min and rotate it in a
*/

static void	join_array(t_ar *ar, int flag)
{
	int min;
	int indexmin;

	while (ar->sizeb > 0)
	{
		if (issorted(ar->b, ar->sizeb, 'b') && !flag)
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
		if (!flag)
			rotate(ar->a, ar->sizea, 1);
	}
}

/*
** Split array: all element bigger then avg push to stack b
*/

static void	split_array(t_ar *ar, int avg, int flag)
{
	int count;

	count = count_avg(ar->a, ar->sizea, avg, flag);
	while (count > 0)
	{
		if ((flag && ar->a[0] <= avg) || !flag)
		{
			push_ab(ar, 'b');
			count--;
		}
		else if (flag && ar->a[0] > avg)
			rotate(ar->a, ar->sizea, 1);
	}
}

/*
** Sort for 10-... elements
*/

void		big_sort(t_ar *ar, int avg)
{
	split_array(ar, avg, 1);
	join_array(ar, issorted(ar->a, ar->sizea, 'a'));
	if (!(issorted(ar->a, ar->sizea, 'a')))
	{
		split_array(ar, avg, 0);
		join_array(ar, 0);
	}
}
