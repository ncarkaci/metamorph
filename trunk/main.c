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
//#include <libdis.h>
//#include <regex>

#include "interface.h"
#include "header.h"
#include "main.h"

std::string inputFile = "";
int blockSize = 128;
int verbosity = 0;

std::string itoa (int n) {
        char * s = new char[17];
        std::string u;
        if (n < 0) {
                n = (-1 * n);
                u = "-";
        }
        int i=0; 
        do {
                s[i++]= n%10 + '0';
                n -= n%10;
        }
        while ((n /= 10) > 0);
        for (int j = i-1; j >= 0; j--) {
                u += s[j]; 
        }
        delete[] s;
        return u;
}

int main (int argc, char ** argv) {
	// Parse command-line options
	int c;
	while ((c = getopt (argc, argv, "i:b:v")) != -1) {
		//if (c == 'T') {optThreads = atoi (optarg);}
		if (c == 'i') {inputFile = optarg;}
		if (c == 'b') {blockSize = atoi (optarg);}
		if (c == 'v') {verbosity += 1;}
		if (c == 'h') {
			printTitle ();
			return 0;
		}
	}
	
	if (inputFile == "") {
		printError ("An input file must be specified!");
		return -1;
	}
	printLine ("Reading file...");
	std::ifstream file (inputFile.c_str (), std::ios::in | std::ios::binary | std::ios::ate);
	if (!file.is_open()) {
		printError ("Count not open file " + inputFile);
		return -1;
	}
	// Read file into memory
	std::ifstream::pos_type size;
	char * memblock;
	size = file.tellg();
	printDebug ("MEM", "Allocating " + itoa (size) + " bytes of memory...");
	memblock = new char [size];
	file.seekg (0, std::ios::beg);
	file.read (memblock, size);
	file.close ();
	printDebug ("MEM", "File in memory");
	
	printLine ("Processing file...");
	
	std::ofstream outFile ((inputFile + ".asm").c_str (), std::ios::out);
	
	file_t fileType = NONE;
	
	if (memblock [0] == 'M' && memblock [1] == 'Z') {
		printDebug ("DIS", "Found Portable Executable (PE) file");	
		fileType = PE;	
	}
	
	else if (memblock [1] == 'E' && memblock [2] == 'L' && memblock [3] == 'F') {
		printDebug ("DIS", "Found ELF file");
		fileType = ELF;
	}
	
	else
	{
		/*printError ("File format not found!");
		printDebug ("MEM", "Freeing memory...");
		delete [] memblock;
		return -1;*/
		printDebug ("DIS", "Found BIN file");
		fileType = ELF;
	}
	
	printDebug ("MEM", "Freeing memory...");
	delete [] memblock;
	printLine ("Disassembling...");
	std::string exec = "ndisasm " + inputFile + " > ~" + inputFile + ".asm";
	system (exec.c_str ());
	
	// TODO: Loop through file line by line, load into structure
	printLine ("Reading file...");
	//exec = "rm ~" + inputFile + ".asm";
	sleep (1);
	
	// TODO: Break down file into blocks
	printLine ("Creating " + itoa (blockSize) + "-bit blocks...");
	sleep (1);
	
	// TODO: Add decryption engine
	printLine ("Inserting engine...");
	sleep (1);
	
	// TODO: Realign blocks (memory offsets)
	printLine ("Realigning blocks...");
	sleep (1);
	
	// TODO: Randomise blocks
	printLine ("Randomising blocks...");
	sleep (1);
	
	// TODO: Reassemble
	printLine ("Reassembling...");
	if (fileType == PE) {exec = "nasm -o crypted-" + inputFile + " -f win32 ~" + inputFile + ".asm";}
	else if (fileType == ELF) {exec = "nasm -o crypted-" + inputFile + " -f elf ~" + inputFile + ".asm";}
	system (exec.c_str ());
	
	printLine ("Done!");
	return 0;
}
