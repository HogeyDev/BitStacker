CC := g++
CCARGS := -Wall -Werror -Wpedantic -g -lSDL2

.PHONY: clean
all: clean compile run

compile:
	$(CC) src/*.cpp -o build/main -I./src/include $(CCARGS)

run:
	./build/main

bear:
	bear -- make

clean:
	rm -rf build
	mkdir build

debug:
	gdb ./build/main
