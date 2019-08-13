/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:48:36 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/13 15:24:58 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swap for both stacks
*/

static int	swaps_ab(t_ar *ar)
{
	if (ar->a[0] > ar->a[1] &&
		(ar->a[0] < ar->a[ar->sizea - 1] || ar->a[0] < ar->a[2]) &&
		ar->b[0] < ar->b[1] &&
		(ar->b[0] > ar->b[ar->sizeb - 1] || ar->b[0] > ar->b[2]))
	{
		write(1, "ss\n", 3);
		swap_ab(ar);
		return (1);
	}
	if (ar->a[0] > ar->a[1] && ar->a[0] > ar->a[ar->sizea - 1] &&
		ar->b[0] < ar->b[1] && ar->b[0] < ar->b[ar->sizeb - 1])
	{
		write(1, "rr\n", 3);
		rotate_ab(ar);
		return (1);
	}
	if (ar->a[ar->sizea - 1] < ar->a[0] && ar->a[ar->sizea - 1] < ar->a[1] &&
		ar->b[ar->sizeb - 1] > ar->a[0] && ar->a[ar->sizeb - 1] > ar->b[1])
	{
		write(1, "rrr\n", 4);
		rrotate_ab(ar);
		return (1);
	}
	return (0);
}

/*
** Swap for both stacks by one
*/

static int	swaps_a(int *ar, int size, char c)
{
	int count;

	count = 0;
	if ((c == 'a' && ar[0] > ar[1] &&
		(ar[0] < ar[size - 1] || ar[0] < ar[2])) ||
		(c == 'b' && ar[0] < ar[1] && (ar[0] > ar[size - 1] || ar[0] > ar[2])))
	{
		write(1, "s", 1);
		swap(ar, size);
		count = 1;
	}
	else if ((c == 'a' && ar[0] > ar[1] && ar[0] > ar[size - 1]) ||
		(c == 'b' && ar[0] < ar[1] && ar[0] < ar[size - 1]))
	{
		write(1, "r", 1);
		rotate(ar, size);
		count = 1;
	}
	else if ((c == 'a' && ar[size - 1] < ar[0] && ar[size - 1] < ar[1]) ||
			(c == 'b' && ar[size - 1] > ar[0] && ar[size - 1] > ar[1]))
	{
		write(1, "rr", 2);
		rrotate(ar, size);
		count = 1;
	}
	if (count == 1 && c == 'a')
		write(1, "a\n", 2);
	else if (count == 1 && c == 'b')
		write(1, "b\n", 2);
	return (count);
}

/*
** Sort for both stacks
*/

static void	sort_ab(t_ar *ar)
{
	if (ar->sizea > 1 && ar->sizeb > 1)
		while (swaps_ab(ar) || swaps_a(ar->a, ar->sizea, 'a') ||
				swaps_ab(ar) || swaps_a(ar->b, ar->sizeb, 'b'))
			;
	else if (ar->sizea > 1)
		while (swaps_a(ar->a, ar->sizea, 'a'))
			;
}

static void	push_swap(t_ar *ar)
{
	if (ar->sizea > 1)
	{
		while (!(ar->sizeb == 0 && issorted(ar->a, ar->sizea, 'a')))
		{
			sort_ab(ar);
			if (ar->sizeb > 0 && issorted(ar->a, ar->sizea, 'a') &&
				(ar->b[0] < ar->a[0] || ar->b[0] < ar->a[1] ||
				ar->b[0] > ar->a[ar->sizea - 1]))
				push_ab(ar, 'a');
			else if (ar->sizea > 3 && (!(issorted(ar->a, ar->sizea, 'a'))
					|| ar->sizeb > 2))
				push_ab(ar, 'b');
		}
	}
}

int			main(int argc, char **argv)
{
	t_ar	*ar;

	if (argc == 1)
		return (0);
	ar = init_ar(argc - 1);
	if (readnumbers(argc - 1, argv + 1, ar->a) != 0)
		push_swap(ar);
	else
		write(1, "Error\n", 6);
	print(ar->a, ar->sizea);
	free_struct(&ar);
	return (0);
}
