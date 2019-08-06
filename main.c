/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:57:35 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 12:09:51 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printmas(int *ar, int size)
{
	int i = 0;

	while (i < size)
	{
		if (i != size - 1)
			printf("%d ", ar[i]);
		else
			printf("%d\n", ar[i]);
		i++;
	}
}

int	main(void)
{
	int a[] = {0, 1, 2, 3, 4 ,5};
	int size = 6;
	int b[] = {5, 4, 3, 2, 1, 0};
	int sizeb = 6;
	
	printf("swap_a\n");
	printmas(a, size);
	swap(a);
	printmas(a, size);
	printf("rotate_a\n");
	rotate(a, size);
	printmas(a, size);
	printf("rrotate_a\n");
	rrotate(a, size);
	printmas(a, size);
	printf("rotate_ab\nb:");
	printmas(b, sizeb);
	rotate_ab(a, b, size, sizeb);
	printf("a:");
	printmas(a, size);
	printf("b:");
	printmas(b, sizeb);
	printf("rrotate_ab\n");
	rrotate_ab(a, b, size, sizeb);
	printf("a:");
	printmas(a, size);
	printf("b:");
	printmas(b, sizeb);
	return (0);
}
