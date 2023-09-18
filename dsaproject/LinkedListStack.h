#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10

typedef struct node
{
    int data;
    struct node *link;
} nodetype, *LIST;

typedef struct Lstack
{
    LIST top;
    int ctr;

} Stack;

void initializeStack(Stack *L)
{

    L->top = NULL;
    L->ctr = 0;
}

bool isEmpty(Stack L)
{
    return (L.top == NULL);
}

bool isFull(Stack L)
{

    return (L.ctr == MAX);
}

int isTop(Stack L)
{

    return (isEmpty(L)) ? 0 : (L).top->data;
}

void pushStack(Stack *L, int data)
{

    if (!isFull(*L))
    {
        LIST temp = (LIST)malloc(sizeof(nodetype));
        if (temp != NULL)
        {
            temp->data = data;
            temp->link = L->top;
            L->top = temp;
            L->ctr++;
        }
    }
}

void popStack(Stack *L)
{

    if (!isEmpty(*L))
    {
        LIST temp = L->top;
        L->top = L->top->link;
        free(temp);
        L->ctr--;
    }
}

void makeNull(Stack *L)
{

    if (!isEmpty(*L))
    {
        while (L->ctr > 0)
        {
            popStack(L);
        }
    }
}

void displayStack(Stack *L)
{

    Stack temp;
    initializeStack(&temp);

    printf("CURRENT STACK\n");
    while (L->ctr > 0)
    {

        printf("| %5d     |\n", isTop(*L));
        printf("_____________\n");
        pushStack(&temp, isTop(*L));
        popStack(L);
    }

    while (temp.ctr > 0)
    {
        pushStack(L, isTop(temp));
        popStack(&temp);
    }
}

void insertBottom(Stack *L, int data)
{

    Stack temp;
    initializeStack(&temp);
    if (!isFull(*L))
    {
        while (L->ctr > 0)
        {

            pushStack(&temp, isTop(*L));
            popStack(L);
        }
        pushStack(L, data);

        while (temp.ctr > 0)
        {
            pushStack(L, isTop(temp));
            popStack(&temp);
        }
    }
}
