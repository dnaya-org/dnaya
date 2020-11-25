HEADERS := $(shell find include -name \*.[ch]pp)
SRC := $(shell find test tools -name \*.[ch]pp) $(HEADERS)

all:
	@echo Please, use CMake instead.

format:
	@echo Formatting source...
	@clang-format -i -style=file $(SRC)

clean:
	@echo Cleaning gcov files...
	@find . -name '*.gcno' -exec rm {} \;
	@find . -name '*.gcda' -exec rm {} \;
	@find . -name '*.gcov' -exec rm {} \;

.PHONY: format clean
