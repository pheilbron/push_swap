/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:10:00 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/28 14:50:44 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_options.h"
#include "ft_printf.h"

void	print_status(uint8_t status)
{
	if ((status & SORTED) == SORTED)
		ft_printf("OK");
	else
		ft_printf("KO");
}

void	print_stacks(t_ps_context *c, int last_command)
{
	int		max_len;
	ps_node	*stack_a;
	ps_node	*stack_b;

	max_len = last_command;
	max_len = ft_max(c->a->size, c->b->size);
	stack_a = c->a->top;
	stack_b = c->b->top;
	while (max_len > 0)
	{
		ft_printf("% 9.d\t% 9.d\n",
				max_len <= c->a->size ? stack_a->content : 0,
				max_len <= c->b->size ? stack_b->content : 0);
		if (max_len <= c->a->size)
			stack_a = ps_stack_get_next(stack_a);
		if (max_len <= c->b->size)
			stack_b = ps_stack_get_next(stack_b);
		max_len--;
	}
	ft_printf("---------\t---------\n");
	ft_printf(" STACK A \t STACK B\n");
}

//static char	*get_spacing(t_ps_context *c)
//{
//	int			a;
//	int			b;
//	t_dstring	*spacing;
//
//	max_a = get_itoa_len(ft_stack_max(c->a));
//	max_b = get_itoa_len(ft_stack_max(c->b));
//	spacing = ft_dstr_init();
//	ft_dstr_addf(spacing, "%%%dd %%%dd", ft_max(max_a, max_b),
//			ft_max(max_a, max_b));
//	return (ft_dstr_release(spacing));
//}
//
//void	print_stacks(t_ps_context *c, int last_command)
//{
//	int			i;
//	char		*spacing;
//	t_dstring	*output;
//
//	i = 0;
//	output = ft_dstr_init();
//	spacing = get_spacing(c);
//	while (i < len)
//		get_row(output, c, i++, spacing);
//	get_bottom_row(output, c, spacing);
//	ft_printf("%s", ft_dstr_release(output));
//	free(spacing);
//}
