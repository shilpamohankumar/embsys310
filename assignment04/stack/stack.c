#include "stack.h"
#define STACK_SIZE 3

// Backing store
char StackStore[STACK_SIZE];

// Pointers to stack elements for adding and retrieving
char* putPtr;
char* getPtr;

// LIFO Stack is Empty if putPtr==getPtr;
// LIFO Stack is Full if putPtr+1 > Address of last element in the stack;

// Initialize internals of the stack
void stack_init(void)
{
    putPtr = 0;
    getPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = '\0';
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_put(char data)
{
    // stack is full
  //  if (getPtr == &StackStore[STACK_SIZE-1] && putPtr == &StackStore[STACK_SIZE-1])
    if(getPtr == &StackStore[STACK_SIZE-1] && putPtr == &StackStore[STACK_SIZE-1])
    {
        return -1;
    }

    //stack is empty
    if (getPtr == putPtr+1)
    {
        return -1;
    }
    
    // If getPtr has not been set
    if (getPtr == 0 )
    {
        getPtr = &StackStore[0];
    }    
    
    // If putPtr has not been set
    if(putPtr == 0) 
    {
      putPtr = &StackStore[0];
    }
    else
    {
        putPtr++;
        getPtr++;
    }
    
   *putPtr = data;
    return 0;
}

// Get data from stack
// If stack is empty return error
// Otherwise return success
int stack_get(char* data)
{   
    // stack is empty
    if (getPtr == 0)
    {
        return -1;
    }

    *data = *getPtr;
   
    // Reset getPtr & putPtr if stack becomes empty
    if (getPtr == &StackStore[0] && putPtr == &StackStore[0])
    {    
        getPtr = 0;
        putPtr = 0;
    }
    else if(getPtr == &StackStore[0])
    {
      //wrap
      getPtr = &StackStore[STACK_SIZE-1];
    }
    else
    { 
      getPtr--;
      putPtr--;
    }
  
    return 0;
}
