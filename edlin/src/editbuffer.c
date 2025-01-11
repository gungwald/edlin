/*
 * EditBuffer.c
 *
 *  Created on: Jul 17, 2022
 *      Author: bill
 */

#include "editbuffer.h"
#include "stringlist.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/* strerror */
#include <errno.h>	/* errno */

static void chomp(char *line);
static void list();

FILE *f;
char line[MAX_LINE_SIZE];
bool isOpen;
int fgetsError;
List *buffer;

void openFile(const char *name) {
	if ((f = fopen(name, "r")) != NULL) {
		initList(buffer);
		isOpen = true;
		while (fgets(line, sizeof(line), f) != NULL) {
			chomp(line);
			appendListItem(buffer, line);
		}
		fgetsError = errno;	// Possible error
		if (ferror(f)) {
			fprintf(stderr, "%s: %s\n", name, strerror(fgetsError));
			exit(EXIT_FAILURE);
		}
		fclose(f);
		isOpen = false;
	} else {
		perror(name);
		exit(EXIT_FAILURE);
	}
}

void save(const char *name)
{
}

void performCommand(const char *command)
{
	switch(command[0]) {
		case 'l':
			list();
			break;
	}
}

static void chomp(char *line)
{
	size_t i;
	char c;
	/* It makes sense to cycle through the whole line because if
	   strlen was used instead, it would do the same to determine
	   the length. */
	for (i=0; i<MAX_LINE_SIZE && (c=line[i])!='\0'; ++i) {
		if (c=='\r' || c=='\n') {
			line[i]='\0';
		}
	}
}

static void list()
{
	resetList(buffer);
	while (! isListAtEnd(buffer)) {
		puts(getListItem(buffer));
		advanceList(buffer);
	}
}