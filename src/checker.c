/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:05:21 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/25 12:06:30 by fsinged          ###   ########.fr       */
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
	char	*line;
	int		i;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "") == 0)
		{
			ft_strdel(&line);
			break ;
		}
		i = check_word(line, ar);
		ft_strdel(&line);
		if (i == 0)
			return (2);
	}
	return (issorted(ar->a, ar->sizea, 'a') && ar->sizeb == 0 ? 1 : 0);
}

int			main(int argc, char **argv)
{
	t_ar	*ar;
	int		i;

	if (argc == 1)
		return (0);
	ar = (t_ar*)malloc(sizeof(t_ar));
	if (readnumbers(argc - 1, argv + 1, ar))
	{
		i = checker(ar);
		if (i == 0)
			write(1, "KO\n", 3);
		else if (i == 1)
			write(1, "OK\n", 3);
		else if (i == 2)
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	free_struct(&ar);
	return (0);
}
