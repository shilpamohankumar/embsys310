#include<assert.h>
#include"stack.h"

int main()
{
    int result1;
    int result2;
    char testChar;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testChar = 'Z';
    stack_init();
    
    // Act:
    result1 = pop(&testChar);
      
    // Assert:
    assert(-1 == result1);
    assert('Z' == testChar);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testChar = 'Z';
    stack_init();
    
    // Act:
    result1 = push('A');
    result2 = pop(&testChar);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert('A' == testChar);
    
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testChar = 'Z';
    stack_init();
    
    // Act:
    push('A');
    push('B');
    push('C');                                    
    
    // Assert:
    assert(0 == pop(&testChar));
    assert('C' == testChar);

    assert(0 == pop(&testChar));
    assert('B' == testChar);

    assert(0 == pop(&testChar));
    assert('A' == testChar);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testChar = 'Z';
    stack_init();
    
    // Act:
    push('A');
    push('B');
    push('C');
    
    // Assert:
    assert(-1 == push('D'));

    assert(0 == pop(&testChar));
    assert('C' == testChar);

    assert(0 == pop(&testChar));
    assert('B' == testChar);

    assert(0 == pop(&testChar));
    assert('A' == testChar);



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testChar = 'Z';
    stack_init();
    
    // Act:
    push('A');
    push('B');
    push('C');
    
    // Assert:
    assert(0 == pop(&testChar));
    assert('C' == testChar);

    assert(0 == push('D'));

    assert(0 == pop(&testChar));
    assert('D' == testChar);

    assert(0 == pop(&testChar));
    assert('B' == testChar);

    assert(0 == pop(&testChar));
    assert('A' == testChar);

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testChar = 'Z';
    stack_init();
    
    // Act:
    push('A');
    push('B');
    push('C');
    
    // Assert:
    assert(0 == pop(&testChar));
    assert('C' == testChar);

    assert(0 == pop(&testChar));
    assert('B' == testChar);

    assert(0 == pop(&testChar));
    assert('A' == testChar);

    assert(0 == push('D'));
    assert(0 == push('E'));
    assert(0 == push('F'));
    
    assert(-1 == push('Z'));

    assert(0 == pop(&testChar));
    assert('F' == testChar);
   
    assert(0 == pop(&testChar));
    assert('E' == testChar);

    assert(0 == pop(&testChar));
    assert('D' == testChar);

    return 0;
}
