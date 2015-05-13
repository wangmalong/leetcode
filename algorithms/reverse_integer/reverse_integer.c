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
