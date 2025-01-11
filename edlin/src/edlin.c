/*
 ============================================================================
 Name        : edlin.c
 Author      : Bill Chatfield
 Version     :
 Copyright   : GPL3
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "editbuffer.h"

#define MAX_COMMAND_SIZE 256

const char *programName;
char command[MAX_COMMAND_SIZE];

int main(int argc, const char *argv[])
{
	programName = argv[0];

	printf("FILE:");
	fgets(command, sizeof(command), stdin);
	openFile(command);
	while (strcmp(command,"q") != 0) {
		printf(":");
		fgets(command, sizeof(command), stdin);
		performCommand(command);
	}

	return EXIT_SUCCESS;
}

