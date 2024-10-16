#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST/bst.h"


BSTNODE *new_node(RECORD data);
BSTNODE *extract_smallest_node(BSTNODE **rootp);

BSTNODE *bst_search(BSTNODE *root, char *key) {
// your code
    if (root == NULL || strcmp(root->data.name, key) == 0)
        return root;

    if (strcmp(root->data.name, key) < 0)
        return bst_search(root->right, key);
    else
        return bst_search(root->left, key);
}


void bst_insert(BSTNODE **rootp, RECORD data) {
// your code
    BSTNODE *root = *rootp;
    if (root == NULL) {
        *rootp = new_node(data);
        return;
    }

    if (strcmp(root->data.name, data.name) < 0)
        bst_insert(&root->right, data);
    else
        bst_insert(&root->left, data);
}

void bst_delete(BSTNODE **rootp, char *key) {
// your code
    BSTNODE *root = *rootp;
    if (root == NULL)
        return;

    if (strcmp(root->data.name, key) < 0)
        bst_delete(&root->right, key);
    else if (strcmp(root->data.name, key) > 0)
        bst_delete(&root->left, key);
    else {
        BSTNODE *temp = root;
        if (root->left == NULL) {
            *rootp = root->right;
            free(temp);
        } else if (root->right == NULL) {
            *rootp = root->left;
            free(temp);
        } else {
            temp = extract_smallest_node(&root->right);
            root->data = temp->data;
            free(temp);
        }
    }
}



BSTNODE *new_node(RECORD data) {
    BSTNODE *np = (BSTNODE *) malloc(sizeof(BSTNODE));
    if (np) {
        memcpy(np, &data, sizeof(BSTNODE));
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

BSTNODE *extract_smallest_node(BSTNODE **rootp) {
    BSTNODE *p = *rootp, *parent = NULL;
    if (p) {
        while (p->left) {
            parent = p;
            p = p->left;
        }

        if (parent == NULL)
            *rootp = p->right;
        else
            parent->left = p->right;

        p->left = NULL;
        p->right = NULL;
    }

    return p;
}

void clean_bst(BSTNODE **rootp) {
    BSTNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_bst(&root->left);
        if (root->right)
            clean_bst(&root->right);
        free(root);
    }
    *rootp = NULL;
}
