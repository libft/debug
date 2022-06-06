#include <stddef.h>
#include <stdbool.h>

typedef bool	t_err;

// prevent including fake header
#define FT_DEBUG_PRELUDE_H

// fake type definitions
typedef struct { void *stacktrace; } t_exception;
typedef t_exception t_exception_internal;
#define EXCEPTION_STACKTRACE_NODE NULL

// fake function prototypes
#define debug_printf(...) ((void) 0)
#define debug_assert(c, m) ((void) 0)
#define debug_print_stacktrace(ex) ((void) 0)
