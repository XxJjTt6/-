#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, (3, 4), 5 };
	printf("%d\n", sizeof(arr));//�������arr������ռ�Ŀռ��С
	return 0;
}

#include <stdio.h>
int main()
{
	char str[] = "hello bit";
	printf("%d %d\n", sizeof(str), strlen(str));
	return 0;
} /*str�ַ�����ʹ��"hello bit"��ʼ��������Ҳ�Ὣ'\0'���õ������У�����������ܹ���10��Ԫ��

sizeof(str)����ȡ������ܴ�С��10��Ԫ�أ�ÿ��Ԫ��ռ1���ֽڣ�����ܹ���10���ֽ�

strlen(str) : ��ȡ�ַ�������Ч�ַ��ĸ���������'\0'������ܹ�9����Ч�ַ�

������printf��ֱ��ӡ��10  9*/