#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* my_strstr(const char *s1, const char *s2)
{   
	char*p1 = (char*)s1;   
	char*p2 = (char*)s2;   
	char* s0 = (char*)s1;  
	if (*s2 == '\0')
	{
		return s0;
	}
	while (*s0)
	{
		while ((*s0 != *p2)&&*s0 !='\0')  //���ҵ���һ����ȵ�λ�ã���������Ǿ仰�����٣���Ϊ��������һ����û������ȵ�
		{
			s0++;
		}
		if (*s0 == '\0')       //��ʱ�Ѿ���s1ȫ�����ˣ�û�ҵ�������null
		{
			return NULL;
		}
		p1 = s0;              //s0���ܱ䣬��Ϊ���û�ҵ��Ļ���s0����������סλ��
		while (*p1 == *s2)     //���൱���ַ���ʼ�ң�ֱ���ҵ���\0������ɹ�������˵����s2ȫ������һ�飬ȫ�����
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')        //��ʱ����s0���ô�����֮ǰ��ס�˵�һ������ַ��ĵ�ַ����ʱ�ٷ���
		{
			return s0;
		}
		p2 = (char*)s2;    
		s0++;                 // ����˵�����ɹ���Ҳ���Ǵ�s0��¼���Ǹ�λ�������У���ô�ͽ�s0����һ��λ��
	}
	return NULL;
}
int main()
{
	char arr1[] = "abcd";
	/*char arr2[] = "b"      ����char arr[]="bd",����Щ����Ҷ����Թ��ˣ������Թ�   */
    char arr2[] = "ac";       //����������͹����ˣ������ӡ�����Ҳ���
	/*char* ret = strstr(arr1, arr2);*/
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
	{
		printf("%s", ret);
	}
	else
	{
		printf("�Ҳ���");
	}
	return 0;
}