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

#include "editbuffer.h"


int main(int argc, const char *argv[])
{
	if (argc > 1) {
		open(argv[1]);
	}
	return EXIT_SUCCESS;
}

