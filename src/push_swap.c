/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:39:07 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/16 12:08:42 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	maxs_help(t_ar *ar, int count, int max)
{
	int i;

	i = ar->sizemax;
	while (count < i)
	{
		ar->max[i] = ar->max[i - 1];
		i--;
	}
	ar->max[count] = max;
}

static void	maxs(t_ar *ar)
{
	int	i;

	i = 0;
	while (i < ar->sizea)
	{
		if (ar->max[0] < ar->a[i])
			maxs_help(ar, 0, ar->a[i]);
		else if (ar->max[1] < ar->a[i])
			maxs_help(ar, 1, ar->a[i]);
		else if (ar->max[2] < ar->a[i])
			maxs_help(ar, 2, ar->a[i]);
		else if (ar->max[3] < ar->a[i])
			maxs_help(ar, 3, ar->a[i]);
		else if (ar->max[4] < ar->a[i])
			maxs_help(ar, 4, ar->a[i]);
		else if (ar->max[5] < ar->a[i])
			maxs_help(ar, 5, ar->a[i]);
		i++;
	}
}

static void	push_swap(t_ar *ar)
{
	if (ar->sizea > 1)
	{
		maxs(ar);
		sort(ar);
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
