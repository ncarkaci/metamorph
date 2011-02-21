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

#ifdef WINDOWS
	#include <windows.h>
#endif

#include "interface.h"
#include "main.h"

void print (std::string text) {
	std::cout << "[ ] " << text;
	return;
}

void printLine (std::string string) {
	print (string + "\n");
	return;
}

void printTitle () {
	printLine ("Metamorph");
	printLine ("By Quetuo");
	return;
}

void printUsage () {
	printLine ("Usage:");
	printLine ("metamorph [-options]");
	printLine ("\t-i\tInput file (must be readable)");
	printLine ("\t-b\tBlock size (default 128 bits)");
	printLine ("\t-v\tIncrease verbosity");
	return;
}

void printError (std::string error) {
	#ifdef LINUX
		std::cout << "\033[22;31m *** " << error << " *** \033[0m" << std::endl;
	#endif
	#ifdef WINDOWS
		std::cout << " *** " << error << " *** " << std::endl;
	#endif
	return;
}

void printDebug (int level, std::string f, std::string debug) {
	if (getVerbosity () >= level) {
		std::cout << "\033[22;32m   [" << f << "] " << debug << " \033[0m" << std::endl;
	}
	return;
}
