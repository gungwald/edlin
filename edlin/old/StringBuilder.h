/*
 * StringBuilder.h
 *
 *  Created on: Jun 29, 2022
 *      Author: bill
 */

#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_

#define SB_CAPACITY 128

struct StringBuilder {
	char data[SB_CAPACITY];
	size_t length;
};

typedef
	struct StringBuilder
	StringBuilder;

extern StringBuilder *newStringBuilder();
extern void sbInit(StringBuilder *s);
extern void sbFree(StringBuilder *s);
extern void sbAppend(StringBuilder *s, const StringBuilder *suffix);
extern void sbAppendCharArray(StringBuilder *s, const char suffix[]);
extern char sbCharAt(const StringBuilder *s, size_t index);
extern void sbSetCharAt(StringBuilder *s, size_t index, char c);
extern StringBuilder *sbDeleteCharAt(StringBuilder *s, size_t index);
extern StringBuilder *sbDelete(StringBuilder *s, size_t start, size_t end);
extern size_t sbLength(const StringBuilder *s);
extern char *sbToCharArray(StringBuilder *s);

#endif /* STRINGBUILDER_H_ */
