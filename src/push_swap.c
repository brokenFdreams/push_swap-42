/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:39:07 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/16 10:59:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			findindexmax(int *b, int size, int max)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (b[i] == max)
			return (i);
		i++;
	}
	return (-1);
}

/*
** looking for new max
*/

int			findnewmax(t_ar *ar)
{
	int i;
	int max;

	i = 0;
	while ((max = ar->b[i]) >= ar->max[4])
		i++;
	while (i < ar->sizeb)
	{
		if (max < ar->b[i] && ar->b[i] < ar->max[4])
			max = ar->b[i];
		i++;
	}
	return (max);
}

static void maxs_help(t_ar *ar, int count, int max)
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
