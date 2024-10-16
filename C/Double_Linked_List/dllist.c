#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

/*
 * Define node structure NODE of a doubly linked list to hold a char data value.
 */

/*
 * Define a structure DLL to hold the length, start and end node addresses of a doubly linked list.
 */

/*
 * Create and return a new node using malloc() with passed data value and returns pointer of the node.
 */
NODE* new_node(char value) {
	NODE *node = (NODE*) malloc(sizeof(NODE));

	if (node == NULL)
		return NULL;

	node->data = value;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

/*
 * Insert a given node at the beginning the of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */
void dll_insert_start(DLL *dllp, NODE *np) {
	if (dllp == NULL || np == NULL) {
		return;
	}

	if (dllp->start == NULL) {
		dllp->start = np;
		dllp->end = np;
	} else {
		np->next = dllp->start;
		dllp->start->prev = np;
		dllp->start = np;
	}
	dllp->length++;
}

/*
 * Insert a node at the end of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */
void dll_insert_end(DLL *dllp, NODE *np) {
	if (dllp == NULL || np == NULL) {
		return;
	}

	np->next = NULL;
	np->prev = dllp->end;

	if (dllp->start == NULL) {
		dllp->start = np;
		dllp->end = np;
	} else {
		dllp->end->next = np;
		dllp->end = np;
	}
	dllp->length++;
}

/*
 * This deletes the first node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_delete_start(DLL *dllp) {
	if (dllp == NULL) {
		return;
	}

	NODE *temp = dllp->start;
	if (dllp->start == dllp->end) {
		dllp->start = NULL;
		dllp->end = NULL;
	} else {
		dllp->start = dllp->start->next;
		dllp->start->prev = NULL;
	}
	free(temp);
	dllp->length--;

}

/*
 * Delete the end node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_delete_end(DLL *dllp) {
	if (dllp == NULL) {
		return;
	}

	NODE *temp = dllp->end;
	if (dllp->start == dllp->end) {
		dllp->start = NULL;
		dllp->end = NULL;
	} else {
		dllp->end = dllp->end->prev;
		dllp->end->next = NULL;
	}
	free(temp);
	dllp->length--;
}

/*
 * Clean and free the nodes of a doubly linked list and reset start and length.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_clean(DLL *dllp) {
	NODE *temp, *ptr = dllp->start;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	dllp->start = NULL;
	dllp->length = 0;
}



