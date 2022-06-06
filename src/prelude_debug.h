#include <stdio.h>

#include "ft_exception.h"

// prevent including fake header
#define FT_DEBUG_PRELUDE_H

// type definitions
#define t_exception \
	t_exception_stacktrace_node exception_stacktrace_node = {parent_exception->stacktrace, __FILE__, __LINE__, __func__}; \
	t_exception_internal
#define EXCEPTION_STACKTRACE_NODE &exception_stacktrace_node

// function prototypes
#define debug_printf(...) ((void) printf(__VA_ARGS__))
#define debug_assert(c, m) debug_assert_internal((c), #c, m, __FILE__, __LINE__, __func__)
void debug_assert_internal(int must_be_true, const char *expression, const char *message, const char *file, int line, const char *function);
#define debug_print_stacktrace(ex) debug_print_stacktrace_internal(ex, __FILE__, __LINE__, __func__)
void debug_print_stacktrace_internal(t_exception_internal *exception, const char *file, unsigned int line, const char *function);
