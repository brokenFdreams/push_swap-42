/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:45:27 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/26 13:07:26 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Count all elements less or bigger then avg
*/

int			count_avg(int *a, int size, int avg, int flag)
{
	int count;
	int av;

	count = 0;
	av = get_avg2(a, size, avg, 1);
	while (--size >= 0)
		if ((flag == 0 && a[size] <= avg) || (flag == 1 && a[size] > avg) ||
			(flag == 2 && a[size] > avg && a[size] <= av))
			count++;
	return (count);
}

/*
** push a all elements in stack b
** if last element of stack b is minimum
** then we're push it to a and rotate it
** if last element of statck b is maximum
** then we're push it to top of stack a
*/

static void	push_a_second(t_ar *ar, int *min, int *cnt)
{
	int index;
	int max;
	int ra;

	ra = 0;
	while (ar->sizeb > 0)
	{
		index = get_max(ar->b, ar->sizeb);
		max = ar->b[index];
		while (ar->b[0] != max)
			if (ar->b[0] == min[0] && ++(*cnt))
			{
				push_ab(ar, 'a');
				rotate(ar->a, ar->sizea, 1);
				min = get_mins(ar->b, ar->sizeb, min);
			}
			else if (index != 0 && index > ar->sizeb / 2)
				rrotate(ar->b, ar->sizeb, 2);
			else
				rotate(ar->b, ar->sizeb, 2);
		push_ab(ar, 'a');
		ra++;
	}
	while (ra-- > 0 && ++(*cnt))
		rotate(ar->a, ar->sizea, 1);
}

static void	push_a_recursive(t_ar *ar, int *min, int *cnt, int flag)
{
	int count;

	count = count_avg(ar->b, ar->sizeb, get_avg(ar->b, ar->sizeb), 1);
	if ((flag && count > 9) || (flag && count > 17))
		push_a_first(ar, get_avg(ar->b, ar->sizeb), min, cnt);
	else
		push_a_second(ar, min, cnt);
}

static void	push_a_help(t_ar *ar, int *min, int *cnt, int ret)
{
	while (ret-- > 0)
		if (min[0] == ar->a[0] && min[0] < ar->b[get_min(ar->b, ar->sizeb)])
		{
			rotate(ar->a, ar->sizea, 1);
			++(*cnt);
			min = get_mins(ar->a, ar->sizea - *cnt, min);
		}
		else
			push_ab(ar, 'b');
}

void		push_a_first(t_ar *ar, int avg, int *min, int *cnt)
{
	int count;
	int ret;
	int flag;

	ret = 0;
	flag = (ar->sizea + ar->sizeb) > 200;
	while (((count = count_avg(ar->b, ar->sizeb, avg, 1)) > 9 && !flag) ||
			(count > 17 && flag))
		while ((avg = count > 0 ? avg : get_avg(ar->b, ar->sizeb)) && count > 0)
			if (ar->b[0] > avg && count-- && ++ret)
				push_ab(ar, 'a');
			else if (ar->b[0] == min[0] && ++(*cnt))
			{
				push_ab(ar, 'a');
				if (ar->b[0] <= avg)
					rotate_ab(ar, 1);
				else
					rotate(ar->a, ar->sizea, 1);
				min = get_mins(ar->b, ar->sizeb, min);
			}
			else
				rotate(ar->b, ar->sizeb, 2);
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), cnt);
	push_a_help(ar, get_mins(ar->a, ar->sizea - *cnt, min), cnt, ret);
	push_a_recursive(ar, get_mins(ar->b, ar->sizeb, min), cnt, flag);
}
