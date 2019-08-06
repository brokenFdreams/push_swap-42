/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:21:00 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 16:52:09 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_ab(t_ar *ar)
{
	int count;

	count = 0;
	if (ar->a[0] > ar->a[1] && ar->b[0] > ar->b[1])
	{
		swap(ar);
		write(1, "ss\n", 3);
		count++;
	}
	if (ar->a[0] > ar->a[ar->sizea - 1] && ar->b[0] > ar->b[ar->sizeb - 1])
	{
		rotate_ab(ar);
		write(1. "rr\n", 3);
		count++;
	}
	if (ar->a[0] < ar->a[ar->sizea - 1] && ar->b[0] < ar->b[ar->sizeb - 1])
	{
		rrotate_ab(ar);
		write(1, "rrr\n", 4);
		count++;
	}
	return (count);
}

static void	sort_swap(int *ar, int size, char c)
{
	int count;

	count = 0;
	if (ar[0] > ar[1])
	{
		swap(ar, size);
		if (c == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	if (ar[0] > ar[size - 1])
	{
		rotate(ar, size);
		if (c == 'a')
			write(1, "ra\n", 1);
		else
			write(1, "rb\n", 1);
	}
	if (ar[0] < ar[size - 1])
	{
		rrotate(ar, size);
		if (c == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

static void	push_swap(t_ar *ar)
{
	if (ar->sizea > 1)
	{
		
		
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
