#ifndef LIST_H_4321
#define LIST_H_4321

#include <stdbool.h>

struct ListNode
{
    struct ListNode *prev;
    struct ListNode *next;
    void *item;
};

typedef struct ListNode /* as */ ListNode;

struct List
{
    ListNode *beginning;
    ListNode *end;
    ListNode *cursor;
    size_t size;
};

typedef struct List /* as */ List;

extern List *createList();
extern void freeList(List *l);
extern void retreatCursorToBegOfList(List *l);
extern void advanceCursorToEndOfList(List *l);
extern bool isCursorAtBegOfList(const List *l);
extern bool isCursorAtEndOfList(const List *l);
extern void advanceCursorInList(List *l);
extern void retreatCursorInList(List *l);
extern List *appendItemToList(List *l, void *item);
extern List *appendListToList(List *l, List *listToBeAppended);
extern List *insertItemIntoList(List *l, void *item);
extern void *removeItemFromList(List *l);
extern void *getItemFromList(const List *l);
extern void clearList(List *l);
extern bool isListEmpty(const List *l);
extern size_t getListSize(const List *l);
extern List *sliceList(const List *l, size_t fromIndex, size_t toIndex);
extern void **convertListToArray(const List *l, size_t *len);
extern List *convertArrayToList(const void **array);

#endif

