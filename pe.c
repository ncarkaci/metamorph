#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

#include "interface.h"
#include "header.h"
#include "main.h"
#include "pe.h"

classPe::classPe (std::string _filename) {
	filename = _filename;
	printDebug ("PE ", "Reading file...");
	std::ifstream ifile (filename.c_str (), std::ios::in | std::ios::binary | std::ios::ate);
	std::ifstream::pos_type size;
	size = ifile.tellg();
	printDebug ("MEM", "Allocating " + itoa (size) + " bytes of memory...");
	memblock = new char [size];
	ifile.seekg (0, std::ios::beg);
	ifile.read (memblock, size);
	ifile.close ();
	printDebug ("MEM", "File in memory");
}

classPe::~classPe () {
	printDebug ("MEM", "Freeing memory...");
	delete [] memblock;
}
