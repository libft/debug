TEST_RULES := all clean fclean re test
Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

.PHONY: $(TEST_RULES)
$(TEST_RULES): %:
	$Q$(MAKE) -C test $@

.PHONY: clean_self
clean: clean_self
clean_self:
	$Qrm -rf tmp
.PHONY: fclean_self
fclean: fclean_self
fclean_self: clean_self
	$Qrm -rf out
.PHONY: build
all test: %: build
build:
	$Q$(MAKE) fclean_self
	$Q$(MAKE) out/additional_normal.a
	$Q$(MAKE) out/additional_debug.a
	$Qcp src/ft_debug_prelude.h src/ft_exception.h src/prelude_debug.h src/prelude_release.h out

out tmp: %:
	$Qmkdir -p $@
%.a:
	$Q$(AR) rcs $@ $^
tmp/%.o: src/%.c | tmp
	$Q$(CC) $(CFLAGS) -c -o $@ $<
out/additional_normal.a: tmp/ft_debug_fake.o | out
out/additional_debug.a: tmp/debug_assert_internal.o tmp/debug_print_stacktrace_internal.o | out
