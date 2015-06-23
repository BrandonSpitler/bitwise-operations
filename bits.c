/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//
// 12 problems, 40 points
// 2 - rating 1
// 4 - rating 2
// 4 - rating 3
// 2 - rating 4
// 2 - fp extra credit
//rating 1
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
    return (~x&~y);
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
   return !(x^0x7fffffff);

}
//rating 2
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x^y);
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
  return  !!(x & (0x55555555));
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 * 
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	n=n<<3;
	m=m<<3;
	int byte1=((x& (0xff<<(n)))>>(n))& 0xff;
	int byte2=((x& (0xff<<(m)))>>(m))& 0xff;
	byte2= byte2 << (n);
	byte1= byte1<< (m);
	x=(x & ~(0xff<<n | 0xff <<m));
	x=(x | (byte1 | byte2));
	//x=x+byte2;
	
	
    return x;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;

}
//rating 3
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  
    int negX = ~x+1; //makes x negative
    int addY = negX + y; /*negative if x > y*/ 
    int checkSign = addY >> 31 & 1; /*shifts sign bit to the right*/
    //check sign if negative x is large if postive y is larger; 
	//check sign is 1 if negative
	// check sign is 0 if poistive
 
    
    int xsign = 0x80000000 & x; 
    // xleft bit is ngeative if x is neagtive as well xleft is left bit if x is negative
    
    int ysign = 0x80000000 & y; 
    //same as y left is the same a left bit if y is negative
    
    int xOrd = xsign ^ ysign; 
    //if both have the same sign this will be 0
    xOrd = (xOrd >> 31) & 1; 
    //if and y have the same sign this is 1
    return !((xOrd & (xsign>>31)) | (!checkSign & !xOrd)); //return 0 if the have the same sign and x is negative

}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {

  return !(x>>31&1);

}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
	//int sign = x>>31;//gets sign of value
	//x=x+0xffffffff;
	//x=x+0x1;
	//int abs=(sign^x)/*negaties everything if it was negative*/+(~sign+1);//adds 1 if negative 0 if postive;
	//abs=abs+~(abs>>n)+1;//gets remainder
  //x=(abs^sign)+1;*/ 
   //return (x + (sign & ((1 << n) + ~0))) >> n;
    
    /*go the other way then you tried before
     * 
     * 
     * */
   int power = (1 << n) + 0xffffffff;//subtracts one 1 to the npower
   
   int sign = x >> 31;//if x is neagative gives you a -1 if postive gives you a zero
   int result = x & power;//results is the remainder if postive
   return (result) + (((~((!!result) << n)) + 1) & sign);//if postive switchs sign of the result
} 
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int firstbyte = (c<<(n<<3));
  int secondbyte= x&(~(0xff<<(n<<3)));
  return secondbyte+firstbyte;
}
//rating 4
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) 
{
   int sign = (x>>31) & 1;
   int abs =~sign+1;//one if negative 0 if postive
   int tempbits = 0; //tempary olds number of bits at that place
   int bits = 2; //number of bits starts at 2 due to equation
   int copy = x; //checks for power of two
   int copy2 = x; //checks for 0
   //check for negative one
   int tminCheck =  x ^ ( 0x80000000); //if neative high this will be 0..
   tminCheck = !tminCheck;//invers if neative high will be 1 all welse will be one
   tminCheck = ~tminCheck+1; //makes neagive high into 1

   x = (x & ~abs) | ((~x +1) & abs);//now a positive value
   //well get one to ever place holder
   x = x + 0xffffffff;//rounds of first value rounds down
   x = (x | x >> 1);
   x = (x | x >> 2);
   x = (x | x >> 4);
   x = (x | x >> 8);
   x = (x | x >> 16);
   x = (x + 1);
   //rounds x up one sets everything else to zero

   /*the following chunks of code follow an algorithm that
     does five different checks, incrementing the counter
     for each check so that the result is the bit position
     of the rounded up value of x*/
     
     //only one one if that one is in one of them tempbits goes to 0
   tempbits = !(x & (0xffff));
   tempbits = ~tempbits+1; //if temp bits was found this will be all ones
   bits += (tempbits & 16);// if the one was found 16 will be the number of bits

   tempbits = !(x & (0xFF | 0xFF << 16));
   tempbits = ~tempbits + 1;
   bits += (tempbits & 8);

   tempbits = 0x0F | 0x0F <<8;
   tempbits = tempbits | tempbits <<16;
   tempbits = !(x & tempbits);
   tempbits = ~tempbits+1;  
   bits += (tempbits & 4);

   tempbits = 0x33 | 0x33 << 8;
   tempbits = tempbits | tempbits << 16;
   tempbits = !(x & tempbits);
   tempbits = ~tempbits+1;
   bits += (tempbits & 2);

   tempbits = 0x55 | 0x55 << 8;
   tempbits = tempbits | tempbits << 16;
   tempbits = !(x & tempbits);
   tempbits = ~tempbits+1;
   bits += (tempbits & 1);

   /*determines if x is 0. if so, you want to return 1.*/
   copy2 = !copy2;
   copy2 = ~copy2+1;   

   bits += ~((tminCheck)&1);

   /*add one to the count if x is a power of 2*/
   copy = copy & (copy+~0);
   bits += !copy;
   return (bits & ~copy2) | (copy2 & 1);
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return ((((~x + 1) >> 31) |(x>>31))+ 1);
  }
//extra credit
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  {  
  unsigned highpostive = 0x7FFFFFFF;		
  unsigned minNone = 0x7F800001;
  unsigned res = uf & highpostive;		// set sign bit to 0
  
  // return argument if it is NaN, all NaN >= minimum NaN
  if (res >= minNone)
  {
    return uf;
  }
  else
  {
    return res;
  }
} 

}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int allOne = 1 << 31;//sign
  int tempOne = (allOne >> 8);
  int e_mask = allOne^tempOne;//exp
  int neg_1 = allOne >> 31;
  int f_mask = ~tempOne;//fact
  int odd_mask = 3;
  int case_mask = 1 << 22;
  int s = allOne & uf;//if negative this would be 1<<31 if postive 0 <<31
  int e = e_mask & uf;//the expoentent bit
  int f = f_mask & uf;//returns fractbit
  int E = e_mask ^ e;// if e is 0 the they where equal and is all omnes infinity
  int odd = odd_mask & f;//the fract bit with either 0 or 11 on the end
  int O = !(odd^3);//checks if the frqch had three on the end 1 if it did 0 if it didnt
  int shift = (f + O) >> 1;//shifts it left one mutiply by .5

  //NaN Case
  if (!E)
    return uf;
  // exp = 0 case */
  if (!e){
    return s | shift;
  }
  // exp = 1 case
  // shift from norm to denorm 
  if (!((e >> 23)^1)){
    return s | case_mask | shift;
  }
 // decrease exp by 1
  return s | ((e + neg_1)& e_mask) | f;
  
  return 2;

}
