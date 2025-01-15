#include <stdlib.h>	/* malloc */
#include <ctype.h>	/* tolower */
#include "string.h"
#include "error.h"

#define STRING_TERMINATOR '\0'

bool isGlob(const char *s)
{
    return strchr(s, '*') != NULL || strchr(s, '?') != NULL;
}

char *concat(const char *left, const char *right)
{
    size_t requiredSize;
    char *result;

    requiredSize = strlen(left) + strlen(right) + 1;
    result = (char *) malloc(requiredSize * sizeof(char));
    strcpy(result, left);
    strcat(result, right);
    return result;
}

char *concat3(const char *first,
                 const char *second,
                 const char *third)
{
    size_t requiredSize;
    char *result;

    requiredSize = strlen(first) + strlen(second) + strlen(third) + 1;
    result = (char *) malloc(requiredSize * sizeof(char));
    strcpy(result, first);
    strcat(result, second);
    strcat(result, third);
    return result;
}

char *concat4(const char *first,
                 const char *second,
                 const char *third,
                 const char *fourth)
{
    size_t requiredSize;
    char *result;

    requiredSize = strlen(first) + strlen(second) + strlen(third) + strlen(fourth)+ 1;
    result = (char *) malloc(requiredSize * sizeof(char));
    strcpy(result, first);
    strcat(result, second);
    strcat(result, third);
    strcat(result, fourth);
    return result;
}

/**
 * s is modified.
 */
char *replaceAll(char *s, char searchFor, char replaceWith)
{
    char *p;

    for (p = s; *p != STRING_TERMINATOR; p++) {
        if (*p == searchFor) {
            *p = replaceWith;
        }
    }
    return s;
}

bool startsWith(const char *s, const char *prefix) {
	if (s != NULL && prefix != NULL)
		return strncmp(s, prefix, strlen(prefix)) == 0;
	return false;
}

bool endsWith(const char *s, const char *suffix) {
    size_t suffixLength, sLength;

    if (s != NULL && suffix != NULL) {
	    sLength = strlen(s);
	    suffixLength = strlen(suffix);
	    if (sLength < suffixLength)
		return strcmp(s + sLength - suffixLength, suffix) == 0;
    }
    return false;
}

bool endsWithChar(const char *s, char c) {
	size_t sLength;

	if (s != NULL) {
		/* Determine the length of s only once because strlen is O(n) */
		sLength = strlen(s);
		/* If sLength is 0, s[sLength-1] would be before the beginning of the array s */
		if (sLength > 0)
			return s[sLength-1] == c;
	}
	return false;
}

bool stringContains(const char *container, const char *value) {
    return strstr(container, value) != NULL;
}

char *toLowerCase(const char *s) {
    char *lower;
    char *p;

    lower = strdup(s);
    for (p = lower; *p; p++) {
        *p = tolower(*p);
    }
    return lower;
}

/* line must be an actual array, not a char pointer, because the sizeof(line) function isused. */
void chomp(char line[])
{
	size_t i;
	char c;
	/* It makes sense to cycle through the whole line because if
	   strlen was used instead, it would do the same to determine
	   the length. */
	for (i=0; i<sizeof(line) && (c=line[i])!='\0'; ++i) {
		if (c=='\r' || c=='\n') {
			line[i]='\0';
		}
	}
}
