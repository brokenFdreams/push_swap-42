/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:33:59 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 14:24:28 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *a, int *b, int *size, int *sizeb)
{
	int tmp;
	int i;

	if (*sizeb > 0)
	{
		tmp = a[0];
		a[0] = b[0];
		i = 1;
		while (i < *size)
		{
			b[0] = a[i];
			a[i] = tmp;
			tmp = b[0];
			i++;
		}
		a[i] = tmp;
		(*size)++;
		(*sizeb)--;
		i = 0;
		while (i < *sizeb)
		{
			b[i] = b[i + 1];
			i++;
		}
	}
}
