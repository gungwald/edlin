#ifndef ERROR_HANDLING_H_BLAH
#define ERROR_HANDLING_H_BLAH 

#include <stdbool.h>
#include <errno.h>

extern void writeError(int errorCode, const char* message, const char* object);
extern void writeError2(int errorCode, const char* message, const char* object1, const char* object2);
extern void writeError3(int errorCode, const char* message, const char* object1, const char* object2, const char* object3);

#endif

