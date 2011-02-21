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
#include <vector>

#include "interface.h"
#include "header.h"
#include "main.h"
#include "blocks.h"

classBlock::classBlock () {
}

classBlock::~classBlock () {
}

classBlockContainer::classBlockContainer (std::vector <std::string> _lines) {
	blockSize = getBlockSize ();
	int offset = 0;
	classBlock _block;
	int block = 0;
	int blocks = 0;
	for (int i = 0; i < (_lines.size () - 1); i ++) {
		std::string address = _lines [i].substr (0, 8);
		std::string op = _lines [i].substr (28);
		std::string _size = _lines [i].substr (10, 18);
		size_t pos = _size.find (" ");
		int size = pos / 2;
		if (offset % blockSize == 0) {
			blocks += 1;
			printDebug ("BLK", "New block (" + itoa (blocks) + ")");
		}
		printDebug ("BLK", itoa (offset) + ": At 0x" + address + ": " + op + "(" + itoa(size) + " bytes)");
		if ((offset + size) - ((blocks - 1) * blockSize) > blockSize) {
			int _padding = blockSize - (offset % blockSize);
			std::vector <std::string>::iterator it = _lines.begin();
			std::advance (it, i);
			_lines.insert (it, _padding, "NOP");
			printDebug ("BLK", "Padding (" + itoa (_padding) + ")...");
			offset += _padding;
		}
		else {offset += size;}
	}
}

classBlockContainer::~classBlockContainer () {
}
