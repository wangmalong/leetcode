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
