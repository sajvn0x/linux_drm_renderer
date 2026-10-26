run: compile
	@./main

compile:
	@clang++ src/main.cc -o main `pkg-config --cflags --libs libdrm libdrm`

fmt:
	@find src/ -iname '*.hh' -o -iname '*.cc' | xargs clang-format -i
