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

#define STRING_SIZE 256

static void editFile(const char *fileName);

const char *programName;
char fileName[STRING_SIZE]={'\0'};
char command[STRING_SIZE]={'\0'};

void main(int argc, const char *argv[])
{
	int i;
	programName=argv[0];

	if (argc>1)
		for (i=1; i<argc; ++i)
			editFile(argv[i]);
	else {
		printf("FILE:");
		fgets(fileName,sizeof(fileName),stdin);
		chomp(fileName);
		if (strlen(fileName)>0)
			editFile(fileName);
	}
}


void editFile(const char *fileName) 
{
	openFile(fileName);
	while (strcmp(command,"q")!=0) {
		printf(":");
		fgets(command,sizeof(command),stdin);
		performCommand(command);
	}
}
