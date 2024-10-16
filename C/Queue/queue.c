/*
 -------------------------------------
 File:    queue.c
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
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
// your code
if (qp->length == 0) {
    qp->front = np;
    qp->rear = np;
    qp->length++;
} else {
    qp->rear->next = np;
    qp->rear = np;
    qp->length++;
}
}

NODE *dequeue(QUEUE *qp) {
// your code
NODE *np = qp->front;
if (qp->length == 0) {
    return NULL;
} else if (qp->length == 1) {
    qp->front = NULL;
    qp->rear = NULL;
    qp->length--;
    return np;
} else {
    qp->front = qp->front->next;
    qp->length--;
    return np;
}
}

void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
  qp->length=0;
}
