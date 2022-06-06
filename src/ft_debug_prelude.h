/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_prelude.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:49:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 15:20:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_PRELUDE_H
# define FT_DEBUG_PRELUDE_H

# include "ft_exception.h"

typedef t_exception_internal	t_exception;
# define EXCEPTION_STACKTRACE_NODE NULL

void	debug_printf(const char *format, ...);
void	debug_assert(int condition, const char *message);
void	debug_print_stacktrace(t_exception_internal *exception);

#endif
