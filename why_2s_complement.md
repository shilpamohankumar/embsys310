2 reasons to use 2's complement to represent negative numbers :

Reason 1 :
+0 is represented in binary as 0000
-0 is represented in 2's complement as 0000(1 being the overflow). 
So there is same representation for both -0 and 0.

Reason 2:
When doing addition/subtraction on binary numbers in other representations we need to apply different logics (circuits) to perform addition and subtraction. In 2s-complement representation, we represent a positive number as it is and negative number by its corresponding 2s-complement, so we can use the same circuit to perform addition and subtraction.

For example: to add 6+4 using 5 bit 2s-complement representation,

 00110
+00100
--------
 01010 = 10

To subtract 6-4, rewrite as 6+ (-4):

 00110
+11100 (2s-complement of 4)
-------
 00010 = 2

To add -6-4, rewrite as -6+ (-4) :

  11010 (2s complement of -6)
 +11100 (2s complement of -4)
-------
1]10110 (2s complement of -10)
