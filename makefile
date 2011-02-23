# 
# Makefile for metamorph
# 
# Compiler: g++
# Linker: lnk
# 

C++		= g++		# Use GNU C++ compiler
LINKER		= g++		# Use GNU C++ as linker
LINKER-FLAGS	= -o		# Flags for linker
RM		= rm -f		# Command to remove files
MAKE		= make		# Make utility
OBJS		= main.o	\
		  interface.o	\
		  pe.o		\
		  blocks.o
TARGET		= metamorph	# 
.IGNORE:			# Ignore problems

C++FLAGS	= -DLINUX
ifdef LINUX
	C++FLAGS	= -DLINUX 
endif
ifdef WINDOWS
	C++FLAGS	= -DWINDOWS
	TARGET		= metamorph.exe
endif

all: nasm ndisasm metamorph

metamorph: main.o interface.o pe.o blocks.o
	g++ -o $(TARGET) main.o interface.o pe.o blocks.o

main.o: main.c
	$(C++) -Wall -c -o main.o main.c $(C++FLAGS)

interface.o: interface.c
	$(C++) -Wall -c -o interface.o interface.c $(C++FLAGS)

pe.o: pe.c
	$(C++) -Wall -c -o pe.o pe.c $(C++FLAGS)

blocks.o: blocks.c
	$(C++) -Wall -c -o blocks.o blocks.c $(C++FLAGS)

install: metamorph
	mv metamorph /usr/bin

clean: metamorph
	rm *.o

nasm:
	apt-get install nasm

ndisasm:
	apt-get install ndisasm
