// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : Wang MaLong
// Date   : 2015-05-13
// Runtime: 6ms

/**********************************************************************************
*
* Reverse digits of an integer.
* 
* Example1: x = 123, return 321
* Example2: x = -123, return -321
* 
* click to show spoilers.
* 
* Have you thought about this?
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
* 
* If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* 
* Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
* 
* For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
* 
* Update (2014-11-10):
* Test cases had been added to test the overflow behavior.
*
**********************************************************************************/


#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x) {
	int sign = x>=0?1:-1;
	int new_num = 0;
	int abs_x = x*sign;

	while(abs_x>0)
	{
		//只剩最后一个数字时开始判断是否溢出。
		if(abs_x<10)
		{
			if(sign==1)
			{
				//上溢出
				if( new_num > (INT_MAX-abs_x%10)/10 ) return 0;
			}
			else if(sign == -1)
			{
				//下溢出
				if( -new_num < (INT_MIN+abs_x%10)/10 ) return 0;
			}
		}
		new_num = new_num*10 + abs_x%10;
		abs_x = abs_x/10;
	}
	return new_num*sign;	
}

int main()
{
	printf("%d --> %d\n", 123, reverse(123));
	printf("%d --> %d\n", -123, reverse(-123));
	printf("%d --> %d\n", -120, reverse(-120));
	printf("%d --> %d\n", 1000000003, reverse(1000000003));
	printf("%d --> %d\n", -1000000003, reverse(-1000000003));

	return 0;
}
