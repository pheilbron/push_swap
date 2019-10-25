/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:52:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 16:38:59 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_string.h"
#include "ft_error.h"

t_ps_option		g_options_tab[] =
{
    {'c', _C, "color"},
    {'d', _D, "debug"},
    {'i', _I, "input-file="},
    {'o', _O, "output-file="},
    {'v', _V, "visual"},
    {0, 0, 0, 0}
};

static int	set_ps_option(t_ps_context *c, char op)
{
	int	i;

	i = 0;
	while (g_options_tab[i].op)
	{
		if (g_options_tab[i].op == op)
		{
			c->flag |= g_options_tab[i].flag;
			return (c->e.no = 1);
		}
		i++;
	}
	c->e.data = &op;
	return (c->e.no = INV_OPTION);
}

static int	set_ps_long_option(t_ps_context *c, char *option)
{
	int	i;

	i = 0;
	while (g_options_tab[i].op)
	{
		if (ft_strcmp(g_options_tab[i].long_op, option) == 0)
		{
			c->flag |= g_options_tab[i].flag;
			return (c->e.no = 1);
		}
		i++;
	}
	c->e.data = option;
	return (c->e.no = INV_LONG_OPTION);
}

int			parse_options(t_ps_context *c, char ***data, int *len)
{
	int	data_i;

	while (len > 0 && (**data)[0] == '-')
	{
		data_i = 1;
		if ((**data)[data_i] && (**data)[data_i] == '-')
			if (set_ps_long_option(c, (**data) + ++data_i) < 0)
				return (c->e.no);
		while ((**data)[data_i])
			if (set_ps_option(c, (**data)[data_i++]) < 0)
				return (c->e.no);
		(**data)++;
		len--;
	}
	return (c->e.no = 1);
}

int			parse_commands(t_ps_context *c, char *data)
{
	
