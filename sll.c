/**
 * sll.c - This module contains the definition/implementation of functions
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
#define _SLL_C_

#include <stdlib.h>
#include "sll.h"

/*
 * Functions
 */

/**
 * Creates a SLL (singly-linked list).
 * @return Reference to the SLL.
 */
Sll* sllCreate()
{
    Sll *list;

    /* Allocate the memory for the list */
    list = (Sll*)malloc(sizeof(Sll));
    
    /* Initialize SLL "variables" */
    list->elementCount = 0;
    list->listHead = NULL;

    return list;
}

/**
 * Destroys a list. It's up to the client to deallocate the memory of the
 * elements. Also, this function also resets the original pointer of the list
 * (it sets it to NULL).
 * @pre Valid list (non-null).
 * @param list Reference to the list.
 */
void sllDestroy(Sll **list)
{
    /* Clear all the elements */
    sllClear(*list);
    
    /* Deallocate the memory of the list */
    free(*list);
    *list = NULL;
}

/**
 * Adds a new 'element' in the beginning of the list. This new element
 * becomes the new 'head' of the list.
 * @pre Valid list (non-null).
 * @pre Valid element (non-null).
 * @param list Reference to the list.
 * @param data Reference to the new element.
 */
void sllAddFirst(Sll *list, void *data)
{
    SllElm *elm;

    /* Create a new SLL element */
    elm = (SllElm*)malloc(sizeof(SllElm));

    /* Initialize the element */
    elm->data = data;
    elm->next = list->listHead;

    /* Insert the element in the list */
    list->listHead = elm;
    list->elementCount++;
}

/**
 * Adds a new 'element' at the end of the list. This new element
 * becomes the new 'tail' of the list.
 * @pre Valid list (non-null).
 * @pre Valid element (non-null).
 * @param list Reference to the list.
 * @param data Reference to the new element.
 */
void sllAddLast(Sll *list, void *data)
{
    SllElm *elm;
    SllElm *curr;

    /* Create a new SLL element */
    elm = (SllElm*)malloc(sizeof(SllElm));

    /* Initialize the element */
    elm->data = data;
    elm->next = NULL;

    /* Insert the element in the list */
    for (curr=list->listHead; 
         curr!=NULL && curr->next!=NULL;
         curr=curr->next) ;
    
    if (curr == NULL)
        list->listHead = elm;
    else
        curr->next = elm;
    list->elementCount++;
}

/**
 * Adds a new 'element' in the list, after the target one.
 * @pre Valid list (non-null).
 * @pre Valid target element (non-null).
 * @pre Valid element (non-null).
 * @pre Target element exists in the list.
 * @param list Reference to the list.
 * @param target Reference to the target element.
 * @param data Reference to the new element.
 */
void sllAddAfter(Sll *list, void *target, void *data)
{
    SllElm *elm;
    SllElm *curr;

    /* Create a new SLL element */
    elm = (SllElm*)malloc(sizeof(SllElm));

    /* Initialize the element */
    elm->data = data;
    elm->next = NULL;

    /* Insert the element in the list */
    for (curr=list->listHead;
         curr!=NULL && curr->data!=target;
         curr=curr->next) ;

    elm->next = curr->next;
    curr->next = elm;
    list->elementCount++;
}

/**
 * Adds a new 'element' in the list, before the target one.
 * @pre Valid list (non-null).
 * @pre Valid target element (non-null).
 * @pre Valid element (non-null).
 * @pre Target element exists in the list.
 * @param list Reference to the list.
 * @param target Reference to the target element.
 * @param data Reference to the new element.
 */
void sllAddBefore(Sll *list, void *target, void *data)
{
    SllElm *elm;
    SllElm *curr;
    SllElm *prev;

    /* Create a new SLL element */
    elm = (SllElm*)malloc(sizeof(SllElm));

    /* Initialize the element */
    elm->data = data;
    elm->next = NULL;

    /* Insert the element in the list */
    for (prev=NULL,curr=list->listHead;
         curr!=NULL && curr->data!=target;
         prev=curr,curr=curr->next) ;

    if (prev == NULL) {
        elm->next = list->listHead;
        list->listHead = elm;
    }
    else {
        elm->next = curr;
        prev->next = elm;
    }
    list->elementCount++;
}

/**
 * Remove the first element in the list.
 * @pre Valid list (non-null).
 * @pre List is not empty.
 * @param list Reference to the list.
 * @return A reference to the removed element.
 */
void* sllRemoveFirst(Sll *list)
{
    SllElm *curr;
    void *data;

    /* Remove the element */
    curr = list->listHead;
    data = curr->data;
    list->listHead = list->listHead->next;
    list->elementCount--;
    free((void*)curr);
    
    return data;
}

/**
 * Remove the last element in the list.
 * @pre Valid list (non-null).
 * @pre List is not empty.
 * @param list Reference to the list.
 * @return A reference to the removed element.
 */
void* sllRemoveLast(Sll *list)
{
    SllElm *curr;
    SllElm *prev;
    void *data;

    /* Remove the element */
    for (prev=NULL,curr=list->listHead;
         curr!=NULL && curr->next!=NULL;
         prev=curr,curr=curr->next) ;

    if (prev == NULL)
        list->listHead = NULL;
    else
        prev->next = curr->next;      

    data = curr->data;
    free((void*)curr);
    list->elementCount--;

    return data;
}

/**
 * Remove the target 'element' from the list.
 * @pre Valid list (non-null).
 * @pre Valid target element (non-null).
 * @pre Target element exists in the list.
 * @param list Reference to the list.
 * @param target Reference to the target element.
 * @return A reference to the removed element.
 */
void* sllRemove(Sll *list, void *target)
{
    SllElm *curr;
    SllElm *prev;

    /* Remove the element */
    for (prev=NULL,curr=list->listHead;
         curr!=NULL && curr->data!=target;
         prev=curr,curr=curr->next) ;

    if (prev == NULL)
        list->listHead = NULL;
    else
        prev->next = curr->next;

    free((void*)curr);
    list->elementCount--;

    return target;
}

/**
 * Remove all the 'elements' in the list.
 * @pre Valid list (non-null).
 * @param list Reference to the list.
 */
void sllClear(Sll *list)
{
    SllElm *curr;

    /* Remove all the elements */
    while (list->listHead != NULL) {
        curr = list->listHead;
        list->listHead = list->listHead->next;
        free((void*)curr);
    }
    
    /* Reset the fields */
    list->elementCount = 0;
    list->listHead = NULL;
}

/**
 * Gets the first 'element' in the list.
 * @pre Valid list (non-null).
 * @param list Reference to the list.
 * @return The first element in the list or, NULL is the list is empty.
 */
void* sllGetFirst(Sll *list)
{
    /* Get the first element */
    return list->listHead == NULL ? NULL : list->listHead->data;
}

/**
 * Gets the last 'element' in the list.
 * @pre Valid list (non-null).
 * @param list Reference to the list.
 * @return The last element in the list or, NULL is the list is empty.
 */
void* sllGetLast(Sll *list)
{
    SllElm *curr;

    /* Get the last element */
    for (curr=list->listHead;
         curr!=NULL && curr->next!=NULL;
         curr=curr->next) ;

    return curr == NULL ? NULL : curr->data;
}

/**
 * Gets the 'element' in the list, after the target one.
 * @pre Valid list (non-null).
 * @pre Valid target element (non-null).
 * @pre Target element exists in the list.
 * @param list Reference to the list.
 * @param target Reference to the target 'element'.
 * @return The element in the list after the target one or,
 * NULL is the list is empty.
 */
void* sllGetNext(Sll *list, void *target)
{
    SllElm *curr;

    /* Get the last element */
    for (curr=list->listHead;
         curr!=NULL && curr->data!=target;
         curr=curr->next) ;

    return curr->next == NULL ? NULL : curr->next->data;
}

/**
 * Gets the 'element' in the list, before the target one.
 * @pre Valid list (non-null).
 * @pre Valid target element (non-null).
 * @pre Target element exists in the list.
 * @param list Reference to the list.
 * @param target Reference to the target element.
 * @return The element in the list before the target one or,
 * NULL is the list is empty.
 */
void* sllGetPrevious(Sll *list, void *target)
{
    SllElm *curr;
    SllElm *prev;

    /* Get the last element */
    for (prev=NULL,curr=list->listHead;
         curr!=NULL && curr->data!=target;
         prev=curr,curr=curr->next) ;

    return prev == NULL ? NULL : prev->data;
}

/**
 * Checks whether the given 'element' exist in the list or not.
 * @param list Reference to the list.
 * @param data Reference to the target element.
 * @return 1 if the element exists, otherwise 0.
 */
int sllContains(Sll *list, void *data)
{
    SllElm *curr;

    /* Is the element here? */
    for (curr=list->listHead;
         curr!=NULL && curr->data!=data;
         curr=curr->next) ;

    return curr == NULL ? 0 : 1;
}

/**
 * Gets the number of 'elements' in the list.
 * @param list Reference to the list.
 * @return Number of elements in the list.
 */
int sllSize(Sll *list)
{
    /* Return the number of elements */
    return list->elementCount;
}

/**
 * Checks whether the list is empty or not.
 * @param list Reference to the list.
 * @return 1 if the list is empty, otherwise 0.
 */
int sllIsEmpty(Sll *list)
{
    /* Is empty? */
    return list->elementCount == 0 ? 1 : 0;
}

/* End of file -------------------------------------------------------------- */



