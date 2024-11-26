#
# Makefile for Binary Search Tree
#
# Homework 3 (fall 2021)
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 


main: main.o BinarySearchTree.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

unit_test: unit_test_driver.o BinarySearchTree.o 
	${CXX} ${LDFLAGS} unit_test_driver.o BinarySearchTree.o

clean:
	rm -rf main *.o *.dSYM


