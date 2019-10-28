/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:57:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/28 10:39:35 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_context.h"
#include "ps_options.h"
#include "ps_stack.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_ps_context	*c;
	int				last_command;
	char			*buffer;

	if (ac > 1 && (c = init_ps_context()))
	{
		if (parse_options(c, &av, &ac) && init_stack(c->a, av, ac))
		{
			while (get_next_line(1, &buffer))
			{
				if (!parse_commands(c, buffer, &last_command))
					return (ps_fatal_error(c));
				if ((c->options & SLOW) > 0)
					if (update_stacks(c))
						break ;
				if ((c->options & _V) == _V)
					print_stacks(c, last_command);
			}
			if (update_stacks(c))
				print_status(check_stacks(c));
		}
		else
			return (ps_fatal_error(c));
		free_ps_context(c);
	}
	ft_printf("\n");
	return (0);
}
