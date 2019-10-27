/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:52:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 13:07:19 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_context.h"
#include "ps_options.h"
#include "ps_stack.h"
#include "ft_string.h"
#include "ft_error.h"

t_ps_option		g_options_tab[] =
{
	{'c', _C, "color"},
	{'d', _D, "debug"},
	{'i', _I, "input-file="},
	{'o', _O, "output-file="},
	{'v', _V, "visual"},
	{'x', _X, "compact"},
	{0, 0, 0}
};

static int	set_ps_option(t_ps_context *c, char op)
{
	int	i;

	i = 0;
	while (g_options_tab[i].op)
	{
		if (g_options_tab[i].op == op)
		{
			c->options |= g_options_tab[i].flag;
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
			c->options |= g_options_tab[i].flag;
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

	while (--(*len) > 0 && (*(++(*data)))[0] == '-')
	{
		data_i = 1;
		if ((**data)[data_i] && (**data)[data_i] == '-')
			if (set_ps_long_option(c, (**data) + ++data_i) < 0)
				return (c->e.no);
		while ((**data)[data_i])
			if (set_ps_option(c, (**data)[data_i++]) < 0)
				return (c->e.no);
	}
	return (c->e.no = 1);
}

static int	is_valid(char *command, int *c)
{
	int	cmd;
	int	i;

	cmd = 0;
	i = -1;
	while (command[++i])
		cmd += command[i] == 'r' ? 'u' : command[i];
	if (cmd != ('s' + 'a') && cmd != ('s' + 'b') && cmd != ('s' + 's')
			&& cmd != ('p' + 'a') && cmd != ('p' + 'b') && cmd != ('u' + 'a')
			&& cmd != ('u' + 'b') && cmd != ('u' + 'u')
			&& cmd != ('u' + 'u' + 'a') && cmd != ('u' + 'u' + 'b')
			&& cmd != ('u' + 'u' + 'u'))
		return (0);
	*c = cmd;
	return (1);
}

int			parse_commands(t_ps_context *c, char *data)
{
	int		last_cmd;
	char	**tab;
	int		i;

	last_cmd = 0;
	if ((c->options & _D) == _D)
	{
		tab = ft_strsplit(data, ' ');
		i = 0;
		while (tab[i])
		{
			if ((last_cmd = is_valid(data)))
				ps_stack_enqueue(c->commands, last_cmd);
			else
				return (free_tab(tab));
			i++;
		}
		free_tab(tab);
	}
	else if (is_valid(data, &last_cmd))
		ps_stack_enqueue(c->commands, last_cmd);
	return (last_cmd);
}
