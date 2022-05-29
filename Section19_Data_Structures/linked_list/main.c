
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node
{
    char val;
    struct Node *next;
} Node_t;

// methods:
void InsertSorted(Node_t **head, char val)
{
    assert(head);
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->val = val;
    if (!*head)
    {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    if ((*head)->val > val)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node_t *node = *head;
    while (node->next)
    {
        if (node->next->val > val)
        {
            newNode->next = node->next;
            node->next = newNode;
            return;
        }
        node = node->next;
    }
    node->next = newNode;
}

void InsertBack(Node_t **head, char val)
{
    assert(head);
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->val = val;
    newNode->next = NULL;
    if (!*head)
    {
        *head = newNode;
        return;
    }
    Node_t *node = *head;
    while (node->next)
        node = node->next;
    node->next = newNode;
}

void InsertFront(Node_t **head, char val)
{
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

bool Delete(Node_t **head, char val)
{
    assert(head);
    if ((*head)->val == val)
    {
        // delete head
        Node_t *temp = (*head)->next;
        free(*head);
        *head = temp;
        return true;
    }
    Node_t *node = *head;
    while (node->next)
    {
        if (node->next->val == val)
        {
            // delete node
            Node_t *temp = node->next;
            node->next = node->next->next;
            free(temp);
            return true;
        }
        node = node->next;
    }
    return false;
}

char DeleteBack(Node_t **head)
{
    assert(*head); // empty list
    if (!(*head)->next)
    {
        // only 1 element in list
        free(*head);
        *head = NULL;
        return true;
    }
    Node_t *node = *head;
    while (node->next->next)
    {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
    return true;
}

int DeleteFront(Node_t **head)
{
    Node_t *temp = (*head)->next;
    free(*head);
    *head = temp;
    return true;
}

int GetSize(Node_t *head)
{
    Node_t *node = head;
    int cnt = 0;
    while (node)
    {
        node = node->next;
        cnt++;
    }
    return cnt;
}

void Print(Node_t *head)
{
    Node_t *node = head;
    printf("[");
    while (node)
    {
        printf(" %d", node->val);
        node = node->next;
    }
    printf(" ]\n");
}

bool IsEmpty(Node_t *head)
{
    if (head)
        return false;
    return true;
}

int main()
{
    Node_t *head = NULL;
    Print(head);
    InsertBack(&head, 22);
    Print(head);
    InsertFront(&head, 11);
    Print(head);
    InsertBack(&head, 33);
    Print(head);
    Delete(&head, 11);
    Print(head);
    DeleteFront(&head);
    Print(head);
    InsertFront(&head, 11);
    Print(head);
    DeleteBack(&head);
    Print(head);
    DeleteBack(&head);
    Print(head);
    InsertBack(&head, 11);
    Print(head);
    InsertBack(&head, 22);
    Print(head);
    InsertBack(&head, 33);
    Print(head);
    printf("size=%d\n", GetSize(head));
    printf("empty=%d\n", IsEmpty(head));
    DeleteBack(&head);
    Print(head);
    DeleteBack(&head);
    Print(head);
    DeleteBack(&head);
    Print(head);
    printf("size=%d\n", GetSize(head));
    printf("empty=%d\n", IsEmpty(head));
    InsertSorted(&head, 55);
    Print(head);
    InsertSorted(&head, 22);
    Print(head);
    InsertSorted(&head, 33);
    Print(head);
    InsertSorted(&head, 66);
    Print(head);
    InsertSorted(&head, 11);
    Print(head);
    InsertSorted(&head, 44);
    Print(head);
    Delete(&head, 44);
    Print(head);
}