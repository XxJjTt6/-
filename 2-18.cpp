#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//float hanshu(float n, float a3, float a2, float a1, float a0)
//{
//	float k = a3*n*n*n + a2*n*n + a1*n + a0;
//	return k;
//}
//int main()
//{
//	float a3, a2, a1, a0, a, b = 0;
//	scanf("%d %d %d %d", &a3, &a2, &a1, &a0);
//	scanf("%d %d", &a, &b);
//	double limit = 0.001;
//	float n = (a + b) / 2;
//	float f = hanshu(n, a3, a2, a1, a0);
//	while ((b - a)>limit)
//	{
//		if (f == 0)
//		{
//			printf("%.2f", n);
//			break;
//		}
//		else if (f*hanshu(a, a3, a2, a1, a0)>0)
//		{
//			a = n;
//			n = (a + b) / 2;
//		}
//		else if (f*hanshu(b, a3, a2, a1, a0)>0)
//		{
//			b = n;
//			n = (a + b) / 2;
//		}
//	}
//	return 0;
//}*/
//
//int main()
//{
//	int y, f, n = 0;
//	scanf("%d", &n);
//	for (y = 0; y<100; y++)
//	for (f = 0; f<100; f++)
//	if (200 * y + 2 * f == 100 * f + y - n)
//	{
//		printf("%d.%d", y, f);
//		return 0;       //�����ñ�־�������������һ��flag
//	}
//	printf("No Solution");
//	return 0;
//}
//
//
//int main()
//{
//	int n, f, y, i, j;
//	int flag = 0;
//	scanf("%d", &n);
//	for (y = 0; y<100; y++)
//	{
//		for (f = 0; f<100; f++)
//		{
//			if (200 * y + 2 * f == f * 100 + y - n)
//			{
//				printf("%d.%d", y, f);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//		printf("No Solution");
//	return 0;
//}

//int main()
//{
//	int N = 0;
//	scanf("%d", &N);
//	int i, j = 0;
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= N; j++)
//		{
//			int s = i*j;
//			printf("%d*%d=%-4d", i, j, s);
//			if (i == j)
//				printf("\n");
//		}
//	}
//	return 0;
//}
//1 * 1 = 1
//1 * 2 = 2   2 * 2 = 4
//1 * 3 = 3   2 * 3 = 6   3 * 3 = 9
//1 * 4 = 4   2 * 4 = 8   3 * 4 = 12  4 * 4 = 16  4������i���ƣ�Ӧ����ÿ���������Ǹ������������1,2,3,4�������ڲ��j�����ƣ��������ߵ���ϵ

//#include<stdio.h>
//int main()
//{
//	int N = 0;
//	scanf("%d", &N);
//	int i, j = 0;
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= i; j++)    
//		{
//			printf("%d*%d=%-4d", j, i, i*j);//������˵����ǰ��һ����j������һ����i
//			if (i == j)
//				printf("\n");
//		}
//	}
//	return 0;
//}
//
//int mian()
//{
//	int N = 0;
//	scanf("%d", &N);
//	int x, y = 0;
//	int flag = 0;
//	for (x = 1; x<N; x++)
//	{
//		for (y = 1; y<N; y++)
//		{
//			if (x*x + y*y == N&&y >= x)
//			{
//				printf("%d %d\n", x, y);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//		printf("No Solution");
//	return 0;
//}
//int main()
//{
//	int N = 0;
//	scanf("%d", &N);
//	int x, y = 0;
//	int flag = 0;
//	for (x = 1; x<N; x++)
//	{
//		for (y = 1; y<N; y++)
//		{
//			if (x*x + y*y == N&&y >= x)
//			{
//				printf("%d %d\n", x, y);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//    printf("No Solution");
//	return 0;
//}


int main()
{
	int T, i;
	scanf("%d", &T);
	int s1 = 0, s2 = 0;//s1�ǹ�꣬s2������ 
	for (i = 1; i <= T; i++)
	{
		s1 = s1 + 3;
		s2 = s2 + 9;
		if (i % 10 == 0 && s2>s1)
		{
			if (T - i >= 30)//��ʣʱ���������30���ӣ�ֱ���ù������ʮ���ӣ����ò��� 
			{
				s1 = s1 + 90;
				i += 30;
			}
			else // ��ʣʱ�����С��30���ӣ�ֱ���ù����ʣ�µ�ʱ�䣬���ò��� 
			{
				s1 = s1 + 3 * (T - i);
				break;
			}
		}
	}
	/*if (s2 - s1>0)
		printf("^_^ %d", s2);
	else if (s2 == s1)
		printf("-_- %d", s2);
	else
		printf("@_@ %d", s1);*/
	if (s1=s2)
		printf("-_- %d", s1);
	if (s1>s2)
		printf("@_@ %d", s1);
	if (s2>s1)
		printf("^_^ %d", s2);
	return 0;
}