#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TPROPS tree_property(TNODE *root) {
// your code
TPROPS props = { 0 };

if (root == NULL){
    return props;
}

props.order = 1 + tree_property(root->left).order + tree_property(root->right).order;
int left_height = 1 + tree_property(root->left).height;
int right_height = 1 + tree_property(root->right).height;
props.height = (left_height > right_height) ? left_height : right_height;

return props;
}

void preorder(TNODE *root) {
// your code
if (root != NULL){
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}
}

void inorder(TNODE *root) {
// your code
if (root != NULL){
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
}

void postorder(TNODE *root) {
// your code
if (root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}
}

void bforder(TNODE *root) {
// your code
if (root == NULL){
    return;
}

QUEUE queue = {0};
enqueue(&queue, root);

while (queue.front) {
    TNODE *current = (TNODE*) dequeue(&queue);
    printf("%c ", current->data);

    if (current->left != NULL)
        enqueue(&queue, current->left);

    if (current->right != NULL)
        enqueue(&queue, current->right);
}

clean_queue(&queue);

return;
}

TNODE *bfs(TNODE *root, char val) {
// your code
TNODE *r = NULL;

if (root){
    QUEUE queue = {0};
    enqueue(&queue, root);

    while (queue.front) {
        TNODE *tnp = (TNODE*) dequeue(&queue);
        if (tnp->data == val){
            r = tnp;
            break;
        }

        if (tnp->left != NULL)
            enqueue(&queue, tnp->left);

        if (tnp->right != NULL)
            enqueue(&queue, tnp->right);
    }

    clean_queue(&queue);
}
    return r;
}

TNODE *dfs(TNODE *root, char val) {
// your code
TNODE *r = NULL;

if (root){
    STACK stack = {0};
    push(&stack, root);

    while (stack.top) {
        TNODE *tnp = (TNODE*) pop(&stack);
        if (tnp->data == val){
            r = tnp;
            break;
        }

        if (tnp->right != NULL)
            push(&stack, tnp->right);

        if (tnp->left != NULL)
            push(&stack, tnp->left);
    }

    clean_stack(&stack);
}
    return r;
}


// the following functions are given, need to add to your program.

TNODE *new_node(char val) {
    TNODE *np = (TNODE *) malloc(sizeof(TNODE));
    if (np != NULL) {
        np->data = val;
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

void clean_tree(TNODE **rootp) {
    TNODE *p = *rootp;
    if (p) {
        if (p->left)
            clean_tree(&p->left);
        if (p->right)
            clean_tree(&p->right);
        free(p);
    }
    *rootp = NULL;
}

void insert_tree(TNODE **rootp, char val) {
    if (*rootp == NULL) {
        *rootp = new_node(val);
    } else {
        QUEUE queue = { 0 };
        TNODE *p;
        enqueue(&queue, *rootp);
        while (queue.front) {
            p = dequeue(&queue);
            if (p->left == NULL) {
                p->left = new_node(val);
                break;
            } else {
                enqueue(&queue, p->left);
            }

            if (p->right == NULL) {
                p->right = new_node(val);
                break;
            } else {
                enqueue(&queue, p->right);
            }
        }
    }
}
