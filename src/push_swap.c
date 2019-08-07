/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:21:00 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/07 14:35:46 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_ab(t_ar *ar)
{
	if (ar->a[0] > ar->a[1] && ar->a[0] < ar->a[ar->sizea - 1]
		&& ar->b[0] < ar->b[1] && ar->b[0] > ar->b[ar->sizeb - 1])
	{
		swap_ab(ar);
		write(1, "ss\n", 3);
		return (1);
	}
	if ((ar->a[0] > ar->a[ar->sizea - 1] || (ar->a[0] < ar->a[ar->sizea - 1] &&
		ar->a[ar->sizea - 1] < ar->a[ar->sizea - 2])) &&
		(ar->b[0] < ar->b[ar->sizeb - 1] || (ar->b[0] > ar->b[ar->sizeb - 1] &&
		ar->b[ar->sizeb - 1] < ar->b[ar->sizeb - 2])))
	{
		if (ar->a[0] > ar->a[1] && ar->b[0] < ar->b[1])
		{
			rotate_ab(ar);
			write(1, "rr\n", 3);
			return (1);
		}
		else if (ar->a[0] < ar->a[1] && ar->b[0] > ar->b[1])
		{
			rrotate_ab(ar);
			write(1, "rrr\n", 4);
			return (1);
		}
	}
	return (0);
}

static int	sort_b(int *ar, int size)
{
	if (ar[0] < ar[1] && ar[0] > ar[size - 1])
	{
		swap(ar, size);
		write(1, "sb\n", 3);
		return (1);
	}
	if (ar[0] < ar[size - 1] ||
		(ar[0] > ar[size - 1] && ar[size - 1] > ar[size - 2]))
	{
		if (ar[0] < ar[1])
		{
			rotate(ar, size);
			write(1, "rb\n", 3);
		}
		else
		{
			rrotate(ar, size);
			write(1, "rrb\n", 4);
		}
		return (1);
	}
	return (0);
}

static int	sort_a(int *ar, int size)
{
	if (ar[0] > ar[1] && ar[0] < ar[size - 1])
	{
		swap(ar, size);
		write(1, "sa\n", 3);
		return (1);
	}
	if (ar[0] > ar[size - 1] ||
		(ar[0] < ar[size - 1] && ar[size - 1] < ar[size - 2]))
	{
		if (ar[0] > ar[1])
		{
			rotate(ar, size);
			write(1, "ra\n", 3);
		}
		else
		{
			rrotate(ar, size);
			write(1, "rra\n", 4);
		}
		return (1);
	}
	return (0);
}

static void	push_swap(t_ar *ar)
{
	int count;

	count = 0;
	if (ar->sizea > 1)
	{
		while (!(issorted(ar->a, ar->sizea, 'a') && ar->sizeb == 0))
		{
			if (ar->sizeb > 1 && ar->sizea > 1)
				while (sort_ab(ar))
					count = 0;
			if (ar->sizeb > 1 && sort_b(ar->b, ar->sizeb) && !(count = 0))
				if (ar->sizeb > 1 && ar->sizea > 1)
					while (sort_ab(ar))
						;
			if (ar->sizea > 1 && sort_a(ar->a, ar->sizea) && !(count = 0))
				if (ar->sizeb > 1 && ar->sizea > 1)
					while (sort_ab(ar))
						;
			if (issorted(ar->a, ar->sizea, 'a') && ar->sizeb > 0 && (count = 1))
				push_ab(ar, 'a');
			else if (!(issorted(ar->a, ar->sizea, 'a')) && !(count))
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
