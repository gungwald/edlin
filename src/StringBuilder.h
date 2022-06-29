/*
 * StringBuilder.h
 *
 *  Created on: Jun 29, 2022
 *      Author: bill
 */

#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_

#define SB_CAPACITY 128

struct stringbuilder {
	char data[SB_CAPACITY];
	size_t length;
};

typedef
	struct stringbuilder
	StringBuilder;

extern StringBuilder *new_StringBuilder();
extern void sbFinalize(StringBuilder *s);
extern void sbAppend(StringBuilder *s, const StringBuilder *suffix);
extern void sbAppendCharArray(StringBuilder *s, const char s[]);
extern void sbCharAt(const StringBuilder *s, size_t index);

#endif /* STRINGBUILDER_H_ */
