/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_context.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:09:08 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:28:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CONTEXT_H
# define PS_CONTEXT_H

# include <stdint.h>
# include "ft_stack.h"
# include "ft_error.h"

typedef struct	s_ps_context
{
	uint8_t	options;
	t_stack	*a;
	t_stack	*b;
	t_stack	*commands;
	t_error	e;
}				t_ps_context;

t_ps_context	*init_ps_context(void);
void			*free_ps_context(t_ps_context *c);
int				free_tab(char **tab);

#endif
