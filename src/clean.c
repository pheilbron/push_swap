/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:12:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 12:46:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_context.h"
#include "ft_stack.h"

void	*free_ps_context(t_ps_context *c)
{
	if (c->a)
		ft_stack_del(c->a, &free);
	if (c->b)
		ft_stack_del(c->b, &free);
	if (c->commands)
		ft_stack_del(c->commands, &free);
	free(c);
	return (NULL);
}

int		free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}
