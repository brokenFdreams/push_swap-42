/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:16:08 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/03 12:50:38 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort for 3 elements
*/

static void	small_sort(t_ar *ar)
{
	while (!(issorted(a, size, 'a')))
	{
		if (a[0] > a[1] && a[0] > a[2])
			rotate(a, size, 1);
		else if (a[0] > a[1] && a[0] < a[2])
			swap(a, size, 1);
		else
			rrotate(s, size, 1);
	}
}

/*
** Sort for less elements, then 10 and more then 3
*/

static void	sort(t_ar *ar)
{

}

/*
** Sort for more elements, then 10
*/

static void	big_sort(t_ar *ar)
{
	
}

static void	push_swap(t_ar *ar)
{
	if (ar->sizea < 10)
		sort(ar);
	else
	{
		ar->max[0] = search_middle(ar);
		big_sort(ar);
		
	}
}

int 		main(int argc, char **argv)
{
	t_ar	*ar;

	if (argc == 1)
		return (0);
	ar = init_ar(argc - 1);
	if (readnumbers(argc - 1, argv + 1, ar->a) != 0 && ar->sizea > 1)
		push_swap(ar);
	else
		write(1, "Error\n", 6);
	free_struct(&ar);
	return (0);
}
