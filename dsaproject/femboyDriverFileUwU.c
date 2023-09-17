#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include ".\gayArrayListStack.h"
// #include ".\gayCursorListStack.h"
// #include ".\gayLinkedListStack.h"



int main(){

   Stack L;

int i;

   initializeStack(&L);

   printf((isEmpty(L)) ? "THE LIST IS EMPTY\n" : "THE LIST IS NOT EMPTY\n");


   for(i = 0; i < MAX; i++){
   pushStack(&L, i+1);
   }

   printf("%d IS THE TOP ELEMENT\n", isTop(L));

   printf((isEmpty(L)) ? "THE LIST IS EMPTY\n" : "THE LIST IS NOT EMPTY\n");

   printf((isFull(L)) ? "THE LIST IS FULL\n" : "THE LIST IS NOT FULL\n");

   popStack(&L);

   printf("%d IS THE TOP ELEMENT\n", isTop(L));

   printf((isFull(L)) ? "THE LIST IS FULL\n" : "THE LIST IS NOT FULL\n");

   printf((isEmpty(L)) ? "THE LIST IS EMPTY\n" : "THE LIST IS NOT EMPTY\n");

   makeNull(&L);

   printf((isFull(L)) ? "THE LIST IS FULL\n" : "THE LIST IS NOT FULL\n");

   printf((isEmpty(L)) ? "THE LIST IS EMPTY\n" : "THE LIST IS NOT EMPTY\n");


     /* printf("My X is: %d", x);

      myfunction();

      printf("My new X is: %d", x);

       */

   return 0;
}


