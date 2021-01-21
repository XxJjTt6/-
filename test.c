//#define _CRT_SECURE_NO_WARNINGS   1
//#include<stdio.h>
//#include<math.h>
//#include<windows.h>
//int add(int x, int y)
//{
//	return (x + y);
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d",add(a, b));
//	return 0;
//

//int is_prime(int i)
//{
//	int n = 1;
//	for (n = 2; n < sqrt(i); n++)
//	{
//		if (i%n == 0)
//		{
//			return 0;
//		}
//		return 1;
//	}
//}
// 
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{  printf("%d",i);
//		}
//	}
//	return 0;
//}
//int ret(int *p, int x,int y)
//{
//	int left = 0;
//	int right = y - 1;
//	int mid = 0;
//	while (1)
//		mid = (left + right) / 2;
//	if (arr[mid] < x)
//		left = mid + 1;
//	if (arr[mid]>x)
//		right = =mid-1;
//	if (arr[mid] = x)
//		return mid;
//
//	
//}
//
//int main()
//{
//	//有序的
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	//二分查找的
//	//找到了，返回下标
//	//找不到，返回 -1
//	int sz = 0;
//	sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//
//	return 0;
//}


//int main()
//{
//	printf(“请输入一个年份和其中的一个月份”);
//	int year = 0;
//	int month = 0;
//	scanf(“%d %d”，&year, &month);
//	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		printf("%d", 31);
//	if (month == 4 || month == 6 || month == 9 || month == 11)
//		printf("%d", 30);
//	if (year % 400 == 0 || year % 4 == 0 && year % 100 !=0)
//	{
//		if (month == 2)
//			printf("%d", 29);
//		else printf("%d", 28);
//	}
//	return 0;
//}

//int main()
//{
//	int year = 0;
//	int month = 0;
//	while (~scanf("%d %d", &year, &month))
//	{       注意while的括号不能少
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//			printf("%d\n", 31);
//		if (month == 4 || month == 6 || month == 9 || month == 11)
//			printf("%d\n", 30);
//		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
//		{
//			if (month == 2)
//				printf("%d\n", 29);
//		}
//		else if (month == 2)
//			printf("%d\n", 28);
//
//		return 0;
//	}
//
//}


//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[7] = { 0 };
//	int temp = 0;
//	int sum = 0;
//	double aver = 0;
//	for (int i = 0; i<7; i++)
//	{
//		scanf("%d", &n);
//		arr[i] = n;
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 6 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int transform = 0;
//				transform = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = transform;
//			}
//		}
//	}
//	for (int i = 0; i<7; i++)
//	{
//		sum += arr[i];
//	}
//	sum = sum - arr[0] - arr[6];
//	aver = sum / 5.0;
//	printf("%.2f\n", aver);
//	return 0;
//}


//实现一个函数，判断一个数是不是素数。

//利用上面实现的函数打印100到200之间的素数
//int prime(int i)
//{
//	int n = 0;
//	for (n = 2; n < sqrt(i); n++)
//	{
//		if (i%n == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (prime(i) == 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//实现函数判断year是不是润年。
//int run(int year)
//{
//	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
//		return 1;
//	else return 0;
//
//}
//int main()
//{
//	int year = 0;
//	printf("请输入你想判断的一年\n");
//	scanf("%d", &year);
//	if (run(year) == 1)
//		printf("此年是润年\n");
//	else printf("不是润年\n");
//	return 0;
//}


//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定

//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。


//void print(int n)
//{
//	int x = 0;
//	for (x = 1; x <= n; x++)
//	{
//		int y = 0;
//		for (y = 1; y <= x; y++)
//		{
//			int z = 0;
//			z = x*y;
//			printf("%d*%d=%2d ", y, x, z);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个正整数");
//		scanf("%d", &n);
//	print(n);
//	return 0;
//	
//}
