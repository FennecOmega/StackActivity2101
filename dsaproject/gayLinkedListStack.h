#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

// needed function operations: PUSH,POP, TOP, EMPTY, FULL, INITIALIZE, MAKENULL(?)

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

// list (LAST is FIRST NODE in the LINKED LIST)
void initializeStack(Stack * L)
{

    /*
     *   initializeStack sets the top pointer of our Linked List stack to null.
     *   It also sets the counter (named ctr) to 0, to signify an empty stack.
     *   The function accepts a pointer to an Lstack datatype.
     */

    

    L->top = NULL;
    L->ctr = 0;
}

bool isEmpty(Stack L)
{

    /*
     *   isEmpty checks if the Stack is empty and returns a boolean. If empty it returns true, otherwise false.
     *   It accepts an Lstack datatype.
     */

    return (L.top == NULL);
}

bool isFull(Stack L)
{

    /*
     *   isFull checks if the Stack is full and returns a boolean. If full it returns true, otherwise false.
     *   It accepts an Lstack datatype.
     */

    return (L.ctr == MAX);
}

int isTop(Stack L)
{

    /*
     *   isTop checks first if the Stack is empty. If it is empty, return 0, else return the data at the top of the Stack.
     *   It accepts an Lstack datatype.
     */

    return (isEmpty(L)) ? 0 : (L).top->data;
}

void pushStack(Stack * L, int data)
{

    /*
     *   pushStack pushes (inserts) a new node to the stack. This is done by adding it at the beginning (top)
     *   It will check if the stack is full, if its not full then the function will add a new node. Otherwise, nothing will be done.
     *   The function accepts a pointer to an Lstack datatype, and the data to be inserted.
     */

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

void popStack(Stack * L)
{

    /*
     *   popStack pops (removes) the top node from the Stack. This is done by making our top pointer point to the node that our current top is linked to.
     *   It will first check if the stack is empty, if its not empty it will remove the top element. Otherwise, nothing will be done.
     *   The function accepts a pointer to an Lstack datatype.
     */

    if (!isEmpty(*L))
    {
        LIST temp = L->top;
        L->top = L->top->link;
        free(temp);
        L->ctr--;
    }
}

void makeNull(Stack * L)
{

    /*
     *   makeNull empties the Stack. This is done by freeing every node in the list, and setting our counter to 0.
     *   It will first check if the stack is empty, if its not empty it will begin deleting the stack, otherwise it does nothing.
     *   The function accepts a pointer to an Lstack datatype.
     */

    LIST temp;
    if (!isEmpty(*L))
    {
        L->ctr -= L->ctr;
        for (temp = L->top; L->top != NULL; temp = L->top)
        {   
            L->top = L->top->link;
            free(temp);
        }
    }
}
