
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct QNode
{
    void *val;
    struct QNode *next;
} QNode_t;

typedef struct Queue
{
    QNode_t *head;
    QNode_t *tail;
    int size;
} Queue_t;

// methods:
void QInit(Queue_t **q);
void QPush(Queue_t *q, struct Node *val);
struct Node *QPull(Queue_t *q);
struct Node *QPeak(Queue_t *q);
int QGetSize(Queue_t *q);
void QPrint(Queue_t *q);
bool QIsEmpty(Queue_t *q);
void QClear(Queue_t *q);
