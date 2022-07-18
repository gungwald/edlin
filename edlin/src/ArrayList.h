/*
 * ArrayList.h
 *
 *  Created on: Jul 2, 2022
 *      Author: bill
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#define ARRAYLIST_CAPACITY 256

struct ArrayList
{
	void *data[ARRAYLIST_CAPACITY];
	size_t length;
};

typedef
		struct ArrayList
		ArrayList;

extern void alInit(ArrayList *a);
extern void alAdd(ArrayList *a, void *s);
extern void alInsert(ArrayList *a, size_t index, void *s);
extern void *alGet(ArrayList *a, size_t index);
extern void alSet(ArrayList *a, size_t index, void *s);

#endif /* ARRAYLIST_H_ */
