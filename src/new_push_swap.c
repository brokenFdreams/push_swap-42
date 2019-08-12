/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:48:36 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/12 16:34:59 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort for both stacs
*/

/*
** If we can ss, we ss, then rrr, if a[last] is smallest then other numbers,
** else if a[0] > a[last] we do rr else pb (in sort_a)
*/

static void	sort_ab(t_ar *ar)
{
	int pivot;
	int i;

	pivot = ar->a[ar->sizea - 1];
	i = 0;
	while (i < ar->sizea - 1)
	{


	}
}

static void	push_swap(t_ar *ar)
{
	if (ar->sizea > 1)
	{
		while (!(ar->sizeb == 0 && issorted(ar->a, ar->sizea, 'a')))
		{
			if (ar->sizeb > 1 && ar->sizea > 1)
				sort_ab(ar);
			if (ar->sizeb > 1)
				sort_b;
			if (ar->sizea > 1)
				sort_a;
			if (issorted(ar->a, ar->sizea, 'a') && ar->sizeb > 0)
				push_ab(ar, 'a');
			else if (!(issorted(ar->a, ar->sizea, 'a')))
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
