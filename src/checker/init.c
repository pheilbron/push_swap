/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:20:35 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:18:15 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_context.h"
#include "ps_options.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_ctype.h"
#include "ft_stack.h"

static int	is_valid_arg(char *s)
{
	int			i;
	long long	num;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if ((num = ft_atoll(s)) > INT_MAX || num < INT_MIN)
		return (0);
	return (num);
}

static int	is_valid_args(t_stack *a, char *s)
{
	char	**tab;
	int		i;
	int		n;

	tab = ft_strsplit(s, ' ');
	i = 0;
	while (tab[i])
	{
		if ((n = is_valid_arg(tab[i])))
			ft_stack_enqueue(a, &n);
		else
			return (free_tab(tab));
		i++;
	}
	free_tab(tab);
	return (1);
}

int			init_stack(t_stack *a, char **data, int len)
{
	int	i;
	int	n;

	i = 0;
	if (len == 1 && !is_valid_args(a, data[0]))
		return (INV_ARG);
	while (i < len)
	{
		if ((n = is_valid_arg(data[i])))
			ft_stack_enqueue(a, &n);
		else
			return (INV_ARG);
		i++;
	}
	return (1);
}
