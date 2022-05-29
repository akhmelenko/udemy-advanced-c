
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
void Push(Node_t **head, char val)
{
    assert(head);
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

char Pop(Node_t **head)
{
    assert(*head); // empty list
    char val = (*head)->val;
    Node_t *temp = (*head)->next;
    free(*head);
    *head = temp;
    return val;
}

char Peak(Node_t *head)
{
    assert(head); // empty list
    return head->val;
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
    Push(&head, 22);
    Print(head);
    Push(&head, 11);
    Print(head);
    Push(&head, 33);
    Print(head);
    char val = Pop(&head);
    printf("pop val=%d\n", val);
    Print(head);
    val = Peak(head);
    printf("peak val=%d\n", val);
    Print(head);
    printf("size=%d\n", GetSize(head));
    printf("empty=%d\n", IsEmpty(head));
    Pop(&head);
    Print(head);
    printf("size=%d\n", GetSize(head));
    printf("empty=%d\n", IsEmpty(head));
    Pop(&head);
    Print(head);
    printf("size=%d\n", GetSize(head));
    printf("empty=%d\n", IsEmpty(head));
}