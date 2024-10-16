/*
 -------------------------------------
 File:    stack.c
 Project: a06
 file description
 -------------------------------------
 Author:  Wajdaan Malik
 ID:      169025778
 Email:   mali5778@mylaurier.ca
 Version  2024-02-28
 -------------------------------------
 */

#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
// your code
if (sp->length == 0) {
    sp->top = np;
    sp->length++;
} else {
    np->next = sp->top;
    sp->top = np;
    sp->length++;
}
}

NODE *pop(STACK *sp) {
// your code
NODE *np = sp->top;
if (sp->length == 0) {
    return NULL;
} else if (sp->length == 1) {
    sp->top = NULL;
    sp->length--;
    return np;
} else {
    sp->top = sp->top->next;
    sp->length--;
    return np;
}
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}
