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

INTEGER CODING RULES :

Replace the "return" statement in each function with one
or more lines of C code that implements the function.Your code
must conform to the following style :

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

Each "Expr" is an expression using ONLY the following :
1. Integer constants 0 through 255 (0xFF), inclusive.You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables(no global variables).
3. Unary integer operations !~
4. Binary integer operations & ^| +<< >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators.You are not restricted to
one operator per line.

You are expressly forbidden to :
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as&&, || , -, or ? :
	6. Use any form of casting.
	7. Use any data type other than int.This implies that you
	cannot use arrays, structs, or unions.


	You may assume that your machine :
1. Uses 2s complement, 32 - bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE :
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

For the problems that require you to implent floating - point operations,
the coding rules are less strict.You are allowed to use looping and
conditional control.You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to :
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc(data lab checker) compiler(described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators(!~&^| +<< >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc.Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function.If there are any inconsistencies
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
			 /*
			  *   lsbZero - set 0 to the least significant bit of x
			  *   Example: lsbZero(0x87654321) = 0x87654320
			  *   Legal ops: ! ~ & ^ | + << >>
			  *   Max ops: 5
			  *   Rating: 1
			  */
	int lsbZero(int x) {
	return (x >> 1) << 1;//先右移再左移，右移消去最低位，左移自动补0
}
/*
 * byteNot - bit-inversion to byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int byteNot(int x, int n) {
	//一个字节为8位，将n左移3位即8*n
	n <<= 3;
	int y = 0xff;
	y <<= n;//选择要反转的字节位置
	x ^= y;//和1异或能实现反转，而0的部分不变
	return x;
}
/*
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int byteXor(int x, int y, int n) {
	n <<= 3;
	//取出x，y的第n个字节
	x = (x >> n) & 0xff;
	y = (y >> n) & 0xff;
	return !!(x ^ y);//比较是否相同，用！！变为逻辑1和0
}
/*
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalAnd(int x, int y) {
	return !((!x) | (!y));
}
/*
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalOr(int x, int y) {
	return (!(!x) | !(!y));
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n) {
	return ((x << n) | (x >> (0x1F & (32 + ~n + 1)))) & ~(0xFFFFFFFF << n);
}
/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int parityCheck(int x) {
	x = x ^ (x << 16);//将整数的高16位和低16位进行异或操作，将结果保存在 x 中
	x = x ^ (x << 8);//同理
	x = x ^ (x << 4);
	x = x ^ (x << 2);
	x = x ^ (x << 1);
	x &= 0x1;
	return x;
}
/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int mul2OK(int x) {
	//判断最高位和第二位是否相等
	return !((x & (1 << 31)) ^ ((x & (1 << 30)) << 1));
}
/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int mult3div2(int x) {
	int y = (x << 1) + x;//乘3就是左移一位再加自己
	y = (y >> 1) + (((y >> 31) & 1) & (((y << 31) >> 31) & 0x1));
	return y;
}
/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
	int z = x + (~y + 1);
	x = (x >> 31) & 0x1;
	y = (y >> 31) & 0x1;
	z = (z >> 31) & 0x1;
	return (((x ^ y) & (x ^ z)) ^ 0x1);
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	//符号位
	int y = x >> 31;
	//符号位为0，就是x；符号位为1，就是x取反
	x = (y & (~x + 1)) + ((~y) & x);
	return x;
}
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
	//将uf按位与操作，将符号位清零
	int x = uf & 0x7fffffff;
	if (x > 0x7f800000) return uf;//直接返回uf
	else return x;//否则返回绝对值
}
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	int x, y;
	unsigned m = 0x80000000;
	x = (uf >> 23) & 0xff;
	y = (uf & 0x007fffff) ^ 0x00800000;
	if (x > 158) return m;
	if (x < 127) return 0;
	else if (((uf >> 31) & 0x1) == 1) {
		if (x > 150) return ((~(y << (x - 150))) + 1);
		else return ((~(y >> (150 - x))) + 1);
	}
	else {
		if (x > 150) return (y << (x - 150));
		else return (y >> (150 - x));
	}
}
