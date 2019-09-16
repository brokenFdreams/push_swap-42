/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:16:08 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/16 15:10:56 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort for 3 elements
*/

void		small_sort(int *a, int size)
{
	if (size == 2 && a[0] > a[1])
		swap(a, size, 1);
	while (!(issorted(a, size, 'a')))
	{
		if (a[0] > a[1] && a[0] > a[2])
			rotate(a, size, 1);
		else if (a[0] > a[1] && a[0] < a[2])
			swap(a, size, 1);
		else
			rrotate(a, size, 1);
	}
}

static void	push_swap(t_ar *ar)
{
	if (issorted(ar->a, ar->sizea, 'a'))
		return ;
	if (ar->sizea < 3)
		small_sort(ar->a, ar->sizea);
	else if (ar->sizea < 10)
		sort(ar);
	else
		big_sort(ar, get_avg(ar->a, ar->sizea));
}

int			main(int argc, char **argv)
{
	t_ar	*ar;

	if (argc == 1)
		return (0);
	ar = (t_ar*)malloc(sizeof(t_ar));
	if (readnumbers(argc - 1, argv + 1, ar))
		push_swap(ar);
	else
		write(1, "Error\n", 6);
	free_struct(&ar);
	return (0);
}
