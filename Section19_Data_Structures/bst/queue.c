
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "queue.h"
#include "tree.h"

// methods:
void QInit(Queue_t **q)
{
    *q = (Queue_t *)malloc(sizeof(Queue_t));
    (*q)->head = NULL;
    (*q)->tail = NULL;
    (*q)->size = 0;
}

void QPush(Queue_t *q, struct Node *val)
{
    assert(q);
    q->size++;
    QNode_t *newNode = (QNode_t *)malloc(sizeof(QNode_t));
    newNode->val = val;
    newNode->next = NULL;
    if (!q->head)
    {
        q->head = newNode;
        q->tail = newNode;
        return;
    }
    q->tail->next = newNode;
    q->tail = newNode;
}

struct Node *QPull(Queue_t *q)
{
    assert(q || q->head);
    q->size--;
    struct Node *val = (q->head)->val;
    QNode_t *temp = (q->head)->next;
    free(q->head);
    q->head = temp;
    if (!q->head)
        q->tail = NULL;
    return val;
}

struct Node *QPeak(Queue_t *q)
{
    assert(q || q->head);
    return q->head->val;
}

int QGetSize(Queue_t *q)
{
    return q->size;
}

void QPrint(Queue_t *q)
{
    assert(q);
    QNode_t *node = q->head;
    printf("[");
    while (node)
    {
        printf(" %p", node->val);
        node = node->next;
    }
    printf(" ]\n");
}

bool QIsEmpty(Queue_t *q)
{
    assert(q);
    if (q->head)
        return false;
    return true;
}

void QClear(Queue_t *q)
{
    assert(q);
    q->size = 0;
    while (q->head)
    {
        QNode_t *temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    q->tail = q->head;
}