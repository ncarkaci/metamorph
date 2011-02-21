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
	for (int i = 0; i < (_lines.size () - 1); i ++) {
		std::string address = _lines [i].substr (0, 8);
		std::string op = _lines [i].substr (28);
		printDebug ("BLK", "At 0x" + address + ": " + op);
		
	}
}

classBlockContainer::~classBlockContainer () {
}
