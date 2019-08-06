/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:05:21 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/06 15:28:08 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_word(char *str)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(a, sizea);
	else if (ft_strcmp(line, "sb") == 0)
		swap(b, sizeb);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(a, b, sizea, sizeb);
	else if (ft_strcmp(line, "pa") == 0)
		push(a, b, &sizea, &sizeb);
	else if (ft_strcmp(line, "pb") == 0)
		push(b, a, &sizeb, &sizea);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a, sizea);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b, sizeb);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_ab(a, b, sizea, sizeb);
	else if (ft_strcmp(line, "rra") == 0)
		rrotate(a, sizea);
	else if (ft_strcmp(line, "rrb") == 0)
		rrotate(b, sizeb);
	else if (ft_strcmp(line, "rrr") == 0)
		rrotate_ab(a, b, sizea, sizeb);
	else
		return (0);
	return (1);
}

static int	checker(int *a, int sizea)
{
	int		*b;
	int		sizeb;
	int		fd;
	char	*line;

	b = (int*)malloc(sizeof(int) * sizea);
	sizeb = 0;
	fd = 0;
	while (get_next_line(fd, &line))
	{
		if (check_word(line) == 0)
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	free(b);
	b = NULL;
	return (issorted(a, sizea));
}

int			main(int argc, char **argv)
{
	int *a;

	a = (int*)malloc(sizeof(int) * (argc - 1));
	if (readnumbers(argc, argv, a) != 0)
	{
		if (checker(a, argc - 1) == 0)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else
		write(1, "Error\n", 6);
	print(a, argc - 1);
	free(a);
	a = NULL;
	return (0);
}
