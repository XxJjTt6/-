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
//	//�����
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	//���ֲ��ҵ�
//	//�ҵ��ˣ������±�
//	//�Ҳ��������� -1
//	int sz = 0;
//	sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//
//	return 0;
//}


//int main()
//{
//	printf(��������һ����ݺ����е�һ���·ݡ�);
//	int year = 0;
//	int month = 0;
//	scanf(��%d %d����&year, &month);
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
//	{       ע��while�����Ų�����
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


//ʵ��һ���������ж�һ�����ǲ���������

//��������ʵ�ֵĺ�����ӡ100��200֮�������
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

//ʵ�ֺ����ж�year�ǲ������ꡣ
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
//	printf("�����������жϵ�һ��\n");
//	scanf("%d", &year);
//	if (run(year) == 1)
//		printf("����������\n");
//	else printf("��������\n");
//	return 0;
//}


//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��

//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���


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
//	printf("������һ��������");
//		scanf("%d", &n);
//	print(n);
//	return 0;
//	
//}
