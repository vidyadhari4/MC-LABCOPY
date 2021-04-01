// Addition of 2 16-bit numbers
//Adding AB20H and 65DE
/*ORG 0000H
	CLR C     ;MAKE CY=0
	MOV A,#020H  ;LOWER BYTE OF OPERAND 1 IN A
	ADD A,#0DEH  ;ADD LOWER BYTE OF OPERAND 2 WITH A
	MOV R1,A  ;STORES LSB OF RESULT IN R1
	MOV A,#65H  ;HIGHER BYTE OF OPERAND 2 IN A
	ADDC A,#0ABH ; ADD WITH HIGHER BYTE OF OPERAND 1
	MOV R0,A  ;STORES MSB OF RESULT IN R0
	END	*/
	
	
	
//ALP TO SUBTRACT TWO 16 BIT NUMBER
//Subtracting AB20H - 65DE = B942H 
/*ORG 0000H
	CLR C	  		;MAKE CY=0
	MOV A,#020H		;LOWER BYTE OF OPERAND 1 IN A
	SUBB A,#0DEH	;SUBTRACT LOWER BYTE OF OPERAND 2 WITH A
	MOV R1,A		;STORES LSB OF RESULT IN R1
	MOV A,#65H		;HIGHER BYTE OF OPERAND 2 IN A
	SUBB A,#0ABH	;SUBTRACT WITH HIGHER BYTE OF OPERAND 1
	MOV R0,A		;STORES MSB OF RESULT IN R0
	END*/
	

// FFFF & EF9D multiplication
/*
ORG 0000H
	MOV R0,#0FFH ;MSB1
	MOV R1,#0EFH ;MSB2
	MOV R2,#0FFH ;LSB1
	MOV R3,#9DH  ;LSB2
	MOV A,R2
	MOV B,R3
	MUL AB
	MOV R4,A
	MOV R5,B
	MOV A,R2
	MOV B,R1
	MUL AB
	MOV R6,B
	ADDC A,R5
	MOV R5,A
	MOV A,R1
	MOV B,R4
	MUL AB
	ADDC A,R5
	MOV R5,A
	MOV A,B
	ADDC A,R6
	MOV R6,A
	MOV A,R1
	MOV B,R2
	MUL AB
	ADDC A,R6
	MOV R6,A
	MOV A,B
	ADDC A,#00H
	MOV R7,A
	END*/
	

//16 bit divisiion repetitive subtraction
/*ORG 0000H;
	MOV R0,#0FFH;		holds the lsb of divisor
	MOV R1,#11H;		holds the msb of divisor
	MOV R2,#22H;		holds lsb of dividend
	MOV R3,#11H;		holds msb of dividend
	MOV R4,#00H;		counter to hold remainder lsb
	MOV R5,#00H;		counter to hold remainder msb
	MOV R6,#00H;		counter to hold quotient lsb
	MOV R7,#00H;		counter to hold quotient msb
	loop: MOV 40h,R0;	make copy of r0 incase of final remainder saving if msb subtraction results in a borrow
	MOV A,R0;			mov the lsb of divident to accumulator
	MOV B,R2;			mov the lsb of divisor to reg B
	CLR C;				
	SUBB A,B;			sub of lsb bits
	MOV R0,A;
	MOV 41h,R1;			make a copy of r1 incase of final remainder saving if masb sub results in a borrow
	JC lab;				
	back: MOV A,R1;
	MOV B,R3;
	CLR C;
	SUBB A,B;			sub of msb bits
	JC mab;
	MOV R1,A;
	INC R6;
	MOV A,R6;
	CJNE A,#0FFH,loop;	it will generate a carry everytime A < #0FFH
	INC R7;
	JMP loop;
	lab: DEC R1;
	JMP back;
	mab:
	MOV R4,40h;			move the remainder lsb to r4
	MOV R3,41h;			move the remainder msb to r5
	END
*/
