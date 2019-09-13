/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:45:27 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/13 15:50:40 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Count all elements less or bigger then avg
*/

static int	count_avg(int *a, int size, int avg, int flag)
{
	int count;

	count = 0;
	while (--size >= 0)
		if ((flag == 0 && a[size] <= avg) || (flag == 1 && a[size] > avg) ||
			(flag == 2 && a[size] > avg && a[size] <= avg + avg / 2))
			count++;
	return (count);
}

/*
** Push all elements > avg + avg / 2 to stack b
** all element bigger we rotate to the and of a
** If we got minimum, then we're rotate it to the end of stack a
** if we didn't rotate anything else
*/

void		push_b_third(t_ar *ar, int avg)
{
	int count;
	int rra;
	int max;

	rra = 0;
	count = count_avg(ar->a, ar->sizea, avg, 2);
	while (count > 0)
		if (ar->a[0] > avg && ar->a[0] <= avg + avg / 2 && count--)
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
** push a all elements in stack b
** if last element of stack b is minimum
** then we're push it to a and rotate it
** if last element of statck b is maximum
** then we're push it to top of stack a
*/

void		push_a_second(t_ar *ar, int *min, int *cnt)
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

/*
** Push b all elememnts <= avg
** Then we're push back all elemts is bigger then avg / 2
** if we got minimum, then we're push it to a and rotate
*/

void		push_b_first(t_ar *ar, int avg, int *min, int *cnt)
{
	int count;

	count = count_avg(ar->a, ar->sizea, avg, 0);
	while (count > 0)
		if (ar->a[0] <= avg && count--)
			push_ab(ar, 'b');
		else
			rotate(ar->a, ar->sizea, 1);
	count = count_avg(ar->b, ar->sizeb, avg / 2, 1);
	while (count > 0)
		if (ar->b[0] > avg / 2 && count--)
			push_ab(ar, 'a');
		else if (ar->b[0] == min[0] && ++(*cnt))
		{
			push_ab(ar, 'a');
			if (ar->b[0] <= avg / 2)
				rotate_ab(ar, 1);
			else
				rotate(ar->a, ar->sizea, 1);
			min = get_mins(ar->b, ar->sizeb, min);
		}
		else
			rotate(ar->b, ar->sizeb, 2);
}

void		push_a_first(t_ar *ar, int avg, int *min, int *cnt)
{
	int count;
	int ret;

	count = count_avg(ar->b, ar->sizeb, avg, 1);
	ret = count;
	while (count > 0)
		while (count > 0)
			if (ar->b[0] > avg && count--)
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
	while (ret-- > 0)
		push_ab(ar, 'b');
}
