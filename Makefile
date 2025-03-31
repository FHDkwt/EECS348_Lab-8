# Makefile for EECS 348 Lab 8

# Default target
all: build

# Build the project
build:
	mkdir -p build
	cd build && cmake .. && make

# Run the main program
run: build
	./build/matrix_operations

# Run the tests
test: build
	./build/tests/matrix_tests

# Clean up
clean:
	rm -rf build

# Phony targets
.PHONY: all build run test clean
