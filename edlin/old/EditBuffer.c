/*
 * EditBuffer.c
 *
 *  Created on: Jul 17, 2022
 *      Author: bill
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "EditBuffer.h"

#define EB_MAX_ROWS 200
#define EB_MAX_COLS 100

char eb[EB_MAX_ROWS][EB_MAX_COLS];
size_t rowCount = 0;
FILE *f;
bool isOpen;

static void cleanup()
{
	if (isOpen) {
		fclose(f);
		isOpen = false;
	}
}

static void fail(const char *message)
{
	cleanup();
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

void open(const char *name) {
	size_t row = 0, col = 0;
	int c;
	if ((f = fopen(name, "r")) != NULL) {
		isOpen = true;
		while ((c = fgetc(f)) != NULL) {
			if (c == '\r') {
				eb[row][col] = '\0';
				++row;
				if (row >= EB_MAX_ROWS) {
					fail("Too many rows");
				}
			} else {
				if (col >= EB_MAX_COLS) {
					fail("Too many columns");
				}
				eb[row][col++] = c;
			}
		}
		fclose(f);
		isOpen = false;
	} else {
		perror(name);
	}
}

void save(const char *name)
{
	size_t row;
	if ((f = fopen(name, "w")) != NULL) {
		isOpen = true;
		for (row = 0; row < rowCount; ++row) {
			fputs(eb[row], f);
			fputc('\r', f);
		}
		fclose(f);
		isOpen = false;
	} else {
		perror(name);
	}
}
