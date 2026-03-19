/**
 * @file linked_list.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-16 00:37
 */

#include <stdio.h>
#include <stdlib.h>
#include "ds/linked_list.h"

/**
 * 출력
 */
void print_node(const node_t *head) {
    const node_t *p;

    p = head;
    while (p != NULL) {
        /* 여기서 출력 */
        printf("p->value : %d\n", p->value);
        p = p->next;
    }
}

/**
 * 삭제
 */
void destroy(node_t *head) {
    node_t *p = head;

    while (p != NULL) {
        node_t *next = p->next;
        free(p);
        p = next;
    }

    head = NULL;
}

void insert_front(node_t **phead, int n)
{
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = n;

    new_node->next = *phead;
    *phead = new_node;
}

void insert_sorted(node_t **phead, int n) {
    node_t **pp;
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = n;

    pp = phead;
    while (*pp != NULL) {
        if ((*pp)->value >= n) {
            break;
        }

        pp = &(*pp)->next;
    }

    new_node->next = *pp;
    *pp = new_node;
}
