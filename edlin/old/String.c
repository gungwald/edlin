/*
 * String.c
 *
 *  Created on: Nov 26, 2015
 *      Author: bill
 */
#include <string.h>
#include <stdlib.h>
#include "String.h"

String *newString(const char *s) {
    String *n;
    size_t len;
    char *validatedS;

    if (s == NULL) {
        validatedS = (char *) "";
    }
    else {
        validatedS = (char *) s;
    }

    len = strlen(validatedS);
    n = (String *) GC_MALLOC(sizeof(struct String_));
    if (n != NULL) {
        n->cls = CLS_STRING;
        n->length = len;
        n->characters = (char *) GC_MALLOC(sizeof(char) * len + 1);
        if (n->characters != NULL) {
            strcpy(n->characters, validatedS);
        }
        else {
            GC_FREE(n);
            n = NULL;
        }
    }
    return n;
}

size_t sLength(const String *s) {
    if (s == NULL) {
        return 0;
    }
    else {
        return s->length;
    }
}

String *sConcat(const String *s, const String *t) {
    size_t len;
    String *n = NULL;
    char *p;
    const String *vs, *vt;

    if (s == NULL) {
        vs = new_String("");
    }
    else {
        vs = s;
    }

    if (t == NULL) {
        vt = new_String("");
    }
    else {
        vt = t;
    }

    len = sLength(vs) + sLength(vt);
    if ((p = (char *) GC_MALLOC(sizeof(char) * len + 1)) != NULL) {
        strcpy(p, vs->characters);
        strcat(p, vt->characters);
        if ((n = (String *) GC_MALLOC(sizeof(struct String_))) != NULL) {
            n->cls = CLS_STRING;
            n->characters = p;
            n->length = len;
        }
        else {
            GC_FREE(p);
        }
    }
    return n;
}

String *sConcatCharArray(const String *s, const char *t) {
    size_t len;
    String *n = NULL;
    char *p;
    const String *validatedS;
    char *validatedT;

    if (s == NULL) {
        validatedS = new_String("");
    }
    else {
        validatedS = s;
    }

    if (t == NULL) {
        validatedT = "";
    }
    else {
        validatedT = (char *) t;
    }

    len = sLength(validatedS) + strlen(validatedT);
    if ((p = (char *) GC_MALLOC(sizeof(char) * len + 1)) != NULL) {
        strcpy(p, validatedS->characters);
        strcat(p, validatedT);
        if ((n = (String *) GC_MALLOC(sizeof(struct String_))) != NULL) {
            n->cls = CLS_STRING;
            n->characters = p;
            n->length = len;
        }
        else {
            GC_FREE(p);
        }
    }
    return n;
}

char *sToCharArray(const String *s) {
    if (s == NULL) {
        return "";
    }
    else {
        return s->characters;
    }
}

bool sEquals(const String *s, const String *t) {
    return strcmp(s->characters, t->characters) == 0;
}

bool sEqualsIgnoreCase(const String *s, const String *t) {
    return sEquals(sToLowerCase(s), sToLowerCase(t));
}

String *sToLowerCase(const String *s) {
    size_t i;
    String *lowerCased;
    char *characters;
    size_t len;

    lowerCased = new_String(s->characters);
    characters = lowerCased->characters;
    len = lowerCased->length;

    for (i = 0; i < len; i++) {
        characters[i] = tolower(characters[i]);
    }
    return lowerCased;
}
