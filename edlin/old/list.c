#include <stdio.h>	/* perror */
#include <stdlib.h>
#include "list.h"

List *createList() {
    List *l;
    ListNode *endOfList;

	l = (List *) malloc(sizeof(List));
    if (l == NULL) {
        perror(__func__);
        exit(EXIT_FAILURE);
    }
    endOfList = (ListNode *) malloc(sizeof(ListNode));
    if (endOfList == NULL) {
        perror(__func__);
        exit(EXIT_FAILURE);
    }
    endOfList->prev = NULL;
    endOfList->next = NULL;
    endOfList->item = NULL;
    l->beginning = endOfList;
    l->cursor = endOfList;
    l->end = endOfList;
    l->size = 0;
    return l;
}

void freeList(List *l) {
	clearList(l);
	free(l->end);
    free(l);
}

void retreatCursorToBegOfList(List *l) {
	l->cursor = l->beginning;
}

void advanceCursorToEndOfList(List *l) {
	l->cursor = l->end;
}

bool isCursorAtBegOfList(const List *l) {
	return l->cursor == l->beginning;
}

bool isCursorAtEndOfList(const List *l) {
	return l->cursor == l->end;
}

void advanceCursorInList(List *l) {
	if (l->cursor != l->end) {
		l->cursor = l->cursor->next;
	}
}

void retreatCursorInList(List *l) {
	if (l->cursor->prev != NULL) {
		l->cursor = l->cursor->prev;
	}
}

List *appendItemToList(List *l, void *item) {
	ListNode *originalCursor;

	originalCursor = l->cursor;
	l->cursor = l->end;
	insertItemIntoList(l, item);
	l->cursor = originalCursor;
    return l;
}

List *appendListToList(List *l, List *toBeAppended) {
    ListNode *p;
    for (p = toBeAppended->beginning; p != toBeAppended->end; p = p->next) {
        appendItemToList(l, p->item);
    }
    return l;
}

List *insertItemIntoList(List *l, void *item) {
	ListNode *n;

    n = (ListNode *) malloc(sizeof(ListNode));
    if (n == NULL) {
        perror(__func__);
        exit(EXIT_FAILURE);
    }
    n->item = item;
    n->prev = l->cursor->prev;
    n->next = l->cursor;
    l->cursor->prev->next = n;
    l->cursor->prev = n;
    l->cursor = n;
    (l->size)++;
    return l;
}

void *getItemFromList(const List *l) {
    return l->cursor->item;
}

void *removeItemFromList(List *l) {
    ListNode *n;
    void *item;
    if (l->cursor != l->end) {
    	n = l->cursor;
    	if (n->prev != NULL) {
    		n->prev->next = n->next;
    	}
    	if (n->next != NULL) {
    		n->next->prev = n->prev;
    	}
        item = n->item;
        (l->size)--;
        free(n);
    } else {
    	item = NULL;
    }
    return item;
}

void clearList(List *l) {
	ListNode *n;
	for (n = l->beginning; n != l->end; n = n->next) {
		free(n->item);
		free(n);
	}
	l->beginning = l->end;
	l->cursor = l->end;
	l->size = 0;
}

bool isListEmpty(const List *l) {
    return l->beginning == l->end;
}

size_t getListSize(const List *l) {
    return l->size;
}

List *sliceList(const List *l, size_t fromIndex, size_t toIndex) {
	List *slice;
	size_t i;
	ListNode *n;

	slice = createList();
	/* Advance to fromIndex */
	for (i = 0, n = l->beginning; i < fromIndex && n != l->end; ++i, n = n->next);
	/* Copy sliced items */
	for (; i < toIndex && n != l->end; ++i, n = n->next) {
		appendItemToList(slice, n->item);
	}
    return slice;
}

void **convertListToArray(const List *l, size_t *len) {
    void **a;
    void **p;
    ListNode *n;

    a = (void **) malloc(l->size * sizeof(void*));
    if (a == NULL) {
        perror(__func__);
        exit(EXIT_FAILURE);
    }
    for (n = l->beginning, p = a; n != l->end; n = n->next, ++p) {
        *p = n->item;
    }
    *len = l->size;
    return a;
}

List *convertArrayToList(const void **a) {
	List *l;
	void **p;

	l = createList();
	for (p = (void **) a; *p; ++p) {
		appendItemToList(l, *p);
	}
	return l;
}
