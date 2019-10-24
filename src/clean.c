/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:12:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 14:12:29 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_context.h"

void	*free_ps_context(t_ps_context *c)
{
	if (c->a)
		ft_stack_del(c->a);
	if (c->b)
		ft_stack_del(c->b);
	if (c->commands)
		ft_stack_del(c->commands);
	free(c);
	return (NULL);
}