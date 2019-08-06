/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:29:00 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 16:07:05 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *ar, int size)
{
	int temp;

	if (size > 1)
	{
		temp = ar[0];
		ar[0] = ar[1];
		ar[1] = temp;
	}
}

void	swap_ab(t_ar *ar)
{
	swap(ar->a, ar->sizea);
	swap(ar->b, ar->sizeb);
}
