#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include <string.h>
//void print(int n)
//{
//	if (n > 9)
//	{ 
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}



//int main()
//{
//	printf("Hello world!\n");
//	printf("%d", printf("Hello world!\n"));
//	return 0;
//}

// ��ŵ������
/*
�㷨˼·��1�� n-1�������ȷŵ�B��λ��
2.��A���ϵ�ʣ�µ�һ�����ƶ���C����
3����n-1���̴�B���ƶ���C����
*/
//��������
void move(char c1, char c2);
void hannuo(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, z); //�ݹ��ֹ����
	else
	{
		hannuo(n - 1, x, z, y);//�� n-1�������ȷŵ�B��λ��
		move(x, z);//��A���ϵ�ʣ�µ�һ�����ƶ���C����
		hannuo(n - 1, y, x, z);//��n-1���̴�B���ƶ���C����

	}
}
void move(char c1, char c2)
{
	printf("%c--->%c\n", c1, c2);
}

int main()
{
	int n;
	printf("input your number");
	scanf("%d", &n);
	hannuo(n, 'a', 'b', 'c');
	return 0;
}