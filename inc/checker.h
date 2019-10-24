/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:13:07 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 13:33:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdint.h>
# include "ps_context.h"

int		init_ps_context(void);
int		init_stack(t_stack *a, char **data, int len);
int		parse_options(t_ps_context *c, char ***data, int *len);
int		parse_commands(t_ps_context *c, char *data);
int		check_stacks(t_ps_context *c);
void	update_stacks(t_ps_context *c);
void	print_stacks(t_ps_context *c, int last_command);
void	print_status(uint8_t status);
void	free_ps_context(t_ps_context *c);

#endif
