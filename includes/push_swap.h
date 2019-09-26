/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:47:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/26 13:14:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

void			swap(int *ar, int size, int h);
void			swap_ab(t_ar *ar, int h);
void			push(int *a, int *b, int *size, int *sizeb);
void			push_ab(t_ar *ar, char c);
void			rotate(int *ar, int size, int h);
void			rotate_ab(t_ar *ar, int h);
void			rrotate(int *ar, int size, int h);
void			rrotate_ab(t_ar *ar, int h);

/*
** functions.c
*/

int				issorted(int *a, int size, char c);
void			free_struct(t_ar **ar);
t_ar			*init_ar(t_ar *ar, int size);

int				readnumbers(int argc, char **argv, t_ar *ar);
void			small_sort(int *a, int size);
void			sort(t_ar *ar);
void			big_sort(t_ar *ar, int avg);

/*
** help.c
*/

int				get_avg2(int *a, int size, int avg, int flag);
int				get_avg(int *a, int size);
int				get_max(int *b, int size);
int				get_min(int *b, int size);
int				*get_maxs(int *ar, int size, int *max);
int				*get_mins(int *ar, int size, int *min);

/*
** pusher.c
*/

int				count_avg(int *a, int size, int avg, int flag);
void			push_a_first(t_ar *ar, int avg, int *min, int *cnt);

#endif
