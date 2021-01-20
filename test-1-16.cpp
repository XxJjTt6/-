#define _CRT_SECURE_NO_WARNINGS   1
//#include<stdio.h>
//int main()
//{  int i;
//for (i = 1; i <= 100; i++)
//{
//	if (i % 2 == 1)
//		printf("%d\n", i);
//}
//  return 0;//此代码用来输出1-100之间的奇数
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i += 2)
//	{
//		printf("%d\n", i);
//	}
//	return 0;减少了循环的次数，循环50次，且不需要判断，增强了程序的效率
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;直接跳出循环
//		printf("%d", i);
//		i++;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;//本次循环往下的东西全不做。然后做下次循环
//		printf("%d", i);
//		i++;
//	}
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[20] = "";
	system("shutdown -s -t 60");
again:
	printf("请注意，你的电脑将在一分钟后关机，如果输入：我是猪，就取消关机");
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}