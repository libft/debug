/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:46:34 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 15:46:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug_prelude.h"

t_err	do_something(t_exception_internal *parent_exception, bool fail)
{
	t_exception	exception;

	exception.stacktrace = EXCEPTION_STACKTRACE_NODE;
	if (fail)
		debug_print_stacktrace(&exception);
	return (!!fail);
}

int	main(void)
{
	t_exception_internal	exception;
	t_err					err;

	exception.stacktrace = NULL;
	debug_printf("Hello world!\n");
	err = do_something(&exception, false);
	debug_assert(!err, "do_something(false) failed");
	err = do_something(&exception, true);
	debug_assert(!err, "do_something(true) failed");
}
