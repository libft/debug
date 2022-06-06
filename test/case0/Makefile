Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

CC := clang

CPPFLAGS := -I../../out

SRCS := $(shell find . -name "*.c")
OBJS := $(patsubst ./%.c,tmp/%.o,$(SRCS))

.PHONY: all clean fclean re test
all: test
clean:
	$Qrm -rf tmp normal debug release
fclean: clean
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
test: test_normal test_debug test_release
	$Qecho "OK!"

.PHONY: test_normal test_debug test_release
test_normal test_debug test_release: test_%: %
	$Qecho "Running test for $< mode ..."
	$Q./$< < data/$<.input.txt | diff data/$<.output.txt -

tmp:
	$Qmkdir -p $@
$(OBJS:.o=.normal.o): tmp/%.normal.o: %.c | tmp
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
$(OBJS:.o=.debug.o): tmp/%.debug.o: %.c | tmp
	$Qprintf '#include "prelude_debug.h"\n' | cat - $< | $(CC) $(CFLAGS) $(CPPFLAGS) -x c -c - -o $@
$(OBJS:.o=.release.o): tmp/%.release.o: %.c | tmp
	$Qprintf '#include "prelude_release.h"\n' | cat - $< | $(CC) $(CFLAGS) $(CPPFLAGS) -x c -c - -o $@

normal debug release: %:
	$Q$(CC) $(LDFLAGS) -o $@ $^
normal: $(OBJS:.o=.normal.o) ../../out/additional_normal.a
debug: $(OBJS:.o=.debug.o) ../../out/additional_debug.a
release: $(OBJS:.o=.release.o)
