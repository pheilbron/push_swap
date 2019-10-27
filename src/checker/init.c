/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:20:35 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:22:07 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_context.h"
#include "ps_options.h"
#include "ps_stack.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_ctype.h"

static int	is_valid_arg(char *s, int *n)
{
	int			i;
	long long	num;

	i = 0;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	if ((num = ft_atoll(s)) > INT_MAX || num < INT_MIN)
		return (0);
	*n = num;
	return (1);
}

static int	is_valid_args(t_ps_stack *a, char *s)
{
	char	**tab;
	int		i;
	int		n;

	tab = ft_strsplit(s, ' ');
	i = 0;
	while (tab[i])
	{
		if (is_valid_arg(tab[i], &n))
			ps_stack_enqueue(a, n);
		else
			return (free_tab(tab));
		i++;
	}
	free_tab(tab);
	return (1);
}

int			init_stack(t_ps_stack *a, char **data, int len)
{
	int	i;
	int	n;

	i = 0;
	if (len == 1 && !is_valid_args(a, data[0]))
		return (INV_ARG);
	while (i < len)
	{
		if (is_valid_arg(data[i], &n))
			ps_stack_enqueue(a, n);
		else
			return (INV_ARG);
		i++;
	}
	return (1);
}
