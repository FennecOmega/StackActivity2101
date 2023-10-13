# StackActivity2101
**FOR C DRIVER.C FILE**
- To change implementation being used, comment out the unused implementations, and only uncomment the implementation that is going to be used.
- Max 1 implementation to be used at a time for C.


**GENERAL INFORMATION**

ArrayListStack.h contains Array Implementation of the Stack.
CursorListStack.h contains CursorList Implementation of the Stack, as well as cursorlist functions.
LinkedListStack.h contains LinkedList Implementation of the Stack.
driver.c contains all the test cases. Will work with any implementation.

CursorListStack.h implements a global VirtualHeap.

**DEFINITION INFORMATION**

Array Stack is defined as an Array with the size of MAX, and an integer that tracks the top/last index in the array.
LinkedList Stack is defined as a pointer to the top/last node in the List, as well as a counter to track the amount of elements. (this is for the isFull function, and other auxiliary functions that need it.)
CursorList stack is defined as an integer to the top/last node in the List, as well as a counter to track the amount of elements. (Same as above ^)

**FUNCTIONS**

Stack Functions:
- initializeStack(Stack * L) // returns void
- isEmpty(Stack L) // returns boolean
- isFull(Stack L) // returns boolean
- isTop (Stack L) // returns data from top/last (in our case int)
- pushStack(Stack * L, int data) // returns void
- popStack(Stack * L) // returns void
- makeNull(Stack * L) // returns void
- displayStack (Stack * L) // returns void
- insertBottom(Stack * L, int data) // returns void

CursorList functions:
- initVH(VirtualHeap * V) // returns void
- AllocSpace(VirtualHeap * V) // returns position of available node
- deallocSpace(VirtualHeap * V) // returns void
