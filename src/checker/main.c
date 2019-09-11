/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:57:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/10 18:00:42 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_stdio.h"

int	main(int ac, char **av)
{
	t_ps_context	*c;
	int				last_command;

	c = init_ps_context;
	if (ac > 1)
	{
		parse_options(c, &av, ac);
		if (init_stack(c->a, av, ac))
		{
			if (c->options)
			parse_commands(c);
			while (get_next_line(1, buffer))
			{
				last_command = parse_commands(c, buffer);
				if ((c->options & _V) == _V)
					print_stacks(c, last_command);
			}
			print_status(c->options);
		}
	}
	ft_printf("\n");
	return (0);
}
