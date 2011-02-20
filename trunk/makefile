# 
# Makefile for metamorph
# 
# Compiler: g++
# Linker: lnk
# 

BUILD_NUMBER_FILE=build-number.txt

all: metamorph

metamorph: main.o interface.o
	g++ -o metamorph main.o interface.o

main.o: main.c
	g++ -Wall -c -o main.o main.c

interface.o: interface.c
	g++ -Wall -c -o interface.o interface.c
