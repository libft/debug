CPPFLAGS := -I../../src
DEBUG_FILES := ../../src/debug_assert_internal.c ../../src/debug_print_stacktrace_internal.c
DEBUG_FILES_FAKE := ../../src/ft_debug_fake.c

.PHONY: all clean fclean re test
all: test
clean:
	@rm -f normal debug release
fclean: clean
re:
	@$(MAKE) fclean
	@$(MAKE) all
test: test_normal test_debug test_release
	@echo "OK!"

.PHONY: test_normal test_debug test_release
test_normal test_debug test_release: test_%: %
	@echo "Running test for $< mode ..."
	@./$< < data/$<.input.txt | diff data/$<.output.txt -

normal: main.c $(DEBUG_FILES_FAKE)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^
debug: main.c $(DEBUG_FILES)
	@printf '#include "prelude_debug.h"\n' | cat - main.c | $(CC) $(CFLAGS) $(CPPFLAGS) -x c - -o $@ $(DEBUG_FILES)
release: main.c
	@printf '#include "prelude_release.h"\n' | cat - $< | $(CC) $(CFLAGS) $(CPPFLAGS) -x c - -o $@
