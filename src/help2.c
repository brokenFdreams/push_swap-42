/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:37:29 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/26 12:52:51 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_avg2(int *a, int size, int avg, int flag)
{
	double	sum;
	int		count;
	int		i;

	i = -1;
	count = 0;
	sum = 0;
	while (++i < size)
		sum += (((!flag && a[i] < avg) || (flag && a[i] > avg)) && ++count)
			? a[i] : 0;
	if (flag == 0 || flag == 1)
		return ((int)(sum / count - 0.5));
	avg = (int)(sum / count - 0.5);
	i = -1;
	sum = 0;
	count = 0;
	while (++i < size)
		sum += a[i] > avg && ++count ? a[i] : 0;
	return ((int)(sum / count - 0.5));
}
