/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:12:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:29:20 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_context.h"
#include "ps_stack.h"

void	*free_ps_context(t_ps_context *c)
{
	if (c->a)
		ps_stack_del(c->a);
	if (c->b)
		ps_stack_del(c->b);
	if (c->commands)
		ps_stack_del(c->commands);
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
