// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : Wang MaLong
// Date   : 2015-05-15
// Runtime: 2ms

/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _prefix{
	char *value;
	int len;
}prefix;

void getCommonPreix(prefix *pref, char *next_str)
{
	int pos = 0, next_str_len=0;

	next_str_len = strlen(next_str);

	while(pos < pref->len && pos < next_str_len)
	{
		if (pref->value[pos] != next_str[pos]) 
		{
			pref->len = pos;
			break;
		}

		pos++;
	}

	pref->len = pos;
}

char* longestCommonPrefix(char **strs, int strsSize)
{
	char *ret;
	int i=1;
	prefix pref;
	
	if (strsSize == 0) return NULL;
	if (strsSize == 1) return strs[0];

	pref.value = strs[0];
	pref.len = strlen(strs[0]);


	while(i<strsSize)
	{
		getCommonPreix(&pref, strs[i++]);
	}

	if (pref.len == 0) return NULL;

	ret = (char*)calloc(1, pref.len+1);
	strncpy(ret, pref.value, pref.len);

	return ret;
}

int main()
{
	char *strs[] = {"aa","a"};
	char *p = longestCommonPrefix(strs, 2);

	printf("%s\n",p?p:"NONE");

	return 0;
}
