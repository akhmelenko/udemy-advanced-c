
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node
{
    char val;
    struct Node *next;
} Node_t;

typedef struct Queue
{
    Node_t *head;
    Node_t *tail;
    int size;
} Queue_t;

// methods:
void Init(Queue_t **q)
{
    *q = (Queue_t *)malloc(sizeof(Queue_t));
    (*q)->head = NULL;
    (*q)->tail = NULL;
    (*q)->size = 0;
}

void Push(Queue_t *q, char val)
{
    assert(q);
    q->size++;
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
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

char Pull(Queue_t *q)
{
    assert(q || q->head);
    q->size--;
    int val = (q->head)->val;
    Node_t *temp = (q->head)->next;
    free(q->head);
    q->head = temp;
    if (!q->head)
        q->tail = NULL;
    return val;
}

char Peak(Queue_t *q)
{
    assert(q || q->head);
    return q->head->val;
}

int GetSize(Queue_t *q)
{
    return q->size;
}

void Print(Queue_t *q)
{
    assert(q);
    Node_t *node = q->head;
    printf("[");
    while (node)
    {
        printf(" %d", node->val);
        node = node->next;
    }
    printf(" ]\n");
}

bool IsEmpty(Queue_t *q)
{
    assert(q);
    if (q->head)
        return false;
    return true;
}

void Clear(Queue_t *q)
{
    assert(q);
    q->size = 0;
    while (q->head)
    {
        Node_t *temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    q->tail = q->head;
}

int main()
{
    Queue_t *q;
    Init(&q);
    Print(q);
    printf("size=%d\n", GetSize(q));
    Push(q, 22);
    Print(q);
    printf("size=%d\n", GetSize(q));
    Push(q, 11);
    Print(q);
    printf("size=%d\n", GetSize(q));
    Push(q, 33);
    Print(q);
    printf("size=%d\n", GetSize(q));
    char val = Pull(q);
    printf("Pull=%d\n", val);
    Print(q);
    val = Pull(q);
    printf("Pull=%d\n", val);
    Print(q);
    printf("size=%d\n", GetSize(q));
    Push(q, 11);
    Print(q);
    Clear(q);
    Print(q);
    printf("size=%d\n", GetSize(q));

    Push(q, 11);
    Print(q);
    Push(q, 22);
    Print(q);
    Push(q, 33);
    Print(q);
    printf("size=%d\n", GetSize(q));
    printf("empty=%d\n", IsEmpty(q));
    val = Pull(q);
    printf("Pull=%d\n", val);
    Print(q);
    val = Pull(q);
    printf("Pull=%d\n", val);
    Print(q);
    val = Pull(q);
    printf("Pull=%d\n", val);
    Print(q);
    printf("size=%d\n", GetSize(q));
    printf("empty=%d\n", IsEmpty(q));
    Push(q, 55);
    Print(q);
    Push(q, 55);
    Print(q);
    printf("size=%d\n", GetSize(q));
    printf("empty=%d\n", IsEmpty(q));
    Clear(q);
    free(q);
}