/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:05:27 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/10 18:08:40 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_ps_option	g_option_tab[] =
{
	{_V, 'v', "visual"},
	{_C, 'c', "color"},
	{_I, 'i', "input-file"},
	{_O, 'o', "output-file"}
};

static int	set_ps_option(t_ps_context *c, char option)
{
	int	i;

	i = 0;
	while (g_options_tab[i].flag)
	{
		if (g_options_tab[i].op == option)
		{
			c->flag |= g_options_tab[i].flag;
			return (c->e.no = 1);
		}
		i++;
	}
	c->e.data = &option;
	return (c->e.no = INV_OPTION);
}

static int	set_ps_long_option(t_ps_context *c, char *option)
{
	int	i;

	i = 0;
	while (g_options_tab[i].flag)
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

int			parse_options(t_ps_context *c, char **data, int len, int *i)
{
	int	data_i;

	while (*i < len && data[*i][0] == '-')
	{
		data_i = 1;
		if (data[*i][data_i] && data[*i][data_i] == '-')
			if (set_ps_long_option(c, data[*i] + ++data_i) < 0)
				return (c->e.no);
		while (data[*i][data_i])
			if (set_ps_option(c, data[*i][data_i++] < 0))
				return (c->e.no);
		(*i)++;
	}
	return (c->e.no = 1);
}
