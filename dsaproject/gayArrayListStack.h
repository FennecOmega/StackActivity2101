#include <stdlib.h>
#include <stdbool.h> 
#define MAX 10

// needed function operations: PUSH,POP, TOP, EMPTY, FULL, INITIALIZE, MAKENULL(?)

// for linked list:
typedef struct ArrayStack
{
    int data[MAX];
    int top;
}Stack;



void initializeStack(Stack * L){
    L->top = -1;
}

bool isEmpty(Stack L){

    return(L.top == -1) ? true : false;

}
bool isFull(Stack L){

    return (L.top == MAX-1) ? true : false;

}
int isTop(Stack L){

return (!isEmpty(L)) ? L.data[L.top] : 0;

}
void pushStack(Stack * L, int data){

    if(!isFull(*L)){
        L->data[++L->top] = data; 
    }

}
void popStack(Stack * L){

    if(!isEmpty(*L)){
        L->top--;
    }

}
void makeNull(Stack * L){

    L->top = -1;

}

void displayStack(Stack * L){
	
	Stack temp;
	initializeStack(&temp);
	
	printf("CURRENT STACK\n");
	while(!isEmpty(*L)){
		
		printf("| %5d     |\n",  isTop(*L));
		pushStack(&temp, isTop(*L));
		popStack(L);
		
	}
	printf("______________");
	
	while(!isEmpty(temp)){
		pushStack(L, isTop(temp));
		popStack(&temp);
	}
	
}
