#ifndef STRING_UTILS_H_AZAZA
#define STRING_UTILS_H_AZAZA

#include <stdbool.h>
#include <string.h>

extern char *concat(const char *s, const char *t);
extern char *concat3(const char *s, const char *t,const char *u);
extern char *concat4(const char *s, const char *t, const char *u, const char *v);
extern char *replaceAll(char *in, char from, char to);
extern bool startsWith(const char *s, const char *prefix);
extern bool endsWith(const char *s, const char *suffix);
extern bool endsWithChar(const char *s, char c);
extern bool stringContains(const char *container, const char *value);
extern char *toLowerCase(const char *s);

#endif

