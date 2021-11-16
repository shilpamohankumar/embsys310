1) Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bitband region to enable the clock for Port A, then answer the following:

	a)	What instructions does the compiler produce in assembly for “writing” to the RCC_AHB2ENR bit when using bit-band address?
		MOVS	R0,#1		//load value 1 to register R0
		LDR.N	R1,[PC,#0x48]	//Load PC + offset address to register R1
		STR	R0,[R1]		//load R0 content to address stored in R1

	b)	What were the instructions produced when writing to the RCC_AHB2ENR without using bit-banding	
		LDR.N	R0,[PC,#0x4c]	//Load PC+offset address to register R0
		LDR	R1,[R0]		//Load content of memory address present in R0 to R1 
		ORRS.W	R1,R1,#1	//Modify the content by ORing with 01
		STR	R1,[R0]		//Store back the value to the memory address pointed by register R0

--------------------------------------------------------------------------------------------------------------------

2. Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:
	a. How does the calling function “func2” pass the values to the called function “func1”?
		ARM operates every operation only on registers.
		Func2 caller function passes first 4 arguments through registes R0-R3(scratch registers) and stores 5th argument on to stack.
		

	b. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?
		STR R4,[SP] - Caller function func2 is storing the 5th argument to stack

	c. What extra code did the compiler generate inside the called function “func1” with the list of multiple arguments?
		PUSH {R4} 	- 	Duty of Callee function func1 to save R4-R11 to stack to save the register values
		LDR R4,[SP,#0x4]-	Loading 5th argument value to R4
			'
			'
			'
			'
		POP {R4}	-	Poping back R4 contents back to register

	d. Any other observations
