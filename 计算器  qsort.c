#define _CRT_SECURE_NO_WARNINGS 1
//����ָ�������Ӧ��-ת�Ʊ�
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
//	/*	printf("Please input two numbers");             �����д�ں�����Ϊ�˷�ֹ�û�����0�˳�ʱ����ʱû��Ҫ��������������������
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
//struct arr //����һ������
//{
//	char name[20];
//	int age;
//};
////int cmpbyname(const void* e1, const void* e2)
////{
////	//return *(struct arr* )e1->name)//�����ַ�֮��Ƚ�Ҫ���ַ��ȽϺ���
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
////		printf("%d", a[i].age);        //Ϊʲô����û��д��ָ�����ʽ��
////	}
////}
////struct arr //����һ������
////{
////	char name[20];
////	int age;
////};
//int main()
//{
//	/*int arr[] = { 1, 3, 5, 2, 4, 6, 9, 8, 7 };*/
//	struct arr a[] = { { "jiangtao", 20 }, { "jintao", 21 }, { "bo", 23 } };
//	int sz = sizeof(a) / sizeof(a[0]);
//	/*qsort(arr, sz, sizeof(arr[0]), cmp);�����������������*/
//	qsort(a, sz, sizeof(a[0]), cmpbyage);
//	/*print(a, sz);*/
//}


   //��ð��������ʵ��qsort
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
	//return *(struct arr* )e1->name)//�����ַ�֮��Ƚ�Ҫ���ַ��ȽϺ���
	return strcmp((struct arr*)e1, (struct arr*)e2);
}
void swap(char* e1, char* e2, int width)  
{
	int i = 0;
	for (i = 0; i < width; i++)
	{ 
		char temp = *e2;         //��סҪ�����ã���Ȼ���ַ�����û�ã���Ϊ����û����ȥ
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