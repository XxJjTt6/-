#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int hour = 0;
//	int minute = 0;
//	int hour2 = 0;
//	scanf("%d:%d", &hour, &minute);
//	if (hour == 24 && minute == 0)
//		printf("0:0 AM");
//	if (hour>12)
//	{
//		hour2 = hour - 12;
//		printf("%d:%d PM",hour2, minute);
//	}
//	if (hour == 12 && minute == 0)
//		printf("12.0 PM");
//	if (hour >= 0 && hour<12)
//		printf("%d:%d AM", hour, minute);
//	return 0;
//}
//int main()
//{
//	float tun = 0;
//	float y = 0;
//	if (tun >= 0 && tun <= 15)
//		y = 4 * tun / 3;
//	else
//		y = tun*2.5-17.5;
//	printf("%.2f", y);
//	return 0;
//}

//int main()
//{
//	float Open, High, Low, Close = 0;
//	scanf("%f %f %f %f",&Open,&High,&Low,&Close);
//	if (Close<Open)
//	{
//		if (Low<Open&&Low<Close && (High <= Open || High <= Close))
//			printf("BW-Solid with Lower Shadow");
//		if (High>Open&&High>Close && (Low >= Open || Low >= Close))
//			printf("BW-Solid with Upper Shadow ");
//		if (High>Open&&High>Close&&Low<Open&&Low<Close)
//			printf("BW-Solid with Lower Shadow and Upper Shadow");
//	}
//	if (Close>Open)
//	{
//		if (Low<Open&&Low<Close && (High <= Open || High <= Close))
//			printf("R-Hollow with Lower Shadow");
//		if (High>Open&&High>Close && (Low >= Open || Low >= Close))
//			printf("R-Hollow with Upper Shadow ");
//		if (High>Open&&High>Close&&Low<Open&&Low<Close)
//			printf("R-Hollow with Lower Shadow and Upper Shadow");
//	}
//	if (Close = Open)
//	{
//		if (Low<Open&&Low<Close && (High <= Open || High <= Close))
//			printf("R-Cross with Lower Shadow");
//		if (High>Open&&High>Close && (Low >= Open || Low >= Close))
//			printf("R-Cross with Upper Shadow ");
//		if (High>Open&&High>Close&&Low<Open&&Low<Close)
//			printf("R-Cross with Lower Shadow and Upper Shadow");
//	}
//	return 0;
//}
//
//#include <stdio.h>  模板化的方法
//
//void Shadow(char S[], double open, double close, double high, double low);
//
//int main()
//{
//	char S[3][15] = { "BW-Solid", "R-Hollow", "R-Cross" };
//	double open, close, high, low;
//	scanf("%lf%lf%lf%lf", &open, &high, &low, &close);
//	if (open > close)
//	{
//		Shadow(S[0], open, close, high, low);
//	}
//	else if (open < close)
//	{
//		Shadow(S[1], open, close, high, low);
//	}
//	else
//	{
//		Shadow(S[2], open, close, high, low);
//	}
//	return 0;
//}
//
//void Shadow(char S[], double open, double close, double high, double low)
//{
//	if ((low < open && low < close) && !(high > open && high > close))
//	{
//		printf("%s with Lower Shadow", S);
//	}
//	else if ((high > open && high > close) && !(low < open && low < close))
//	{
//		printf("%s with Upper Shadow", S);
//	}
//	else if ((high > open && high > close) && (low < open && low < close))
//	{
//		printf("%s with Lower Shadow and Upper Shadow", S);
//	}
//	else
//	{
//		printf("%s", S);
//	}
//}

//#include<stdio.h>
//int main()
//{
//	int A, B = 0;
//	scanf("%d %d", &A, &B);
//	int i = 0;
//	int count = 0;
//	for (i = A; i <= B; i++)
//	{
//		printf("%5d", i);
//		count++;
//		if (count%5== 0 && count !=B)
//			printf("\n");
//	}
//	int number = B - A + 1;
//	float Sum = 0;
//	Sum = ((A + B)*number) / 2.0;
//	printf("\nSum=%.0f", Sum);
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	int a, b, i, sum = 0, x = 0;
//	scanf("%d %d", &a, &b);
//	for (i = a; i <= b; i++){
//		printf("%5d", i);
//		x++;
//		if (x % 5 == 0 && i != b)
//			printf("\n");
//		sum += i;
//	}
//	printf("\n");
//	printf("Sum = %d", sum);
//	return 0;
//}
//int main()
//{
//	double limit = 0;
//	scanf("%lf", &limit);
//	int fenzi = 1;
//	int fenmu = 3;
//	int temp1 = 1;
//	int temp2 = 3;
//	double sum2 = 0;
//	double sum = 1;
//	double pi = 0;
//	while (sum2 >= limit)
//	{
//		sum2 = fenzi / fenmu;
//		sum = sum + sum2;
//		temp1++;
//		temp2 = temp2 + 2;
//		fenzi = fenzi*temp1;
//		fenmu = fenmu*temp2;
//	}
//	pi = sum * 2;
//	printf("%.6lf", pi);
//}

/*#include<stdio.h>
int main()
{
int A;
scanf("%d",&A);
int min=A*100+(A+1)*10+A+2;
int max=(A+3)*100+(A+2)*10+A+1;
int i=min;
int count=0;
for(i=min;i<=max;i++)
{
count++;
printf("%d ",i);
if(count%6==0)
printf("\n");
}
return 0;
}*/
/*#include<stdio.h>
int main()
{
int i,j,k;
int huan_hang=0;	//控制空格和换行
int t,n;
scanf("%d",&t);
n=t;
for(i=n;i<=n+3;i++)
{
for(j=n;j<=n+3;j++)
{
if(i!=j)
{
for(k=n;k<=n+3;k++)
{
if(j!=k&&i!=k)
{
huan_hang++;	//控制空格和换行
if(huan_hang<=5)
printf("%d%d%d ",i,j,k);
else
printf("%d%d%d",i,j,k);
if(huan_hang%6==0)
{
printf("\n");
huan_hang=0;
}
}
}
}
}
}
return 0;
}*/

//#include<stdio.h>
//int main(void) {
//	int i, j, k, a, count;
//	int n[4];
//	scanf("%d", &a);
//	for (i = 0; i < 4; ++i)
//		n[i] = a + i;
//	for (i = 0; i < 4; ++i) {
//		count = 0;
//		for (j = 0; j < 4; ++j) {
//			for (k = 0; k < 4; ++k) {
//				if (k != i && k != j && i != j) {
//					printf("%d", 100 * n[i] + 10 * n[j] + n[k]);
//					++count;
//					if (count % 6 == 0)
//						printf("\n");
//					else
//						printf(" ");
//				}
//			}
//		}
//	}
//	return 0;
//}