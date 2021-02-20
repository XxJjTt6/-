#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main() {
//	char strings[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 ,0};
//	printf("%s\n", strings);
//	return 0;
//}

//int main()
//{
//	int a[8] = { 0 };
//	for (int i = 0; i<8; i++)
//	{
//		scanf("%d", a[i]);
//	}
//	printf("year=%d%d%d%d", a[0], a[1], a[2], a[3]);
//	printf("month=%d%d", a[4], a[5]);
//	printf("date=%d%d", a[6], a[7]);
//}

//int main()
//{
//	int a, b = 0;
//	scanf("%d,%d", &a, &b);
//	int temp;
//	temp = b;
//	b = a;
//	a = temp;
//	printf("a=%d,b=%d", a, b);
//}
//int main()
//{
//	int a = 40, c = 212;
//	printf("%d", (-8 + 22)×a - 10 + c / 2);
//}

//int main()
//{
//	float a = 0;
//	scanf("%f", &a);
//	int b = (int) float a;
//	printf("%d", b % 10);
//}


//int main()
//{
//	int second = 0;
//	scanf("%d", &second);
//	if (second >= 0 && second<3600)
//		printf("0 %d %d", second / 60, second % 60);
//	if (second >= 3600)
//		int hour = 0;
//	hour = second / 3600;
//	printf("%d %d %d", hour, (second - 3600 * hour) / 60, second % 60);
//}

//#include<stdio.h>
//#define pi 3.1415926
//int main()
//{
//	float r = 0;
//	scanf("%f", &r);
//	double v = (4.0 / 3)*pi*r*r*r;
//	printf("%.3lf", v);
//}

/*define P 3.1415926
int main(){
float r,V;
scanf("%f",&r);
printf("%.3f",P*4/3*r*r*r);
return 0;
}*/

//int main()
//{
//	char a = 0;
//	while (scanf("%c", &a) != EOF)
//	{
//		getchar();
//		printf("%c\n", a + 32);
//	}
//}


//int main()
//{
//	int n, h, m = 0;
//	int sheng = 0;
//	while (scanf("%d %d %d", &n, &h, &m) != EOF)
//	{
//		if (m%h == 0)
//		{
//			sheng = n - m / h;
//		}
//		else
//		{
//			sheng = n -m/h - 1;
//		}
//		printf("%d\n", sheng);
//	}
//}

//int main()
//{
//	int n, h, m;
//	int i;
//
//	while (EOF != scanf("%d %d %d", &n, &h, &m))
//		printf("%d", n - (m / h) - (m%h));
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a, b, c, d, e = 0;
//	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
//	float aver = (a + b + c + d + e) / 5.0;
//	printf("%.1f", aver);
//}


//输入一个十六进制数a，和一个八进制数b，输出a + b的十进制结果（范围 - 231~231 - 1）
//int main()
//{
//	int a, b = 0;
//	scanf("0x%x 0%o", &a, &b);
//	printf("%d", a + b);
//}


//int main()
//{
//	for (int i = 10000; i <= 99999; i++)
//	{
//		//第一个空槽
//		int a = i / 10000;
//		int b = i % 10000;
//		long long c = a*b;
//		//2
//		int a2 = i / 1000;
//		int b2 = i % 1000;
//		long long c2 = a2*b2;
//			//3
//	    int a3 = i / 100;
//		int b3 = i % 100;
//		long long c3 = a3*b3;
//		//4
//		int a4 = i / 10;
//		int b4 = i % 10;
//		long long c4 = a4*b4;
//		if (i == c + c2 + c3 + c4)
//			printf("%d ", i);
//	}
//}

int main()
{
	char c[1000] = { 0 };
	int i = 0;
	int a=0, b = 0;
	for (i = 0; i<1000; i++)
	{
		scanf("%c", c[i]);
	}
	for (i = 0; i<1000; i++)
	{
		if (c[i] == 'A')
			a++;
		else if (c[i] == 'B')
			b++;
		else
			break;

	}
	if (a == b)
		printf("E\n");
	else if (a>b)
		printf("A\n");
	else if (a<b)
		printf("B");
}