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
build: test
	$Q$(MAKE) fclean_self
	$Q$(MAKE) out/ft_debug_prelude.h
	$Q$(MAKE) out/additional_normal.a
	$Q$(MAKE) out/additional_debug.a
out tmp: %:
	$Qmkdir -p $@
out/ft_debug_prelude.h: src/ft_debug_prelude.h | out
	$Qcp $< $@
%.a:
	$Q$(AR) rcs $@ $^
tmp/%.o: src/%.c | tmp
	$Q$(CC) $(CFLAGS) -c -o $@ $<
out/additional_normal.a: tmp/ft_debug_fake.o
out/additional_debug.a: tmp/debug_assert_internal.o tmp/debug_print_stacktrace_internal.o
