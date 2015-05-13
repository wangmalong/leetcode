// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Author : Wang MaLong
// Date   : 2015-05-13
// Runtime: 4 ms

/********************************************************************************** 
* 
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge, 
*       please do not see below and ask yourself what are the possible input cases.
* 
* Notes: 
*   It is intended for this problem to be specified vaguely (ie, no given input specs). 
*   You are responsible to gather all the input requirements up front. 
* 
* 
* Requirements for atoi:
* 
* The function first discards as many whitespace characters as necessary until the first 
* non-whitespace character is found. Then, starting from this character, takes an optional 
* initial plus or minus sign followed by as many numerical digits as possible, and interprets 
* them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, 
* which are ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, 
* or if no such sequence exists because either str is empty or it contains only whitespace 
* characters, no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value 
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) 
* is returned.
*               
**********************************************************************************/

#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

#define S0 0
#define S1 1
#define S2 2
#define S3 3

int myAtoi(char* str) 
{
    char *p=str, sign=1;
    int result=0, state=S0, digit=0;
    
    while( *p != '\0' )
    {
        switch( state )
        {
            case S0:
            {
                if( *p=='-' ) { sign = -1; state = S1; } 
                else if( *p=='+' ) { sign = 1; state = S1; }
                else if( *p>='0' && *p<='9' ) { result = result*10 + *p - '0'; state = S2; }
                else if( *p==' ' || *p=='\t' ) { state = S0; }
                else { state=S3; return 0; }
                break;
            }
            case S1:
            {
                if( *p>='0' && *p<='9' ) { result = result*10 + *p - '0'; state = S2; }
                else { state = S3; return 0; }
                break;
            }
            case S2:
            {
                if ( *p>='0' && *p<='9' ) 
                {
                    digit = *p-'0';
                    if ( sign == -1 )
                    {
                        if( -result < (INT_MIN + digit)/10 ) { return INT_MIN; }
                    }
                    else {
                        if( result > (INT_MAX - digit)/10 ) { return INT_MAX; }
                    }
                    result = result*10 + digit; 
                    state = S2;
                }
                else { return result*sign; }
                break;
            }
        }
        p++;
    }
    return result*sign;
}

int main()
{
    printf("\"%s\" = %d\n", "123", myAtoi("123"));
    printf("\"%s\" = %d\n", "   123", myAtoi("    123"));
    printf("\"%s\" = %d\n", "+123", myAtoi("+123"));
    printf("\"%s\" = %d\n", " -123", myAtoi(" -123"));
    printf("\"%s\" = %d\n", "123abc", myAtoi("123abc"));
    printf("\"%s\" = %d\n", " abc123abc", myAtoi(" abc123abc"));
    printf("\"%s\" = %d\n", "   11474836470", myAtoi("   11474836470"));
    printf("\"%s\" = %d\n", "2147483647", myAtoi("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", myAtoi("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", myAtoi("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", myAtoi("-2147483649"));
}
