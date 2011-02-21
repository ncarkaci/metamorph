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
#include <map>

#include "interface.h"
#include "header.h"
#include "main.h"
#include "blocks.h"

classBlock::classBlock (std::vector <std::string> _lines) {
	lines = _lines;
}

classBlock::~classBlock () { 
}

int classBlock::getSize () {
	return lines.size ();
}

std::string classBlock::getLine (int i) { 
	return lines [i];
}

classBlockContainer::classBlockContainer (std::vector <std::string> _lines) {
	blockSize = getBlockSize ();
	int offset = 0;
	//classBlock _block;
	int block = 0;
	int _blocks = 1;
	std::vector <std::string> _temp;
	for (int i = 0; i < (_lines.size () - 1); i ++) {
		std::string address = _lines [i].substr (0, 8);
		std::string op = _lines [i].substr (28);
		std::string _size = _lines [i].substr (10, 18);
		size_t pos = _size.find (" ");
		if (pos == std::string::npos) {
			if (_lines [i] == "nop") {
				offset += 1;
			}
		}
		else
		{
			int size = pos / 2;
			if (offset % blockSize == 0 && offset > 0) {
				_blocks += 1;
				printDebug (3, "BLK", "New block (" + itoa (_blocks) + ") / (" + itoa (_temp.size()) + ")");
				classBlock blockTemp (_temp);
				blocks.push_back (blockTemp);
				_temp.clear ();
			}
			printDebug (4, "BLK", itoa (offset) + ": At 0x" + address + ": " + op + "(" + itoa(size) + " bytes)");
			if ((offset + size) - ((_blocks - 1) * blockSize) > blockSize) {
				int _padding = blockSize - (offset % blockSize);
				std::vector <std::string>::iterator it = _lines.begin();
				std::advance (it, i);
				_lines.insert (it, _padding, "nop");
				printDebug (3, "BLK", "Padding (" + itoa (_padding) + ")...");
				offset += _padding;
			}
			if ((offset + size) - ((_blocks - 1) * blockSize) <= blockSize) {
				blockOffset [address] = _blocks;
				blockOffsetOffset [address] = offset % blockSize;
				printDebug (4, "ALN", "Realigned 0x" + address + " to " + itoa (offset) + " (" + itoa (offset % blockSize) + " in block " + itoa (_blocks) + ")");
				offset += size;
			}
			_temp.push_back (_lines [i]);
			blockString.push_back (_lines [i]);
			printDebug (4, "ASM", _lines [i]);
		}
	}
	int _padding = blockSize - (offset % blockSize);
	for (int i = 0; i < _padding; i ++) {_temp.push_back ("NOP"); blockString.push_back ("NOP");}
	printDebug (3, "BLK", "Padding (" + itoa (_padding) + ")...");
	offset += _padding;
	classBlock blockTemp (_temp);
	blocks.push_back (blockTemp);
}

classBlockContainer::~classBlockContainer () {
}

int classBlockContainer::getBlocks () {
	return blocks.size ();
}

std::vector <std::string> classBlockContainer::getVector () {
	/*std::vector <std::string> ret;
	for (int i = 0; i < (blocks.size () - 1); i ++) {
		for (int ii = 0; ii < ((blocks [i]).getSize () - 1); ii ++) {
			ret.push_back ((blocks [i]).getLine (ii));
		}
	}
	return ret;*/
	return blockString;
}

std::string classBlockContainer::getString () {
	std::vector <std::string> _vector = getVector ();
	std::string ret = "";
	for (int i = 0; i < (_vector.size ()); i ++) {
		ret = ret + _vector [i] + "\n";
	}
	return ret;
	//return blockString;
}
