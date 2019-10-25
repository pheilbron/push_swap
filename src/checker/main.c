/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:57:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 14:27:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_context.h"
#include "ps_options.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_printf.h"

void	print_all_stacks(t_ps_context *c)
{
	t_dl_node	*n;

	n = c->a->top;
	ft_printf("A\n");
	while (n)
	{
		ft_printf("%p\t%d\n", n, *(int *)n->content);
		n = ft_stack_get_next(n);
	}
	n = c->b->top;
	ft_printf("B\n");
	while (n)
	{
		ft_printf("%d\n", *(int *)n->content);
		n = ft_stack_get_next(n);
	}
	n = c->commands->top;
	ft_printf("Commands\n");
	while (n)
	{
		ft_printf("%d\n", *(int *)n->content);
		n = ft_stack_get_next(n);
	}
}

int	main(int ac, char **av)
{
	t_ps_context	*c;
	int				last_command;
	char			*buffer;

	if (ac > 1 && (c = init_ps_context()))
	{
		if (parse_options(c, &av, &ac) && init_stack(c->a, av, ac))
		{
			print_all_stacks(c);
			while (get_next_line(1, &buffer))
			{
				last_command = parse_commands(c, buffer);
				if ((c->options & SLOW) > 0)
					if(update_stacks(c))
						break ;
				if ((c->options & _V) == _V)
					print_stacks(c, last_command);
			}
			if (update_stacks(c))
				print_status(check_stacks(c));
		}
		else
			ft_printf("Error");
		free_ps_context(c);
	}
	ft_printf("\n");
	return (0);
}
