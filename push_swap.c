/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:21:00 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 15:24:05 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int *a, int size)
{
	
}

int			main(int argc, char **argv)
{
	int *a;

	a = (int*)malloc(sizeof(int) * (argc - 1));
	if (readnumbers(argc, argv, a) != 0)
		push_swap(a, argc - 1);
	else
		write(1, "Error\n", 6);
	print(a, argc - 1);
	free(a);
	a = NULL;
	return (0);
}
