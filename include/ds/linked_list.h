/**
 * @file linked_list.h
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-16 00:37
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// 내용을 입력하세요

typedef struct node node_t;

typedef struct node {
    int value;
    node_t *next;
} node_t;

void print_node(const node_t *head);
void destroy(node_t *head);
void insert_front(node_t **phead, int n);
void insert_sorted(node_t **phead, int n);

#endif /* LINKED_LIST_H */

