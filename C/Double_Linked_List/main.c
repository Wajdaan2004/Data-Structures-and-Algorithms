#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

int main() {
    // Create a new doubly linked list (DLL)
    DLL dll;
    dll.start = NULL;
    dll.end = NULL;
    dll.length = 0;

    // Insert nodes at the start
    NODE* node1 = new_node('A');
    dll_insert_start(&dll, node1);
    NODE* node2 = new_node('B');
    dll_insert_start(&dll, node2);

    printf("After inserting at start: %c -> %c\n", dll.start->data, dll.start->next->data);

    // Insert nodes at the end
    NODE* node3 = new_node('C');
    dll_insert_end(&dll, node3);
    printf("After inserting at end: %c -> %c -> %c\n", dll.start->data, dll.start->next->data, dll.end->data);

    // Delete from the start
    dll_delete_start(&dll);
    printf("After deleting from start: %c -> %c\n", dll.start->data, dll.end->data);

    // Delete from the end
    dll_delete_end(&dll);
    printf("After deleting from end: %c\n", dll.start->data);

    // Clean the entire list
    dll_clean(&dll);
    printf("After cleaning the list, length is: %d\n", dll.length);

    return 0;
}
