
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include "queue.h"
#include "tree.h"

bool InsertRec(Node_t *node, Node_t *newNode)
{
    if (newNode->val < node->val)
    {
        if (node->left)
            return InsertRec(node->left, newNode);
        else
        {
            node->left = newNode;
            return true;
        }
    }
    else if (newNode->val > node->val)
    {
        if (node->right)
            return InsertRec(node->right, newNode);
        else
        {
            node->right = newNode;
            return true;
        }
    }
    return false;
}

bool Insert(Node_t **t, int val)
{
    assert(t);
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    // is empty BST
    if (!*t)
    {
        *t = newNode;
        return true;
    }
    // search insetr place
    return InsertRec(*t, newNode);
}

void InOrderPrint(Node_t *node)
{
    if (!node)
        return;
    InOrderPrint(node->left);
    printf(" %d", node->val);
    InOrderPrint(node->right);
}

void PreOrderPrint(Node_t *node)
{
    if (!node)
        return;
    printf(" %d", node->val);
    PreOrderPrint(node->left);
    PreOrderPrint(node->right);
}

void PostOrderPrint(Node_t *node)
{
    if (!node)
        return;
    PostOrderPrint(node->left);
    PostOrderPrint(node->right);
    printf(" %d", node->val);
}

void BFTPrint(Node_t *node)
{
    Queue_t *q;
    QInit(&q);
    QPush(q, node);
    while (QGetSize(q))
    {
        int size = QGetSize(q);
        while (size--)
        {
            Node_t *node = QPull(q);
            if (node->left)
                QPush(q, node->left);
            if (node->right)
                QPush(q, node->right);
            // process
            printf("%d ", node->val);
        }
        printf("\n");
    }
}

int main()
{
    Node_t *t = NULL;
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        int val = rand() % 100;
        if (Insert(&t, val) == false)
            printf("%d already exists\n", val);
    }
    printf("\nBFTOrder:\n");
    BFTPrint(t);
    printf("\nInOrder:");
    InOrderPrint(t);
    printf("\nPreOrder:");
    PreOrderPrint(t);
    printf("\nPostOrder:");
    PostOrderPrint(t);
}