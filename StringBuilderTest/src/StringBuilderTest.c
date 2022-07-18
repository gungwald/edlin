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
	int i;
	StringBuilder s;
	sbInit(&s);
	assert(s.length == 0);
	sbAppendCharArray(&s, "1");
	assert(s.length == 1);
	sbAppendCharArray(&s, "blah");
	assert(s.length == 5);
	assert(sbCharAt(&s, 3) == 'a');
	for (i=0; i < 130; i++) {
		sbAppendCharArray(&s, "A");
	}
	assert(sbLength(&s) == 127);
	sbDeleteCharAt(&s, 100);
	assert(sbLength(&s) == 126);
	sbDelete(&s, 2, 3);
	assert(sbLength(&s) == 125);
	sbDelete(&s, 0, 125);
	assert(sbLength(&s) == 0);
	return EXIT_SUCCESS;
}
