/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:24:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/24 11:42:40 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		print(int *a, int size, char *str)
{
	int i;

	i = -1;
	printf("%s", str);
	printf("size=%d\n", size);
	while (++i < size)
		if (i + 1 == size)
			printf("%d\n", a[i]);
		else
			printf("%d ", a[i]);
}

/*
** Check, sorted array or not
*/

int			issorted(int *a, int size, char c)
{
	int i;

	i = 0;
	if (c == 'a')
		while (i < size - 1)
		{
			if (a[i] > a[i + 1])
				return (0);
			i++;
		}
	else
		while (i < size - 1)
		{
			if (a[i] < a[i + 1])
				return (0);
			i++;
		}
	return (1);
}

/*
** Free struct
*/

void		free_struct(t_ar **ar)
{
	free((*ar)->a);
	free((*ar)->b);
	free(*ar);
	ar = NULL;
}

/*
** Initialization of struct t_ar
*/

t_ar		*init_ar(t_ar *ar, int size)
{
	ar->sizea = size;
	ar->a = (int*)malloc(sizeof(int) * size);
	ar->sizeb = 0;
	ar->b = (int*)malloc(sizeof(int) * size);
	return (ar);
}
