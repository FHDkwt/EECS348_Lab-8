# Makefile for EECS 348 Lab 8
# Default target
all: build
# Building project
build:
	mkdir -p build
	cd build && cmake .. && make
# Run main program
run: build
	./build/matrix_operations
# Run tests
test: build
	./build/tests/matrix_tests
# Clean up
clean:
	rm -rf build
# Phony targets
.PHONY: all build run test clean
