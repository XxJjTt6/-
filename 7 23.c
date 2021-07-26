#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//strlen 计算字符串和字符数组的长度的
//方法1，指针-指针
//int my_strlen(const char* str)   //最好将返回类型写成size_t类型，因为strlen的返回值类型就是的
//{
//	const char *end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - str;
//}
//方法2，一般方法
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{	
//		count++;
//        str++;
//	}
//	return count;
//}
//方法3，递归
//int my_strlen(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	
//	else
//		return 1 + my_strlen(str+1);        //为什么这儿不能写成str++
//
//}
//int main()
//{
//	char p[] = "abcdef";
//	/*int sum = strlen(p);*/
//	/*printf("%d", strlen(p));*/
//	printf("%d", my_strlen(p));
//	return 0;
//}

//strcpy      复制函数
//my_strcpy的实现
//char* my_strcpy(char* destnation, const char *source)
//{
//	assert(destnation&&source);
//	char *p1 = destnation;
//	char *p2 = source;
//	while (*p2!='\0')
//	{
//		*p1++ = *p2++;
//	}
//	*p1 = '\0';
//	return destnation;
//}
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdefg";
//	/*printf("%s", strcpy(arr1, arr2));*/
//	printf("%s", my_strcpy(arr1, arr2));
//	return 0;
//}


//strcat      追加函数，追加一个字符串到另一个字符串后面 ,函数自己是无法追加自己的，因为如果这样的话，就没有终止条件了
//char* my_strcat(char *p0, const char *p2)
//{
//	assert(p0&&p2);
//	char *p1 = p0;
//	char *p3 = (char *)p2;
//	while (*p1 != '\0')
//	{
//		p1++;
//	}
//	while (*p3 != '\0')
//	{
//		*p1 = *p3;
//		p1++;
//		p3++;
//	}
//	*p1 = *p3;
//	return p0;
//}
//int main()
//{
//	char a1[] = "abcd";
//	char a2[] = "efghigk";
//	/*printf("%s", strcat(a1, a2));*/
//	printf("%s", my_strcat(a1, a2));
//}

//strcmp  比较函数，比较的方式是逐个字符来比较
//int my_strcmp(const char *arr1, const char *arr2)
//{
//	char *p1 = (char *)arr1;
//	char *p2 = (char *)arr2;
//	while (*p1!='\0'||*p2!='\0')
//	{    
//		if (*p1 != *p2)
//		{
//			return *p1 - *p2;
//		}
//		else
//		{
//			p1++;
//			p2++;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "abcdd";
//	/*printf("%d", strcmp(arr1, arr2));*/
//	printf("%d", my_strcmp(arr1, arr2));
//	return 0;
//}


//strncpy           受长度限制，字符串拷贝，自己规定拷贝几个字节过去，如果源头的拷贝字符串没有达到要拷贝字节的需求，那么少的会补'\0'
//char *my_strncpy(char* arr1, const char *arr2,int size)
//{
//	assert(arr1&arr2);
//	char *ret = arr1;
//	while (size--)
//	{
//		*arr1++ = *arr2++;
//		if (*arr2 == '\0'&&size!=0)
//		{
//			*arr1++ = '\0';
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "########";
//	char arr2[] = "abcdef";
//	//printf("%s\n", strncpy(arr1, arr2, 6));
//	//printf("%c", arr1[5]);
//	printf("%s\n", my_strncpy(arr1, arr2, 6));
//	printf("%c", arr1[5]);
//	return 0;
//}

//strncat   
//char* my_strncat(char *arr1, const char* arr2, int sz)
//{
//	char* ret = arr1;
//	while (*ret)
//	{
//		*ret++;
//	}
//	while (sz--&&*arr2)
//	{
//		*ret++ = *arr2++;
//	}
//	*ret = *arr2;
//	while (sz--)
//	{
//		*ret++ = '\0';
//	}
//	return arr1;
//}
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "adf";
//	/*printf("%s\n", strncat(arr1, arr2, 2));*/
//	/*printf("%c", arr1[6]);*/
//	printf("%s\n", my_strncat(arr1, arr2, 2));
//	/*printf("%c", arr1[6]);*/
//	return 0;
//}


//strncmp
//int my_strncmp( char *arr1, char* arr2, int sz)
//{
//	assert(arr1&&arr2);
//	while (* arr1 == *arr2&&sz)
//	{
//		arr1++;
//		arr2++;
//		sz--;
//		if (*arr2 == '\0')
//		{
//			return 0;
//		}
//	}
//	return *arr1 - *arr2;
//}
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "abcd";
//	/*printf("%d", strncmp(arr1, arr2, 3));*/
//	printf("%d", my_strncmp(arr1, arr2, 2));
//	return 0;
//}

//strstr  寻找一个字符串是否含有子字符串
char* my_strstr(const char* arr1, const char* arr2)
{
	char*p1 = (char*)arr1;
	char*p0 = p1;
	char*p2 = (char*)arr2;
	char*ret=(char*) arr2;
	while (*p0&&*p2)
	{
		if (*p2!=*p1)
		{
			p1++;
		}
		p0 = p1;
		while (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return p0;
		}
		p2 = ret;
		p1 = p0;
		++p1;
		/*p1 = p0;
		while (*p1 != *p2)
		{
			p1++;
		}
		p0 = p1;
		while (*p1 = *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return p0;
		}
		p2 = arr2;
		p0++;*/
	}
	return NULL;
}
////char* my_strstr(const char*s1, const char*s2)                                         
////{
////	assert(s1 && s2);
////	const char *cp = s1;
////
////	if (*s2 == '\0')
////		return (char*)s1;
////
////	while (*cp)
////	{
////		const char *p1 = cp;
////		const char *p2 = s2;
////		while ((*p1) && (*p2) &&  (*p1 == *p2))
////		{
////			p1++;
////			p2++;
////		}
////		if (*p2 == '\0')
////		{
////			return (char*)cp;
////		}
////		cp++;
////	}
////	return NULL;
////}
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "ea";
//	/*char* ret = strstr(arr1, arr2);*/
//	char* ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//	{
//		printf("%s", ret);
//	}
//	else
//	{
//		printf("找不到");
//	}
//	return 0;
//}