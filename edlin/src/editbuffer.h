/*
 * EditBuffer.h
 *
 *  Created on: Jul 17, 2022
 *      Author: bill
 */

#ifndef EDITBUFFER_H_
#define EDITBUFFER_H_

#define MAX_LINE_SIZE 256

extern void append(const char *data);
extern void openFile(const char *name);
extern void performCommand(const char *command);

#endif 
/* EDITBUFFER_H_ */
