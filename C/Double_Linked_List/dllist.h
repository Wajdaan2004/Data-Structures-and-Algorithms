#ifndef DLLIST_H_
#define DLLIST_H_

typedef struct node {
	char data;
	struct node *prev;
	struct node *next;
} NODE;

typedef struct dllist {
	int length;
	NODE *start;
	NODE *end;
} DLL;

NODE* new_node(char value);
void dll_insert_start(DLL *dllp, NODE *np);
void dll_insert_end(DLL *dllp, NODE *np);
void dll_delete_start(DLL *dllp);
void dll_delete_end(DLL *dllp);
void dll_clean(DLL *dllp);

#endif /* DLLIST_H_ */
