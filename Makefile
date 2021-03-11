LIB := $(shell find src -name \*.[ch]pp)
SRC := $(shell find test tools -name \*.[ch]pp) $(LIB)
CLANG_STYLE := file

all: compile

generate-make:
	@cmake -H. -Bbuild -DDNAYA_BUILD_TEST=on

compile: generate-make
	@make --quiet -C build

check: compile
	@./build/test/dnaya_test_suite

format:
	@echo Formatting source...
	@clang-format -i -style=$(CLANG_STYLE) $(SRC)

clean:
	@echo Cleaning gcov files...
	@find . -name '*.gcno' -exec rm {} \;
	@find . -name '*.gcda' -exec rm {} \;
	@find . -name '*.gcov' -exec rm {} \;
	@rm -rf build;

.PHONY: format clean
