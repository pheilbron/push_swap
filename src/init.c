/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:34:39 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:11:15 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_context.h"
#include "ps_stack.h"

t_ps_context	*init_ps_context(void)
{
	t_ps_context	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->a = NULL;
	ret->b = NULL;
	ret->commands = NULL;
	if (!(ret->a = ps_stack_init()))
		return (free_ps_context(ret));
	if (!(ret->b = ps_stack_init()))
		return (free_ps_context(ret));
	if (!(ret->commands = ps_stack_init()))
		return (free_ps_context(ret));
	return (ret);
}
