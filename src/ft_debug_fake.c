/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_fake.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:52:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/06 15:31:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug_prelude.h"

void	debug_printf(const char *format, ...)
{
	(void)format;
}

void	debug_assert(int condition, const char *message)
{
	(void)condition;
	(void)message;
}

void	debug_print_stacktrace(t_exception_internal *exception)
{
	(void)exception;
}
