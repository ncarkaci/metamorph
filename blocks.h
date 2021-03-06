#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include <vector>
#include <map>

class classBlock {
	char * memblock;
	std::vector <std::string> lines;
	public:
		classBlock (std::vector <std::string> _lines);
		~classBlock ();
		int getSize ();
		std::string getLine (int i);
};

class classBlockContainer {
	std::vector <classBlock> blocks;
	std::vector <std::string> blockString;
	int blockSize;
	std::map <int, int> blockOffset;
	std::map <int, int> blockOffsetOffset;
	char * data;
	public:
		classBlockContainer (std::vector <std::string> _lines);
		~classBlockContainer ();
		int getBlocks ();
		std::vector <std::string> getVector ();
		std::string getString ();
};

#endif
