/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:37:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 15:13:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_H
# define FT_EXCEPTION_H

# include <stddef.h>
# include <stdbool.h>

typedef bool	t_err;

typedef struct s_exception_stacktrace_node
{
	struct s_exception_stacktrace_node	*parent;
	const char							*file;
	unsigned int						line;
	const char							*function;
}	t_exception_stacktrace_node;

typedef struct s_exception_internal
{
	t_exception_stacktrace_node	*stacktrace;
}	t_exception_internal;

#endif
