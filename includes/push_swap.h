/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:47:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/13 11:05:53 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>


typedef struct	s_ar
{
	int			*a;
	int			*b;
	int			sizea;
	int			sizeb;
}				t_ar;

/*
** Rules
*/

void	swap(int *ar, int size);
void	swap_ab(t_ar *ar);
void	push(int *a, int *b, int *size, int *sizeb);
void	push_ab(t_ar *ar, char c);
void	rotate(int *ar, int size);
void	rotate_ab(t_ar *ar);
void	rrotate(int *ar, int size);
void	rrotate_ab(t_ar *ar);

/*
** Help functions
*/

int		issorted(int *a, int size, char c);
int		readnumbers(int argc, char **argv, int *a);
void	free_struct(t_ar **ar);
t_ar	*init_ar(int size);
void	print(int *a, int size);

#endif
