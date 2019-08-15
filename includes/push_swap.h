/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:47:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/15 16:34:00 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

# include <stdio.h>

typedef struct	s_ar
{
	int			*a;
	int			*b;
	int			sizea;
	int			sizeb;
	int			*max;
	int			sizemax;
}				t_ar;

/*
** Rules
*/

void	swap(int *ar, int size, int h);
void	swap_ab(t_ar *ar, int h);
void	push(int *a, int *b, int *size, int *sizeb);
void	push_ab(t_ar *ar, char c);
void	rotate(int *ar, int size, int h);
void	rotate_ab(t_ar *ar, int h);
void	rrotate(int *ar, int size, int h);
void	rrotate_ab(t_ar *ar, int h);

/*
** Help functions
*/

int		issorted(int *a, int size, char c);
int		readnumbers(int argc, char **argv, int *a);
void	free_struct(t_ar **ar);
t_ar	*init_ar(int size);
void	print(int *a, int size);
int		findindexmax(int *b, int size, int max);
int		findnewmax(t_ar *ar);
void	sort(t_ar *ar);

#endif
