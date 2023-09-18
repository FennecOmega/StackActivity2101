#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
#define VH_MAX 1000

// needed function operations: PUSH,POP, TOP, EMPTY, FULL, INITIALIZE, MAKENULL(?)

typedef int LIST;

typedef struct node
{

    int data;
    LIST link;

} Nodetype;

typedef struct virtualHeap
{
    Nodetype Nodes[VH_MAX];
    int avail;
    bool isInit;

} VirtualHeap;

typedef struct stack
{

    LIST top;
    int ctr;

} Stack;

VirtualHeap globalHeap = {.isInit = false};

// list (LAST is FIRST NODE in the LINKED LIST)

void initVH(VirtualHeap *V)
{
    int i;
    for (i = 0; i < VH_MAX; i++)
    {
        V->Nodes[i].link = i - 1;
    }
    V->avail = VH_MAX - 1;
    V->isInit = true;
}

int AllocSpace(VirtualHeap *V)
{
    int AvailNode = V->avail;
    if (AvailNode != -1)
    {
        V->avail = V->Nodes[AvailNode].link;
    }
    return AvailNode;
}

void deallocSpace(VirtualHeap *V, int pos)
{
    if (pos > -1 && pos < VH_MAX)
    {
        V->Nodes[pos].link = V->avail;
        V->avail = pos;
    }
}

void initializeStack(Stack *L)
{

    if (!globalHeap.isInit)
    {
        initVH(&globalHeap);
    }
    L->top = -1;
    L->ctr = 0;
}

bool isEmpty(Stack L)
{

    return (L.top == -1);
}

bool isFull(Stack L)
{

    return (L.ctr == MAX);
}

int isTop(Stack L)
{

    return (L.ctr != 0) ? globalHeap.Nodes[L.top].data : 0;
}

void pushStack(Stack *L, int data)
{

    if (!isFull(*L))
    {
        LIST temp = AllocSpace(&globalHeap);
        if (temp != -1)
        {
            globalHeap.Nodes[temp].data = data;
            globalHeap.Nodes[temp].link = L->top;
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
        L->top = globalHeap.Nodes[L->top].link;
        deallocSpace(&globalHeap, temp);
        L->ctr--;
    }
}

void makeNull(Stack *L)
{

    int temp;
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
