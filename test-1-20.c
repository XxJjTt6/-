#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int main()
//{
//	int i=0, j = 0;
//	for (; i < 10; i++)
//	{  
//		for (; j < 10; j++)  i��1֮���ȥǶ��ѭ������ʱj=10����ѭ��������ֻ��ӡ10��hehe
//		{
//			printf("hehe\n");
//		}
//	}
//
//
//
//
//	return 0;
//}


//����n�Ľײ�,n����̫�󣬲�Ȼ���ݻ�������޷�������
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int sum =1;
//	printf("������һ��������");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum *=  i;
//	}
//	printf("%d", sum);
//	return 0;
//}


//������ײ�ĺ�
//����1
//int main()
//{
//		int i = 1;
//		int n = 0;
//		int sum = 0;
//		int temp = 1;
//		printf("������һ��������");
//		scanf("%d", &n);
//		for (i = 1; i <= n; i++)
//		{
//			temp*= i;
//			sum += temp;
//		}
//		printf("%d", sum);
//		return 0;
//}

//����2
//int main()
//{
//	int n = 0;
//	int i = 1;
//	int sum = 0;
//	int ret = 1;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//int main(){
//	for (int i = 0; i<3; i++){
//		for (int j = 0; j<5; j++){
//			if (i == j || j == 4 - i)
//				printf("v");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//}

#include<stdio.h>
int main()
{

	for (int i = 0; i<11; i++)
	{
		if (i == 0 || i == 2)
		{
			printf("     **\n");
		}
		if (i == 4 || i == 6)
		{
			printf("************\n");
		}
		if (i == 8 || i == 10)
		{
			printf("    *  *\n");
		}

	}
}