#define _CRT_SECURE_NO_WARNINGS   1
//#include<stdio.h>
//int main()
//{  int i;
//for (i = 1; i <= 100; i++)
//{
//	if (i % 2 == 1)
//		printf("%d\n", i);
//}
//  return 0;//�˴����������1-100֮�������
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i += 2)
//	{
//		printf("%d\n", i);
//	}
//	return 0;������ѭ���Ĵ�����ѭ��50�Σ��Ҳ���Ҫ�жϣ���ǿ�˳����Ч��
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;ֱ������ѭ��
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
//			continue;//����ѭ�����µĶ���ȫ������Ȼ�����´�ѭ��
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
	printf("��ע�⣬��ĵ��Խ���һ���Ӻ�ػ���������룺��������ȡ���ػ�");
	scanf("%s", input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}