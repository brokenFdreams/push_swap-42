/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:47:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 13:49:58 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	swap(int *ar, int size);
void	swap_ab(int *a, int *b, int sizea, int sizeb);
void	push(int *a, int *b, int *size, int *sizeb);
void	rotate(int *ar, int size);
void	rotate_ab(int *a, int *b, int sizea, int sizeb);
void	rrotate(int *ar, int size);
void	rrotate_ab(int *a, int *b, int sizea, int sizeb);

#endif
