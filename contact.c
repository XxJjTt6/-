#include"contact.h"
//��̬�汾
//void init(struct contact* pz)
//{
//	pz->sz = 0;
//	memset(pz->data, 0, sizeof(pz->data));       //memset��������Ч���ҿ���
//}
//��̬�汾
void init(struct contact* pz)
{
	pz->sz = 0;
	pz->cap = begin;
	/*struct contact*data = (struct contact*)malloc()    ��������д����Ϊ����д�Ļ������data�����Լ��ִ�����һ��������ԭ���ṹ���е�data*/
	pz->data = (struct people*)malloc(begin*sizeof(struct people));
}
//��̬�汾������
int checkcap(struct contact* pz) //�����÷���int���ͣ�����������������ʹ�ã���Ϊ�����и�����ֵ����������������һЩ�ж�
{
	if (pz->sz == pz->cap)
	{
		/*pz->data = (struct people*)realloc(pz->data, (begin + 2)*sizeof(struct people));*/ //�������ֱ������д����Ӧ���Ǵ���һ��������Ȼ��ͨ�������������data��
	     struct people* str = (struct people*)realloc(pz->data, (begin + 2)*sizeof(struct people));
		if (pz->data == NULL)
		{
			printf("����ʧ��\n");
			return 0;
		}
		else
		{
			pz->data = str;
			(pz->cap)+= 2;
			printf("���ݳɹ�\n");
			return 1;
		}
	}
	return 1;
}

//��̬�汾
void Addcontact(struct contact* pz)
{
	if (checkcap(pz) == 0)               //�����checkcap�е�ص�������ζ������Ϊǰ�治��Ҫ�Ǹ�����������ԭ���Ǻ����
	{
		printf("����ʧ��,�ռ䲻��ʹ��\n");
	}
	else
	{
				printf("����������\n");                   //�������Ҫ�Լ��ڴ���һ��char name�������������������֣�Ȼ���ӡ������ֱ������д�����ˣ�����ԭ���Ǻ������Ӧ�ú�printf
                                                          //����scanf��Ҳ�п������ڴ��й�
				scanf("%s", pz->data[pz->sz].name);       //��data�Ŀռ䴴���ã���ʵ�Ϳ��԰������������ˣ��������뾲̬��д��һģһ��
				printf("����������\n");
				scanf("%d",&(pz->data[pz->sz].age));  
				printf("������绰\n");
				scanf("%s", pz->data[pz->sz].tele);
				printf("�������ַ\n");
				scanf("%s", pz->data[pz->sz].address);
				pz->sz++;
				printf("���ӳɹ�\n");
	}
}
//��̬�汾
//void Addcontact(struct contact* pz)
//{
//	if (pz->sz ==max)
//	{
//		printf("ͨѶ¼����");
//	}
//	else
//	{
//		printf("����������\n");
//		scanf("%s", pz->data[pz->sz].name);  //ע�����pz->sz�����٣���Ϊdata�Ǹ����飬Ҫȷ�����ĸ��±긳ֵ   ����������飬������������Ԫ�صĵ�ַ�ˣ��ʲ���Ҫȡ��ַ����
//		printf("����������\n");
//		scanf("%d",&(pz->data[pz->sz].age));   //�������ʲô��ַ������Ҫȡ��ַ����
//		printf("������绰\n");
//		scanf("%s", pz->data[pz->sz].tele);
//		printf("�������ַ\n");
//		scanf("%s", pz->data[pz->sz].address);
//	}
//	(pz->sz)++;
//}

void Showcontact(struct contact* pz)
{   
	printf("%15s%5s%14s%20s\n", "����","����","�绰","��ַ");                               //ע�����ִ�ӡ����
	//printf("%15s%5d%14d%20s", pz->data[pz->sz].name, pz->data[pz->sz].age, pz->data[pz->sz].tele, pz->data[pz->sz].address);
	//pz->sz++;
	int i = 0;
	for (i = 0; i < pz->sz; i++)
	{
		printf("%15s%5d%14s%20s\n", pz->data[i].name, pz->data[i].age, pz->data[i].tele, pz->data[i].address);
	}
	//int i = 0;
	//if (pc->sz == 0)
	//{
	//	printf("ͨѶ¼Ϊ��\n");
	//}
	//else
	//{
	//	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//	for (i = 0; i < pc->sz; i++)
	//	{
	//		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
	//			pc->data[i].name,
	//			pc->data[i].age,
	//			pc->data[i].tele,
	//			pc->data[i].address);
	//	}
	//}
}
int findbyname(struct contact* pz, char name[])
{
	int i = 0;
	for (i = 0; i < pz->sz; )
	{
		if (strcmp(pz->data[i].name, name))
		{
			i++;
		}
		else
		{
			return i;
		}
	}
	return -1;
}

void Searchcontact(struct contact* pz)
{
	char name[20];
	printf("��������Ҫ���ҵ�����\n");
	scanf("%s", name);
	int pos = findbyname(pz, name);
	if (pos != -1)
	{
		printf("�ҵ���\n");
		printf("%15s%5s%14s%20s\n", "����", "����", "�绰", "��ַ");
		printf("%15s%5d%14s%20s\n", pz->data[pos].name, pz->data[pos].age, pz->data[pos].tele, pz->data[pos].address);
	}
	else
	{
		printf("û�ҵ�,����ͨѶ¼����\n");
	}
}

void Delectcontact(struct contact* pz)
{
	char name[20];
	printf("��������Ҫɾ���˵�����\n");
	scanf("%s", name);
	int pos = findbyname(pz, name);
	for (; pos < (pz->sz)-1; pos++)
	{
		pz->data[pos] = pz->data[pos + 1];
	}
	pz->sz--;
	printf("ɾ���ɹ�\n");
	if (pz->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��");
	}
}


void Modifycontact(struct contact* pz)
{
	char name[20];
	printf("��������Ҫ�޸��˵�����\n");
	scanf("%s", name);
	int pos = findbyname(pz, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�������ͨѶ¼��");
	}
	else
	{
		printf("�������޸��˵�����\n");
		scanf("%s", pz->data[pos].name);  
		printf("�������޸��˵�����\n");
		scanf("%d", &(pz->data[pos].age));  
		printf("�������޸��˵ĵ绰\n");
		scanf("%s", pz->data[pos].tele);
		printf("�������޸��˵ĵ�ַ\n");
		scanf("%s", pz->data[pos].address);
		printf("�޸ĳɹ�\n");
	}
}


void DestroyContact(struct contact* pz)
{
	free(pz->data);
	pz->data = NULL;
	pz->cap= 0;
	pz->sz = 0;
}