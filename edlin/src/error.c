#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* EXIT_FAILURE */
#include "edlin.h"	/* for programName */
#include "error.h"

void writeError(int errorCode, const char* message, const char* object)
{
    char *errorText;

    errorText = strerror(errorCode);
    fprintf(stderr, "%s: %s: \"%s\": %s\n", programName, message, object, errorText);
}

void writeError2(int errorCode, const char* message, const char* object1, const char* object2)
{
    char *errorText;

    errorText = strerror(errorCode);
    fprintf(stderr, "%s: %s: \"%s\" and \"%s\": %s\n", programName, message, object1, object2, errorText);
}

void writeError3(int errorCode, const char* message, const char* object1, const char* object2, const char* object3)
{
    char *errorText;

    errorText = strerror(errorCode);
    fprintf(stderr, "%s: %s: \"%s\", \"%s\" and \"%s\": %s\n", programName, message, object1, object2, object3, errorText);
}

void fail(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}
