#include <stdio.h>
#include <stdlib.h>
#include "ds/linked_list.h"

int main() {
    node_t *head = NULL;

    // insert_front(&head, 3);
    // insert_front(&head, 5);
    // insert_front(&head, 2);
    // insert_front(&head, 0);

    insert_sorted(&head, 3);
    insert_sorted(&head, 5);
    insert_sorted(&head, 2);
    insert_sorted(&head, 0);

    print_node(head);

    return 0;
}
