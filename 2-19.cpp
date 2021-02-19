#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()   一般求公约数的算法
//{
//	int fenzi = 0;
//	int fenmu = 0;
//	scanf("%d/%d", &fenzi, &fenmu);
//	int i = 1;
//	int min = fenzi < fenmu ? fenzi : fenmu; //(a > b ? b : a)
//	for (i = 1; i <= min; i++)
//	{
//		if (fenzi%i == 0 && fenmu%i == 0)
//		{
//			fenzi /= i;
//			fenmu /= i;
//			i = 1;
//		}
//	}
//	printf("%d/%d", fenzi, fenmu);
//	return 0;
//}

//int gcd(int a, int b)   
//{  
//	int r = a%b;
//	while (r)    辗转相除法求最大公约数。
// {
//		a = b;
//		b = r;
//		r = a%b;
//	}
//	return b;
//}
//int main(){
//	int a, b;
//	scanf("%d/%d", &a, &b);
//	int n = gcd(a, b);
//	printf("%d/%d", a / n, b / n);
//}


//int main()
//{
//	int num = 0;
//	char a[20] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
//	scanf("%d", &num);
//    int count = 0;
//	while (num)
//	{
//		num /= 10;
//		count++;
//	}
//	int k = 0;
//	int b[1000000] = { 0 };
//	for (k = count-1; k >=0; k--)
//   {
//		b[k] = num % 10;
//		num /= 10;
//	}
//	int i, j = 0;
//	for (i = 0; i<count; i++)
//	{
//		for (j = i; j <= i; j++)
//		{
//			j = b[i];
//			printf("%c", a[j]);
//			if (j != count - 1)
//				printf(" ")
//		}
//	}
//	return 0;
//}
//
//#include<math.h>
//int main()
//{
//	int n;
//	int t = 1;	//用t作被除数
//	scanf("%d", &n);
//	//判断n是否为0
//	if (n < 0){
//		printf("fu ");
//	}
//	n = abs(n);	//取n的绝对值
//
//	//求出n的位数
//	int i = n;
//	while (i > 9){
//		i /= 10;	//去掉一位数
//		t *= 10;	//增加一位数
//	}
//
//	do{
//		int a = n / t;
//		if (a == 0) printf("ling");
//		if (a == 1)printf("yi");
//		if (a == 2)printf("er");
//		if (a == 3)printf("san");
//		if (a == 4)printf("si");
//		if (a == 5)printf("wu");
//		if (a == 6)printf("liu");
//		if (a == 7)printf("qi");
//		if (a == 8)printf("ba");
//		if (a == 9)printf("jiu");
//		if (t > 9)printf(" ");
//		n = n % t;
//		t = t / 10;
//	} while (t>0);
//
//	return 0;
//}


#include<stdio.h>
int main()
{
	int n, k = 0;
	scanf("%d %d", &n, &k);
	int i = 0;
	int a[100] = { 0 };
	int temp = 0;
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	int j = 0;
	for (i = 0; i<k; i++)
	{
		for (j = 0; j<n - 1; j++)
		{
			if (a[j]>a[j+ 1])
			{
				temp = a[j + 1];
				a[j+ 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		if (i != n - 1)
			printf("%d ", a[i]);
		else
			printf("%d", a[i]);
	}
	return 0;
}