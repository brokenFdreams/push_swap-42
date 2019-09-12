/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:50:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/12 16:02:27 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return 1 if to max num less steps and 0 if not
*/

static int ismaxormin(int *b, int size)
{
	int indexmax;
	int indexmin;

	indexmax = get_max(b, size);
	indexmin = get_min(b, size);
	return (ft_min(indexmax, size - indexmax + 1) <
			ft_min(indexmin, size - indexmin + 1));
}

/*
** Join array: all elements get back to stack a, first min and rotate it in a
*/

static void	join_array(t_ar *ar)
{
	int ra;
	int index;
	int flag;
	int num;

	ra = 0;
	while (ar->sizeb > 0)
	{
		flag = ismaxormin(ar->b, ar->sizeb);
		index = flag ? get_max(ar->b, ar->sizeb) : get_min(ar->b, ar->sizeb);
		num = ar->b[index];
		if (index != 0 && index > ar->sizeb / 2)
			while (ar->b[0] != num)
				rrotate(ar->b, ar->sizeb, 2);
		else if (index != 0)
			while (ar->b[0] != num)
				rotate(ar->b, ar->sizeb, 2);
		push_ab(ar, 'a');
		if (flag)
			ra++;
		else
			rotate(ar->a, ar->sizea, 1);
	}
	while (ra-- > 0)
		rotate(ar->a, ar->sizea, 1);
}

/*
** Count all elements less or bigger then avg
*/

static int	count_avg(int *a, int size, int avg, int flag)
{
	int count;

	count = 0;
	while (--size >= 0)
		if ((flag && a[size] > avg) || (!flag && a[size] <= avg))
			count++;
	return (count);
}

/*
** Split array on 2 stack
*/

static void	split_array(t_ar *ar, int avg, int flag, int *min)
{
	int count;
	int sorted;
	int rra;

	count = count_avg(ar->a, ar->sizea, avg, flag);
	sorted = 0;
	rra = 0;
	while (count > 0)
		if (flag && ar->a[0] == min[0] && ++sorted)
		{
			rotate(ar->a, ar->sizea, 1);
			count--;
			min = get_mins(ar->a, ar->sizea - sorted, min);
		}
		else if ((!flag && ar->a[0] <= avg && ++rra) ||
				(flag && ar->a[0] > avg))
		{
			count--;
			push_ab(ar, 'b');
			if ((!flag && ar->b[0] > avg / 2) ||
				(flag && ar->b[0] > avg + avg / 2))
				rotate(ar->b, ar->sizeb, 2);
		}
		else
			rotate(ar->a, ar->sizea, 1);
	while (rra-- > 0)
		rrotate(ar->a, ar->sizea, 1);
}

/*
** Sort for 10-... elements
*/

void		big_sort(t_ar *ar, int avg)
{
	int *min;

	min = (int*)malloc(sizeof(int) * 3);
	split_array(ar, avg, 0, min);
	join_array(ar);
	split_array(ar, avg, 1, get_mins(ar->a, ar->sizea / 2, min));
	join_array(ar);
	free(min);
}
