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
#include "header.h"

void print (std::string text) {
	std::cout << text;
	return;
}

void printLine (std::string string) {
	print ("[ ] " + string + "\n");
	return;
}

void printTitle () {
	print ("                 _                                    _     \n");
	print ("                | |                                  | |    \n");
	print ("  _ __ ___   ___| |_  __ _ _ __ ___   ___  _ __ _ __ | |__  \n");
	print (" | '_ ` _ \\ / _ \\ __|/ _` | '_ ` _ \\ / _ \\| '__| '_ \\| '_ \\ \n");
	print (" | | | | | |  __/ |_| (_| | | | | | | (_) | |  | |_) | | | |\n");
	print (" |_| |_| |_|\\___|\\__|\\__,_|_| |_| |_|\\___/|_|  | .__/|_| |_|\n");
	print ("                                               | |          \n");
	print ("                                               |_|          \n");
	print ("\n");
	printLine ("Metamorph " + itoa (VERSION_MAJOR) + "." + itoa (VERSION_MINOR) + "." + itoa (VERSION_BUILD));
	printLine ("By Quetuo (http://www.quetuo.net)");
	printLine ("For XtremeRoot.net");
	return;
}

void printUsage () {
	printLine ("Usage:");
	printLine ("metamorph [-options]");
	printLine ("\t-i\tInput file (must be readable)");
	printLine ("\t-b\tBlock size (default 128 bits)");
	printLine ("\t-v\tIncrease verbosity");
	printLine ("Example: metamorph -i input.exe -b 256 -v -v");
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
