/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:39:15 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 15:48:21 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

typedef struct	s_ps_node
{
	int					content;
	struct s_ps_node	*prev;
	struct s_ps_node	*next;
}				t_ps_node;

typedef struct	s_ps_stack
{
	t_ps_node	*top;
	t_ps_node	*bottom;
	int			size;
}				t_ps_stack;

int				ps_stack_is_empty(t_ps_stack *stack);
t_ps_stack		*ps_stack_init(void);
void			ps_stack_enqueue(t_ps_stack *stack, void *content);
t_ps_node		*ps_stack_get_next(t_ps_node *node);
t_ps_node		*ps_stack_get_prev(t_ps_node *node);
void			*ps_stack_push(t_ps_stack *stack, void *content);
void			*ps_stack_pop(t_ps_stack *stack);
void			*ps_stack_drop(t_ps_stack *stack);
void			*ps_stack_peek(t_ps_stack *stack);
void			ps_stack_del(t_ps_stack *stack);

#endif
