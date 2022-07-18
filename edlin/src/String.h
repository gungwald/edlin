/*
 * String.h
 *
 *  Created on: Nov 25, 2015
 *      Author: bill
 */

#ifndef STRING_H_
#define STRING_H_

#include <stdbool.h>
#include <string.h>

struct String {
    char *characters;
    size_t length;
};

typedef
	struct String
	String;

extern String *newString(const char *s);
extern size_t sLength(const String *s);
extern String *sConcat(const String *s, const String *t);
extern String *sConcatCharArray(const String *s, const char *t);
extern bool sEquals(const String *s, const String *t);
extern bool sEqualsIgnoreCase(const String *s, const String *t);
extern int sCompareTo(const String *s, const String *t);
extern char sCharAt(const String *s, size_t index);
extern size_t sIndexOf(const String *s, const char *search);
extern char *sToCharArray(const String *s);
extern String *sToLowerCase(const String *s);
extern String *sToUpperCase(const String *s);

#endif /* STRING_H_ */
