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

// 汉诺塔问题
/*
算法思路：1将 n-1个盘子先放到B座位上
2.将A座上地剩下的一个盘移动到C盘上
3、将n-1个盘从B座移动到C座上
*/
//函数声明
void move(char c1, char c2);
void hannuo(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, z); //递归截止条件
	else
	{
		hannuo(n - 1, x, z, y);//将 n-1个盘子先放到B座位上
		move(x, z);//将A座上地剩下的一个盘移动到C盘上
		hannuo(n - 1, y, x, z);//将n-1个盘从B座移动到C座上

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