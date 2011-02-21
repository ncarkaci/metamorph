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
	printDebug (1, "PE ", "Reading file...");
	std::ifstream ifile (filename.c_str (), std::ios::in | std::ios::binary | std::ios::ate);
	std::ifstream::pos_type size;
	size = ifile.tellg();
	printDebug (2, "MEM", "Allocating " + itoa (size) + " bytes of memory...");
	memblock = new char [size];
	ifile.seekg (0, std::ios::beg);
	ifile.read (memblock, size);
	ifile.close ();
	printDebug (2, "MEM", "File in memory");
}

classPe::~classPe () {
	printDebug (2, "MEM", "Freeing memory...");
	delete [] memblock;
}
