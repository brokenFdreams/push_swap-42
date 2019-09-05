/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:24:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/05 12:05:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print(int *a, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (i < size - 1)
			printf("%d ", a[i]);
		else
			printf("%d\n", a[i]);
		i++;
	}
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
** Check for digits
*/

static int	isdigits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

/*
** Reading numbers from args
*/

int			readnumbers(int argc, char **argv, int *a)
{
	int	i;
	int j;

	i = 0;
	while (i < argc)
	{
		if (!isdigits(argv[i]))
			return (0);
		a[i] = ft_atoi(argv[i]);
		j = 0;
		while (j < i)
		{
			if (a[j] == a[i])
				return (0);
			j++;
		}
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
	free((*ar)->max);
	free(*ar);
	ar = NULL;
}

/*
** Initialization of struct t_ar
*/

t_ar		*init_ar(int size)
{
	t_ar	*ar;

	ar = (t_ar*)malloc(sizeof(t_ar));
	ar->sizea = size;
	ar->a = (int*)malloc(sizeof(int) * size);
	ar->sizeb = 0;
	ar->b = (int*)malloc(sizeof(int) * size);
	ar->max = (int*)malloc(sizeof(int) * (size < 3 ? size : 3));
	return (ar);
}
