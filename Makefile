run: build
	./main

build:
	clang src/main.c -o main
