.PHONY: all clean fclean re test
all: test
re:
	@$(MAKE) fclean
	@$(MAKE) all
clean fclean test: %:
	@MAKE='$(MAKE)' sh make.sh $@
