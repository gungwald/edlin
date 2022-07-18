/*
 * StringBuilder.c
 *
 *  Created on: Jul 2, 2022
 *      Author: bill
 */

#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "StringBuilder.h"

#define MIN(x,y) (x <= y ? x : y)
#define DEC(i) --(i)
#define STRING_TERMINATOR '\0'
#define IS_STRING_TERMINATOR(c) (c == '\0')
#define IS_NOT_STRING_TERMINATOR(c) (c != '\0')

/*
	IMPLEMENTATION NOTES:
	1. Implements a mutable string with a fixed maximum capacity.
	2. ++i is faster with cc65 than i++
*/

StringBuilder *newStringBuilder()
{
	StringBuilder *s;
	s = (StringBuilder *) malloc(sizeof(struct StringBuilder));
	if (s != NULL) {
		sbInit(s);
	} else {
		perror("malloc");
	}
	return s;
}

void sbInit(StringBuilder *s)
{
	s->data[0] = STRING_TERMINATOR;
	s->length = 0;
}

void sbFree(StringBuilder *s)
{
	free(s);
}

void sbAppend(StringBuilder *s, const StringBuilder *suffix)
{
	size_t combinedLength;

	combinedLength = s->length + strlen(suffix->data);
	combinedLength = MIN(combinedLength, sizeof(s->data) - 1);
	strncat(s->data, suffix->data, combinedLength);
	s->data[combinedLength] = STRING_TERMINATOR;
	s->length = combinedLength;
}

void sbAppendCharArray(StringBuilder *s, const char suffix[])
{
	size_t combinedLength;

	combinedLength = s->length + strlen(suffix);
	combinedLength = MIN(combinedLength, sizeof(s->data) - 1);
	strncat(s->data, suffix, combinedLength);
	s->data[combinedLength] = STRING_TERMINATOR;
	s->length = combinedLength;
}

char sbCharAt(const StringBuilder *s, size_t index)
{
	return s->data[index];
}

void sbSetCharAt(StringBuilder *s, size_t index, char c)
{
	s->data[index] = c;
}

StringBuilder *sbDeleteCharAt(StringBuilder *s, size_t index)
{
	size_t i, j, oldLength;
	char *data;

	/* index and s->length cannot be negative at the beginning because they
	   are unsigned. If they would be assigned negative values during the
	   execution of this code, then that is an underflow error which will
	   be silently ignored, and the result will be wrong. */
	if (index >= s->length) {
		fprintf(stderr, "Index %lu out of bounds for string '%s'\n", index, s->data);
	} else {
		/* Get more efficient variables */
		data = s->data;
		oldLength = s->length;
		/* Copy each character back one, from index+1 to the string terminator, inclusive */
		for (i = index, j = i + 1; j <= oldLength; ++i, ++j) {
			data[i] = data[j];
		}
		s->length = i - 1; /* i is 1 past the final string terminator */
	}
	return s;
}

StringBuilder *sbDelete(StringBuilder *s, size_t start, size_t end)
{
	size_t i, j, oldLength;
	char *data;

	/* start and end cannot be negative at the beginning because they
	   are unsigned. If they would be assigned negative values during the
	   execution of this code, then that is an underflow error which will
	   be silently ignored, and the result will be wrong. */
	if (start >= s->length) {
		fprintf(stderr, "Start index %lu out of bounds for string '%s'\n", start, s->data);
	} else if (end > s->length) { /* end is 1 past the last to delete */
		fprintf(stderr, "End index %lu out of bounds for string '%s'\n", end, s->data);
	} else {
		/* Create more efficient variables */
		data = s->data;
		oldLength = s->length;
		/* Copy characters from j back to i, from end to the string terminator, inclusive */
		for (i = start, j = end; j <= oldLength; ++i, ++j) {
			data[i] = data[j];
		}
		s->length = i - 1;
	}
	return s;

}

size_t sbLength(const StringBuilder *s)
{
	return s->length;
}

char *sbToCharArray(StringBuilder *s)
{
	return s->data;
}
