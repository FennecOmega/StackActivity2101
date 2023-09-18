#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include ".\ArrayStack.h"
// #include ".\CursorListStack.h"
// #include ".\LinkedListStack.h"

int main()
{

   Stack L;

   int i;

   initializeStack(&L);
   printf("After Stack Initialization...\n");

   printf((isEmpty(L)) ? "The Stack is Empty\n\n" : "The Stack is Not Empty\n\n");

   printf("\n\n");

   for (i = 0; i < MAX; i++)
   {
      pushStack(&L, i + 10);
   }

   printf("After Fully Populating Stack...\n");

   displayStack(&L);

   printf("\n\n");

   printf((isFull(L)) ? "The Stack is Full\n\n" : "The Stack is Not Full\n\n");

   printf("%d is the Top Element\n\n", isTop(L));

   pushStack(&L, 20);
   printf("After Stack Push on Full Stack...\n");

   printf("%d is the Top Element\n\n", isTop(L));

   popStack(&L);
   printf("After Stack Pop...\n");

   printf((isFull(L)) ? "The Stack is Full\n\n" : "The Stack is Not Full\n\n");

   insertBottom(&L, 200);
   printf("After Inserting at Bottom...\n");

   displayStack(&L);
   printf((isFull(L)) ? "The Stack is Full\n\n" : "The Stack is Not Full\n\n");

   printf("%d is the Top Element\n\n", isTop(L));

   makeNull(&L);
   printf("After Stack makeNull...\n");

   printf((isEmpty(L)) ? "The Stack is Empty\n\n" : "The Stack is Not Empty\n\n");

   pushStack(&L, 59 + 10);
   printf("After Pushing Data to Stack...\n");

   displayStack(&L);

   insertBottom(&L, 21);
   printf("After Inserting at Bottom...\n");

   printf("\n\n");

   displayStack(&L);

   printf((isEmpty(L)) ? "The Stack is Empty\n\n" : "The Stack is Not Empty\n\n");

   printf((isFull(L)) ? "The Stack is Full\n\n" : "The Stack is Not Full\n\n");

   printf("%d is the Top Element\n\n", isTop(L));

   makeNull(&L);
   printf("After Stack makeNull...\n");

   printf((isEmpty(L)) ? "The Stack is Empty\n\n" : "The Stack is Not Empty\n\n");

   printf("END OF PROGRAM/DRIVER FILE");

   return 0;
}
