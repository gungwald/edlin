#include <stdio.h>
#include <stdlib.h>
#include "filename.h"
#include "string.h"
#include "error.h"
#include "trace.h"

enum FileType {
    FILETYPE_DIRECTORY, FILETYPE_FILE, FILETYPE_GLOB, FILETYPE_UNKNOWN
};

/* Result should be freed. */
char* slashToBackslash(const char *path) {
    /* Make sure all separators are backslashes. */
    return replaceAll(strdup(path), '/', '\\');
}

/* Result must be freed. */
char* getAbsolutePath(const char *path) {
	fprintf(stderr, "%s not implemented", "getAbsolutePath");
	return NULL;
}

/* Result must be freed. */
char* getParentPath(const char *path) {
	fprintf(stderr, "%s not implemented", "getParentPath");
	return NULL;
}

/* Returns pointer which should not be freed. */
const char* getSimpleName(const char *path) {
    const char *lastSeparator;
    const char *simpleName;

    lastSeparator = strrchr(path, FILE_SEPARATOR_CHAR);
    if (lastSeparator == NULL)
        simpleName = path;
    else
        simpleName = lastSeparator + 1;
    return simpleName;
}

/* Returns pointer which should not be freed. */
extern const char* skipPrefix(char *path) {
	fprintf(stderr, "%s not implemented", "skipPrefix");
	return NULL;
}

int getFileSize(char *path) {
	fprintf(stderr, "%s not implemented", "getFileSize");
	return 0;
}

List* listFiles(const char *path) {
	fprintf(stderr, "%s not implemented", "listFiles");
	return NULL;
}

enum FileType getFileType(const char *path) {
	fprintf(stderr, "%s not implemented", "getFileType");
	return 0;
}

bool isFile(const char *path) {
    return getFileType(path) == FILETYPE_FILE;
}

bool isDirectory(const char *path) {
    return getFileType(path) == FILETYPE_DIRECTORY;
}

bool isGlobPattern(const char *path) {
    return getFileType(path) == FILETYPE_GLOB;
}

bool isAbsolutePath(const char *path) {
    if (path != NULL && path[0] == FILE_SEPARATOR_CHAR)
	    return true;
    return false;
}

char* buildPath(const char *dir, const char *file) {
    return concat3(dir, FILE_SEPARATOR, file);
}

bool fileExists(char *path) {
	fprintf(stderr, "%s not implemented", "fileExists");
	return false;
}

