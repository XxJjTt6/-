//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int weight, high = 0;
//	while (~scanf("%d %d", &weight, &high))
//	{
//		float HIGH = high / 100.0;
//		float bmi = weight / pow(HIGH, 2);
//		if (bmi<18.5)
//			printf("Underweight\n");
//		else if (bmi >= 18.5&&bmi <= 23.9)
//			printf("Normal\n");
//		else if (bmi>23.9&&bmi <= 27.9)
//			printf("Overweight\n");
//		else
//			printf("Obese\n");
//	}
//}
//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a, b, c = 0;
//	while (~scanf("%d %d %d", &a, &b, &c))
//	{
//		if (a == b&&a == c)
//			printf("Equilateral triangle!\n");
//		else if (a == b&&b != c&&a + b>c && (a - b)<c || a == c&&c != b&&a + b>c && (a - b)<c || b == c&&a != b&&a + b>c && (a - b)<c)
//			printf("Isosceles triangle!\n");
//		else if (a + b>c && (a - b)<c)
//			printf("Ordinary triangle!\n");
//		else
//			printf("Not a triangle!\n");
//	}
//}
//
//
//#include<stdio.h>
//
//
//
//int main(){
//	int m, n, k;
//	while (scanf("%d%d%d", &m, &n, &k) != EOF){
//
//		if (m + n>k&&m + k>n&&n + k>m){
//
//			if (m == n&&n == k&&m == k)
//				printf("Equilateral triangle!\n");
//			else if (m == n || m == k || n == k)
//				printf("Isosceles triangle!\n");
//			else  printf("Ordinary triangle!\n");
//
//
//
//		}
//		else{
//			printf("Not a triangle!\n");
//		}
//
//
//
//	}
//
//
//
//
//
//}
//
//
//
//#include<stdio.h>
//int main()
//{
//	int t = 0;
//	while (scanf("%d", &t) != EOF)
//	{
//		getchar();
//		if (t>0)
//			printf("1\n");
//		if (t == 0)
//			printf("0.5\n");
//		if (t<0)
//			printf("0\n");
//	}
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		if (a == b)
//			printf("%d=%d\n", a, b);
//		if (a>b)
//			printf("%d>%d\n", a, b);
//		if (a<b)
//			printf("%d<%d\n", a, b);
//	}
//}