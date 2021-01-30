#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//#include<math.h>
//实现一个对整形数组的冒泡排序
//void paixu(int a[])
//{ 
//	int i = 0;
//	int j = 0;
//	int flag==1
//	for (i = 0; i < 9; i++)
//	{
//		for (j = 1; j < 10- i; j++)
//		{
//			if (a[j-1] >a[j])
//			{
//				int temp = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = temp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//int main()
//{
//	int a[10] = { 3, 4, 5, 7, 1, 2, 6, 9, 0, 8 };
//	paixu(a);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//		printf("%d", a[i]);
//	return 0;
//}

//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
//void init(int a[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		a[i] = 0;
//}
//
//
//void reverse(int *a, int sz)
//{
//	int *left = a;
//	int *right = a + sz - 1;
//	int temp = 0;
//	while (left < right)
//	{
//		int temp = *right;
//		*right = *left;
//		*left = temp;
//		left++;
//		right++;
//	}
//}
//
//void print(int a[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		printf("%d", a[i]);
//}
//
//int main()
//{
//	int a[5] = { 0, 1, 2, 3, 4 };
//	int sz = sizeof(a) / sizeof(a[0]); 
//	init(a,sz);
//	reverse(a, sz);
//	print(a, sz);
//	return 0;
//}


//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//void huan(char*a, char*b)
//{
//	char c = 0;
//	while (*a != '\0')
//	{
//		*a = *b;
//		c = *a;
//		*b = c;
//		a++;
//		b++;
//	}
//}
//void print(char *a,char *b)
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d", a[i]);
//	}
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d", b[i]);
//	}
//}
//
//int main()
//{
//	char a[10] = "hello";
//	char  b[10] = "apple";
//	huan(a, b);
//	print(a,b);
//	return 0;
//}


//写一个函数，可以逆序一个字符串的内容
//void nxu(char *a, int sz)
//{
//	char *left = a;
//	char *right = a + sz - 2;
//	char temp = 0;
//	int i = 0;
//	while (left < right)
//	{
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//	for (i = 0; i < sz - 1; i++)
//	{
//		printf("%c", *(a + i));
//	}
//}
//int main()
//{
//	char a[5] = "abcd";
//	int sz = sizeof(a) / sizeof(a[0]);
//	nxu(a,sz);
//	return 0;
//}


//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//
//例如：2 + 22 + 222 + 2222 + 22222
//int cal(int n,int i)
//{   
//	int ret = 0;
//	int k = 0;
//	int temp = 0;
//	for(k = 0; k < i; k++)
//	{
//		temp= temp* 10 +n;
//		ret += temp;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d%d", &n,&i);
//	int sum = 0;
//	sum=cal(n,i);
//	printf("%d", sum);
//}   95623
 

//求出0～100000之间的所有“水仙花数”并输出。
//
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”
//int Pow(int m, int k)
//{
//	k = 3;
//	for (k = 1; k < 3; k++)
//	{
//		m *= m;
//	}
//	return m;
//}
//int Pow(int m, int count)
//{
//	int k = 1;
//	int kong=m;
//	for (k= 1; k < count; k++)
//	{  
//		kong *= m;	
//	}
//	return kong;
//}
//
//void shuixian()
//{
//	int i = 0;
//	for (i = 1; i <= 100000; i++)
//	{
//		int count = 1;
//		int sum = 0;
//		int temp = i;
//		while (temp / 10)
//		{
//			count++;
//			temp = temp / 10;
//		}
//		temp = i;
//		while (temp)
//		{
//			sum += Pow(temp % 10, count);
//			temp = temp / 10;
//		}
//		if (sum == i)
//			printf("%d  ", i);
//	}
//}
//int main()
//{
//	shuixian();
//	return 0;
//}

int main()
{
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//打印上半部分
	for (i = 0; i < line; i++)
	{
		//打印一行
		//打印空格
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}