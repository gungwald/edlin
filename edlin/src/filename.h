/**
 * path.h
 *
 *  Created on: Nov 14, 2020
 *      Author: bill
 */

#ifndef FILENAME_H
#define FILENAME_H

#include <stdbool.h>
#include <stdint.h>
#include "stringlist.h"
#include "string.h"

#define FILE_SEPARATOR "/"
#define FILE_SEPARATOR_CHAR '/'

extern char *getAbsolutePath(const char *path);
extern const char *getSimpleName(const char *path);
extern char *getParentPath(const char *path);
extern int getFileSize(char *path);
extern List *listFiles(const char *path);
extern bool isFile(const char *path);
extern bool isDirectory(const char *path);
extern bool isGlob(const char *path);
extern bool isAbsolutePath(const char *path);
extern char *buildPath(const char *dir, const char *file);
extern bool fileExists(char *path);
extern char* makeExtendedLengthPath(const char *path);
extern char* makeNormalPath(const char *path);
extern bool isExtendedLengthPath(const char *path);
extern char* slashToBackslash(const char *path);
extern const char* skipPrefix(char *path);

#endif

