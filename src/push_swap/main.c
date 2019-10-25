/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:57:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:21:46 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_context.h"
#include "ps_options.h"
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
			//solve
		}
		else
			ft_printf("Error");
		free_ps_context(c);
	}
	ft_printf("\n");
	return (0);
}
