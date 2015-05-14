// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : Wang MaLong
// Date   : 2015-05-14
// Runtime: 41ms

/**********************************************************************************
*
* Determine whether an integer is a palindrome. Do this without extra space.

* click to show spoilers.

* Some hints:
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
* 
**********************************************************************************/


#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef enum{true=1, false=0} bool;

bool isPalindrome(int x) {

    int tmp = x, new_num = 0;

    if( x<0 ) return false;

    while(tmp>0)
    {
        //只剩最后一个数字时开始判断是否溢出。
        if(tmp<10)
        {
            //上溢出
            if( new_num > (INT_MAX-tmp%10)/10 ) return 0;
        }

        new_num = new_num*10 + tmp%10;
        tmp = tmp/10;
    }

    return new_num==x;    
}

int main()
{

    printf("%d %s\n", 12321, isPalindrome(12321)?"y":"n");
    printf("%d %s\n", -123, isPalindrome(-123)?"y":"n");
    printf("%d %s\n", -1000000003, isPalindrome(-1000000003)?"y":"n");
    printf("%d %s\n", 1000000001, isPalindrome(1000000001)?"y":"n");
    printf("%d %s\n", 0, isPalindrome(0)?"y":"n");
    printf("%d %s\n", -2147447412, isPalindrome(-2147447412)?"y":"n");

    return 0;
}
