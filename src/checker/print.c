/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:10:00 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/08 14:53:24 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"

void	print_status(uint8_t status)
{
	if ((options & SORTED) == SORTED)
		ft_printf("OK");
	else
		ft_printf("KO");
}

static char	*get_spacing(t_ps_context *c)
{
	int			a;
	int			b;
	t_dstring	*spacing;

	max_a = get_itoa_len(ft_stack_max(c->a));
	max_b = get_itoa_len(ft_stack_max(c->b));
	spacing = ft_dstr_init();
	ft_dstr_addf(spacing, "%%%dd %%%dd", ft_max(max_a, max_b),
			ft_max(max_a, max_b));
	return (ft_dstr_release(spacing));
}

void	print_stacks(t_ps_context *c, int last_command)
{
	int			i;
	char		*spacing;
	t_dstring	*output;

	i = 0;
	output = ft_dstr_init();
	spacing = get_spacing(c);
	while (i < len)
		get_row(output, c, i++, spacing);
	get_bottom_row(output, c, spacing);
	ft_printf("%s", ft_dstr_release(output));
	free(spacing);
}