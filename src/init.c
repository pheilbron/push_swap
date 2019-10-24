/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:34:39 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 14:12:38 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_context.h"

t_ps_context	*init_ps_context(void)
{
	t_ps_context	*ret;

	ret->a = NULL;
	ret->b = NULL;
	ret->commands = NULL;
	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	if (!(ret->a = ft_stack_init()))
		return (free_ps_context(ret));
	if (!(ret->b = ft_stack_init()))
		return (free_ps_context(ret));
	if (!(ret->commands = ft_stack_init()))
		return (free_ps_context(ret));
	return (ret);
}
