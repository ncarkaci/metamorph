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
	std::vector<std::string>::iterator it;
	blockSize = getBlockSize ();
	for (it = _lines.begin (); it < _lines.end (); it ++) {
		printDebug ("BLK", *it);
	}
}

classBlockContainer::~classBlockContainer () {
}
