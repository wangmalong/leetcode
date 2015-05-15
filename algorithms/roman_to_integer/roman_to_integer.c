// Source : https://oj.leetcode.com/problems/roman-to-integer/
// // Author : Wang MaLong
// // Date   : 2015-05-15
// // Runtime: 16ms

/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
* 
* Input is guaranteed to be within the range from 1 to 3999.
***********************************************************************************/


#include <stdio.h>
#include <string.h>

typedef enum{I=1,V=5,X=10,L=50,C=100,D=500,M=1000} roman;

int romanToInt(char *s)
{
    int ret = 0, len=0;
    roman cur, pre;

    len = strlen(s);
    cur = s[len-1];
    pre = I;
    

    while(len>0)
    {
        switch(s[len-1])
        {
            case 'I':
                cur = I; break;
            case 'V':
                cur = V; break;
            case 'X':
                cur = X; break;
            case 'L':
                cur = L; break;
            case 'C':
                cur = C; break;
            case 'D':
                cur = D; break;
            case 'M':
                cur = M; break;
        }

        if(cur >= pre) ret+=cur; 
        else ret -= cur;
        
        pre=cur;
        len--;
    }

    return ret;
}

int main()
{
    printf("%s = %d\n", "I", romanToInt("I"));
    printf("%s = %d\n", "II", romanToInt("II"));
    printf("%s = %d\n", "IV", romanToInt("IV"));
    printf("%s = %d\n", "VI", romanToInt("VI"));
    printf("%s = %d\n", "MVI", romanToInt("MVI"));
    printf("%s = %d\n", "MIV", romanToInt("MIV"));
}
