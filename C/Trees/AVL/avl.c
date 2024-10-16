/**
 * -------------------------------------
 * @file  avl.c
 * Assignment 8
 * -------------------------------------
 * @author
 *
 * @version 2024-02-14
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL/avl.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(AVLNODE *root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int balance_factor(AVLNODE *np) {
    if (np == NULL) {
        return 0;
    }
    return height(np->left) - height(np->right);
}

AVLNODE *rotate_right(AVLNODE *root) {
    AVLNODE *new_root = root->left;
    AVLNODE *temp = new_root->right;

    new_root->right = root;
    root->left = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

AVLNODE *rotate_left(AVLNODE *np) {
    AVLNODE *new_root = np->right;
    AVLNODE *temp = new_root->left;

    new_root->left = np;
    np->right = temp;

    np->height = 1 + max(height(np->left), height(np->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

AVLNODE *avl_insert_node(AVLNODE *root, RECORD data) {
    if (root == NULL) {
        AVLNODE *new_node = (AVLNODE *)malloc(sizeof(AVLNODE));
        new_node->data = data;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (strcmp(data.name, root->data.name) < 0) {
        root->left = avl_insert_node(root->left, data);
    } else if (strcmp(data.name, root->data.name) > 0) {
        root->right = avl_insert_node(root->right, data);
    } else {
        return root; // Duplicate keys not allowed
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = balance_factor(root);

    if (balance > 1 && strcmp(data.name, root->left->data.name) < 0) {
        return rotate_right(root);
    }

    if (balance < -1 && strcmp(data.name, root->right->data.name) > 0) {
        return rotate_left(root);
    }

    if (balance > 1 && strcmp(data.name, root->left->data.name) > 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && strcmp(data.name, root->right->data.name) < 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

void avl_insert(AVLNODE **rootp, RECORD data) {
    *rootp = avl_insert_node(*rootp, data);
}

AVLNODE *avl_search(AVLNODE *root, char *name) {
    if (root == NULL || strcmp(root->data.name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->data.name) < 0) {
        return avl_search(root->left, name);
    }

    return avl_search(root->right, name);
}

AVLNODE *find_min_node(AVLNODE *node) {
    AVLNODE *current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

AVLNODE *avl_delete_node(AVLNODE *root, char *key) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(key, root->data.name) < 0) {
        root->left = avl_delete_node(root->left, key);
    } else if (strcmp(key, root->data.name) > 0) {
        root->right = avl_delete_node(root->right, key);
    } else {
        if (root->left == NULL || root->right == NULL) {
            AVLNODE *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        } else {
            AVLNODE *temp = find_min_node(root->right);

            strcpy(root->data.name, temp->data.name);
            root->right = avl_delete_node(root->right, temp->data.name);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = balance_factor(root);

    if (balance > 1 && balance_factor(root->left) >= 0) {
        return rotate_right(root);
    }

    if (balance > 1 && balance_factor(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && balance_factor(root->right) <= 0) {
        return rotate_left(root);
    }

    if (balance < -1 && balance_factor(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

void avl_delete(AVLNODE **rootp, char *key) {
    *rootp = avl_delete_node(*rootp, key);
}

void clean_avl(AVLNODE **rootp) {
    AVLNODE *root = *rootp;
    if (root != NULL) {
        clean_avl(&root->left);
        clean_avl(&root->right);
        free(root);
        *rootp = NULL;
    }
}
