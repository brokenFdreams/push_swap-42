/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:59:18 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/16 15:12:16 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_strddel(char **argv)
{
	int i;

	if (argv == NULL)
		return ;
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

/*
** Count words in str
*/

static int	ft_wordcounter(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (s[i] != c && i == 0))
			count++;
		i++;
	}
	return (count);
}

/*
** Check is int or not
*/

static int	isint(char *str)
{
	long int	num;
	int			sign;

	num = 0;
	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		str++;
		if (!((num * sign) <= 2147483647 && (num * sign) >= -2147483648))
			return (0);
	}
	return ((num * sign) <= 2147483647 && (num * sign) >= -2147483648);
}

/*
** Check this number was in array
*/

static int	isduplicate(int *a, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (a[i] == a[j])
			return (0);
		j++;
	}
	return (1);
}

/*
** Read arguments and check it
*/

int			readnumbers(int argc, char **argv, t_ar *ar)
{
	int	flag;
	int i;

	flag = 0;
	if (argc == 1)
	{
		argc = ft_wordcounter(argv[0], ' ');
		argv = ft_strsplit(argv[0], ' ');
		flag = 1;
	}
	i = -1;
	ar = init_ar(ar, argc);
	while (++i < argc)
	{
		ar->a[i] = ft_atoi(argv[i]);
		if (!isint(argv[i]) || !isduplicate(ar->a, i))
		{
			if (flag)
				ft_strddel(argv);
			return (0);
		}
	}
	if (flag)
		ft_strddel(argv);
	return (1);
}
