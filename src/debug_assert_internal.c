#include <stdio.h>
#include <stdlib.h>

void debug_assert_internal(int must_be_true, const char *expression, const char *message, const char *file, unsigned int line, const char *function) {
	if (must_be_true)
		return;
	if (message)
		printf("%s:%u: %s: Assertion `%s` failed: %s\n", file, line - 1, function, expression, message);
	else
		printf("%s:%u: %s: Assertion `%s` failed.\n", file, line - 1, function, expression);
	exit(EXIT_FAILURE);
}
