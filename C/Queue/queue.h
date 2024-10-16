/*
 -------------------------------------
 File:    queue.h
 Project: a06
 file description
 -------------------------------------
 Author:  Wajdaan Malik
 ID:      169025778
 Email:   mali5778@mylaurier.ca
 Version  2024-02-28
 -------------------------------------
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

typedef struct queue {
  int length;
  NODE *front;
  NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif
