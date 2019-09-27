/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:05:21 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/27 12:58:21 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(int num)
{
	write(1, "\t[", 3);
	ft_putnbr(num);
	write(1, "]\t", 3);
}

static void	ft_print(t_ar *ar)
{
	int sa;
	int size;

	sa = -1;
	usleep(110000);
	system("clear");
	size = ar->sizea + ar->sizeb;
	while (++sa < size)
	{
		if (sa < ar->sizea)
			print(ar->a[sa]);
		else
			write(1, "\t[ ]\t", 5);
		if (sa < ar->sizeb)
			print(ar->b[sa]);
		else
			write(1, "\t[ ]\t", 5);
		write(1, "\n", 1);
	}
}

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

static int	checker(t_ar *ar, int flag)
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
		if (flag)
			ft_print(ar);
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
	int		flag;

	if (argc == 1)
		return (0);
	flag = 0;
	ar = (t_ar*)malloc(sizeof(t_ar));
	if (ft_strequ(argv[1], "-v") && argv++ && argc--)
		flag = 1;
	if (readnumbers(argc - 1, argv + 1, ar))
	{
		ft_putnbr(ar->sizeb);
		i = checker(ar, flag);
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
