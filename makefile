# 
# Makefile for metamorph
# 
# Compiler: g++
# Linker: lnk
# 

BUILD_NUMBER_FILE=build-number.txt

all: metamorph

metamorph: main.o interface.o pe.o blocks.o
	g++ -o metamorph main.o interface.o pe.o blocks.o

main.o: main.c
	g++ -Wall -c -o main.o main.c

interface.o: interface.c
	g++ -Wall -c -o interface.o interface.c

pe.o: pe.c
	g++ -Wall -c -o pe.o pe.c

blocks.o: blocks.c
	g++ -Wall -c -o blocks.o blocks.c
