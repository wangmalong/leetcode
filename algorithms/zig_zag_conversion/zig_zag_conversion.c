// Source : https://oj.leetcode.com/problems/zigzag-conversion/
// // Author : Wang MaLong
// // Date   : 2015-05-13
// // Runtime: 8 ms
//
// /********************************************************************************** 
// * 
// * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// * (you may want to display this pattern in a fixed font for better legibility)
// * 
// * P   A   H   N
// * A P L S I I G
// * Y   I   R
// * 
// * And then read line by line: "PAHNAPLSIIGYIR"
// * 
// * Write the code that will take a string and make this conversion given a number of rows:
// * 
// * string convert(string text, int nRows);
// * 
// * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
// * 
// *               
// **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int i=0, j=0, k=0, idx=0, step=0;
    int len = strlen(s);
    char *dst = (char*)calloc(1, len+1);

    for(i=0; i<numRows; i++)
    {
        if(i==0 || i==numRows-1) 
        {
            step = (numRows==1?1:(2*numRows-2));
            for(j=i;j<len;j+=step)
                dst[idx++]=s[j];
        }    
        else
        {
            for(j=i,k=1; j<len; j+=(k%2==1?2*(numRows-i-1):2*i),k++)
                dst[idx++]=s[j];
        }
    }    
    return dst;
}

int main()
{
    char *s = "PAYPALISHIRING";
    int r = 3;
    
    printf("%s: %s\n", s, convert(s, r));

    return 0;
}
