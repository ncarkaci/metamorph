#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include <vector>

class classBlock {
	char * memblock;
	public:
		classBlock ();
		~classBlock ();
};

class classBlockContainer {
	std::vector <classBlock> blocks;
	int blockSize;
	char * data;
	public:
		classBlockContainer (std::vector <std::string> _lines);
		~classBlockContainer ();
};

#endif
