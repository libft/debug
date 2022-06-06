/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_stacktrace_internal.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:23:23 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 15:44:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_debug_prelude.h"

static unsigned int	debug_print_stacktrace_node(t_exception_stacktrace_node *node) {
	if (!node)
		return 0;
	int depth = debug_print_stacktrace_node(node->parent);
	printf("%d | %s:%u: %s\n", depth, node->file, node->line - 1, node->function);
	return depth + 1;
}

void	debug_print_stacktrace_internal(t_exception_internal *exception, const char *file, unsigned int line, const char *function) {
	int depth = debug_print_stacktrace_node(exception->stacktrace);
	printf("%d | %s:%u: %s\n", depth, file, line - 1, function);
}
