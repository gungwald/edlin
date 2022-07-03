/*
 ============================================================================
 Name        : StringBuilderTest.c
 Author      : Bill Chatfield
 Version     :
 Copyright   : GPL3
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "StringBuilder.h"

int main(void) {
	StringBuilder s;
	sbInit(&s);
	assert(s.length == 0);
	return EXIT_SUCCESS;
}
