#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* my_strstr(const char *s1, const char *s2)
{   
	char*p1 = (char*)s1;   
	char*p2 = (char*)s2;   
	char* s0 = (char*)s1;  
	if (*s2 == '\0')
	{
		return s0;
	}
	while (*s0)
	{
		while ((*s0 != *p2)&&*s0 !='\0')  //先找到第一个相等的位置，但与后面那句话不能少，因为可能里面一个都没与它相等的
		{
			s0++;
		}
		if (*s0 == '\0')       //此时已经将s1全遍历了，没找到，返回null
		{
			return NULL;
		}
		p1 = s0;              //s0不能变，因为如果没找到的话，s0还能用来记住位置
		while (*p1 == *s2)     //从相当的字符开始找，直到找到‘\0’才算成功，这是说明把s2全遍历了一遍，全都相等
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')        //这时发挥s0的用处，它之前记住了第一个相等字符的地址，这时再返回
		{
			return s0;
		}
		p2 = (char*)s2;    
		s0++;                 // 这是说明不成功，也就是从s0记录的那个位置往后不行，那么就将s0往后一个位置
	}
	return NULL;
}
int main()
{
	char arr1[] = "abcd";
	/*char arr2[] = "b"      或者char arr[]="bd",等这些情况我都测试过了，都可以过   */
    char arr2[] = "ac";       //像这种情况就过不了，不会打印出来找不到
	/*char* ret = strstr(arr1, arr2);*/
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
	{
		printf("%s", ret);
	}
	else
	{
		printf("找不到");
	}
	return 0;
}