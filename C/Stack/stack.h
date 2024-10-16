/*
 -------------------------------------
 File:    stack.h
 Project: a06
 file description
 -------------------------------------
 Author:  Wajdaan Malik
 ID:      169025778
 Email:   mali5778@mylaurier.ca
 Version  2024-02-28
 -------------------------------------
 */

#ifndef STACK_H
#define STACK_H
#include "common.h"

typedef struct stack {
  int length;
  NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
