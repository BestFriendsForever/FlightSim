/**
 * sll.h - This module contains the definition/implementation of functions
 * to represent a singly-linked list (SLL) data structure.
 * <p>
 * It's assumed that all the elements stored in the container are dynamic
 * elements represented by pointers. The list stores these elements as generic
 * pointers (void*), regardless of their original data type.
 * <p>
 * This module includes the definitions of the singly-linked list itself and,
 * the elements that are stored in it. The schematic representation of the data
 * structure is shown below:
 * <p>
 * [The list]
 * +---+--+
 * | 3 |  |----+
 * +---+--+    |
 *             v    [The elements]
 *             +---+--+   +---+--+   +---+--+
 *             | A |  |-->| B |  |-->| C |  |--> NULL
 *             +---+--+   +---+--+   +---+--+
 */
#ifndef _SLL_H_
#define _SLL_H_

/*
 * Definitions
 */

/**
 * Singly-linked list element.
 */
typedef struct _SllElm
{
    /**
     * Client's data.
     */
    void *data;

    /**
     * Reference to the next element in line.
     */
    struct _SllElm *next;

} SllElm;

/**
 * Singly-linked list.
 */
typedef struct
{
    /**
     * No. of elements in the list.
     */
    int elementCount;

    /**
     * Reference to the first element in the list.
     */
    SllElm *listHead;

} Sll;

/**
 * Prototypes
 */
Sll* sllCreate();
void sllDestroy(Sll **list);

void sllAddFirst(Sll *list, void *data);
void sllAddLast(Sll *list, void *data);
void sllAddBefore(Sll *list, void *target, void *data);
void sllAddAfter(Sll *list, void *target, void *data);

void* sllRemoveFirst(Sll *list);
void* sllRemoveLast(Sll *list);
void* sllRemove(Sll *list, void *target);
void sllClear(Sll *list);

void* sllGetFirst(Sll *list);
void* sllGetLast(Sll *list);
void* sllGetNext(Sll *list, void *target);
void* sllGetPrevious(Sll *list, void *target);

int sllContains(Sll *list, void *target);

int sllSize(Sll *list);
int sllIsEmpty(Sll *list);

/* End of file -------------------------------------------------------------- */

#endif

