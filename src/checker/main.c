/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:57:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/23 22:05:14 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"

int	main(int ac, char **av)
{
	t_ps_context	*c;
	int				last_command;
	char			*buffer;

	c = init_ps_context;
	if (ac > 1)
	{
		if (parse_options(c, &av, &ac) && init_stack(c->a, av, ac))
		{
			while (get_next_line(1, &buffer))
			{
				last_command = parse_commands(c, buffer);
				if ((c->options & SLOW) > 0)
					update_stacks(c);
				if ((c->options & _V) == _V)
					print_stacks(c, last_command);
			}
			update_stacks(c);
			print_status(check_stacks(c));
		}
		else
			ft_printf("Error\n");
	}
	ft_printf("\n");
	return (0);
}
