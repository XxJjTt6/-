#define _CRT_SECURE_NO_WARNINGS 1
//函数指针数组的应用-转移表
#include<stdio.h>
#include<string.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x-y;
//}
//
//int	Mul(int x, int y)
//{
//	return x*y;
//}
//
//int	Dive(int x, int y)
//{
//	return x/y;
//}
//
//void menu()
//{
//	printf("**********************************\n");
//	printf("****0.Exit            1.Add   ****\n");
//	printf("****2.Sub             3.Mul   ****\n");
//	printf("****4.Dive                    ****\n");
//	printf("**********************************\n");
//	printf("**********************************\n");
//
//}
//int main()
//{
//	int x, y = 0;
//	int input = 0;
//	int ret = 0;
//	int(*arr[5])(int, int) = { 0, Add, Sub, Mul, Dive };
//	do
//	{
//		menu();
//		printf("Please chose");
//		scanf("%d", &input);
//	/*	printf("Please input two numbers");             把这句写在后面是为了防止用户输入0退出时，这时没必要再让他输入两个数字了
//		scanf("%d%d", &x, &y);*/
//		//int(*arr[5])(int, int) = { 0, Add, Sub, Mul, Dive };
//		if (input >= 1 && input <= 4)
//		{
//			printf("Please input two numbers");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", (*arr[input])(x, y));
//		}
//		else if (0 == input)
//		{
//			printf("Exit\n");
//		}
//		else
//		{
//			printf("Please reselect\n");
//		}
//	} while (input);
//	return 0;
//}



  //qsort

//int cmp(const void* e1, const void* e2)
//{
//	return (*(int *)e1 - *(int *)e2);
//}
//struct arr //这是一个类型
//{
//	char name[20];
//	int age;
//};
////int cmpbyname(const void* e1, const void* e2)
////{
////	//return *(struct arr* )e1->name)//连个字符之间比较要用字符比较函数
////	return strcmp((struct arr*)e1, (struct arr*)e2);
////}
//
//int cmpbyage(const void* e1, const void* e2)
//{
//	return *(int*)e1- *(int *)e2;
//}
//
////void print(struct arr a[],int sz)
////{
////	int i = 0;
////	for (i = 0; i < sz; i++)
////	{
////		printf("%d", a[i].age);        //为什么这里没法写成指针的形式？
////	}
////}
////struct arr //这是一个类型
////{
////	char name[20];
////	int age;
////};
//int main()
//{
//	/*int arr[] = { 1, 3, 5, 2, 4, 6, 9, 8, 7 };*/
//	struct arr a[] = { { "jiangtao", 20 }, { "jintao", 21 }, { "bo", 23 } };
//	int sz = sizeof(a) / sizeof(a[0]);
//	/*qsort(arr, sz, sizeof(arr[0]), cmp);对整形数组进行排序*/
//	qsort(a, sz, sizeof(a[0]), cmpbyage);
//	/*print(a, sz);*/
//}


   //用冒泡排序来实现qsort
struct stu
{
	char name[20];
	int age;
};
//int cmp(const void* e1, const void* e2)
//{
//	return (*(int *)e1 - *(int *)e2);
//}

int cmpbyname(const void* e1, const void* e2)
{
	//return *(struct arr* )e1->name)//连个字符之间比较要用字符比较函数
	return strcmp((struct arr*)e1, (struct arr*)e2);
}
void swap(char* e1, char* e2, int width)  
{
	int i = 0;
	for (i = 0; i < width; i++)
	{ 
		char temp = *e2;         //记住要解引用，不然光地址往后加没用，因为内容没换过去
		*e2 = *e1;  
		*e1 = temp;
		e1++;
		e2++;
	}
}
void bubble_qsort(int a[], size_t sz, size_t width, int(*cmp)(const void* e1, const void* e2))
{
	size_t i, j = 0; 
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if ((*cmp)((char*)a + j*width, (char *)a + (j + 1)*width)>0)
			{
				swap((char*)a + j*width, (char *)a + (j + 1)*width, width);
			}
		}
	}
	/*for (i = 0; i < sz; i++)
	{
		printf("%d", a[i]);
	}*/
}
//void print(int* a, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", *(a + i));
//	}
//}
void print(struct stu arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{ 
		printf("%s", arr[i].name);
	}
}
int main()
{
	/*int a[] = { 1, 3, 5, 2, 4, 6, 9, 8, 7 };*/
	struct stu arr[] = { { "kingtao", 21 }, { "jintao", 20 }, { "bo", 23 } };
	/*int sz = sizeof(a) / sizeof(a[0]);*/
	int sz = sizeof(arr) / sizeof(arr[0]);
	/*bubble_qsort(a, sz, sizeof(a[0]), cmp);*/
	bubble_qsort(arr, sz, sizeof(arr[0]), cmpbyname);
	print(arr, sz);
}