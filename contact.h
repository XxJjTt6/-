#define _CRT_SECURE_NO_WARNINGS 1
#define max 1000          
#define begin 3 
#include<stdio.h>
#include<string.h>
struct people
{
	char name[20];                  //��ʵ������������Ҳ��define����ĳ�����д����Ϊ���������Ժ���޸�
	int age;
	char tele[14];   //ע�����һ��Ҫд��char���͵����飬����д��int���͵����飬��˵���Ķ���������׵�ַ��ȥ��������ʱchar��%s���գ�ֻҪ֪���׵�ַ�Ϳ��Խ������ȫ��ӡ��������int
	                 //���������
	char address[15];
};
//��̬�İ汾
//struct contact
//{
//	struct people data[max];
//	int sz;
//};
//��̬�İ汾
struct contact
{
	struct people* data;           // ���һ��Ҫд��ָ�����ʽ����Ϊ��ʱ����malloc����realloc�����ռ��ʱ�򷵻صľ���һ����ַ������Ҫд��ָ�룬��������һ�󴮿ռ��ֻ�践��
	                               //�׵�ַ���Ϳ����ҵ�����һ�����ϵ�Ŀռ䣬���ϣ�һ��Ҫд��ָ�룬�����㲻д��ָ�����ʽҲû�취д�ɶ�̬�ġ�
	int sz;
	int cap;
};
void init(struct contact* pz);
void Addcontact(struct contact* pz);
void Showcontact(struct contact* pz);
void Searchcontact(struct contact* pz);
void Delectcontact(struct contact* pz);
void Modifycontact(struct contact* pz);
void DestroyContact(struct Contact* pz)
//void checkcap(struct contact* pz);   //�����Ҫ���������������Ϊ������������ǻص�����������ԭ����Ҳ���Ǻ����