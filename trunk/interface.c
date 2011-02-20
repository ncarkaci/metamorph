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

#include "interface.h"

void print (std::string text) {
	std::cout << "[ ] " << text;
	return;
}

void printLine (std::string string) {
	std::cout << "[ ] " << string << std::endl;
	return;
}

void printTitle () {
	printLine ("metamorph");
	printLine ("By Quetuo");
	return;
}

void printUsage () {
	printLine ("Usage:");
	printLine ("metamorph [-options]");
	printLine ("\t-i\tInput file (must be readable)");
	return;
}

void printError (std::string error) {
	std::cout << "\033[22;31m *** " << error << " *** \033[0m" << std::endl;
	return;
}

void printDebug (std::string f, std::string debug) {
	std::cout << "\033[22;32m   [" << f << "] " << debug << " \033[0m" << std::endl;
	return;
}
