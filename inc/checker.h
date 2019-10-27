/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:13:07 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 13:15:50 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdint.h>
# include "ps_context.h"
# include "ft_stack.h"

int		init_stack(t_ps_stack *a, char **data, int len);
int		parse_options(t_ps_context *c, char ***data, int *len);
int		parse_commands(t_ps_context *c, char *data, int *last_command);
int		check_stacks(t_ps_context *c);
int		update_stacks(t_ps_context *c);
void	print_stacks(t_ps_context *c, int last_command);
void	print_status(uint8_t status);

#endif
