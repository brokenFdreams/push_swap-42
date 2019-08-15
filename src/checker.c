/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:05:21 by fsinged           #+#    #+#             */
/*   Updated: 2019/08/15 14:36:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_word(char *line, t_ar *ar)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(ar->a, ar->sizea, 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap(ar->b, ar->sizeb, 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(ar, 0);
	else if (ft_strcmp(line, "pa") == 0)
		push(ar->a, ar->b, &(ar->sizea), &(ar->sizeb));
	else if (ft_strcmp(line, "pb") == 0)
		push(ar->b, ar->a, &(ar->sizeb), &(ar->sizea));
	else if (ft_strcmp(line, "ra") == 0)
		rotate(ar->a, ar->sizea, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(ar->b, ar->sizeb, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_ab(ar, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rrotate(ar->a, ar->sizea, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrotate(ar->b, ar->sizeb, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrotate_ab(ar, 0);
	else
		return (0);
	return (1);
}

static int	checker(t_ar *ar)
{
	int		fd;
	char	*line;

	fd = 0;
	while (get_next_line(fd, &line))
	{
		if (check_word(line, ar) == 0)
			break ;
		ft_strdel(&line);
	}
	return (issorted(ar->a, ar->sizea, 'a') && ar->sizeb == 0);
}

int			main(int argc, char **argv)
{
	t_ar	*ar;

	if (argc == 1)
		return (0);
	ar = init_ar(argc - 1);
	if (readnumbers(argc - 1, argv + 1, ar->a) != 0)
	{
		if (checker(ar) == 0)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else
		write(1, "Error\n", 6);
	free_struct(&ar);
	return (0);
}
