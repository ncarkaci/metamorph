#ifndef __PE_H__
#define __PE_H__

class classPe {
	std::string filename;
	char * memblock;
	public:
		classPe (std::string _filename);
		~classPe ();
};

#endif
