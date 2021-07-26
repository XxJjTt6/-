#define _CRT_SECURE_NO_WARNINGS 1
#define max 1000          
#define begin 3 
#include<stdio.h>
#include<string.h>
struct people
{
	char name[20];                  //其实这儿的数字最好也用define定义的常量来写，因为这样方便以后的修改
	int age;
	char tele[14];   //注意这儿一定要写成char类型的数组，不能写成int类型的数组，虽说传的都是数组的首地址过去，但接收时char用%s接收，只要知道首地址就可以将后面的全打印出来，而int
	                 //做不到这点
	char address[15];
};
//静态的版本
//struct contact
//{
//	struct people data[max];
//	int sz;
//};
//动态的版本
struct contact
{
	struct people* data;           // 这儿一定要写成指针的形式，因为到时候用malloc或者realloc创建空间的时候返回的就是一个地址，所以要写成指针，而且扩容一大串空间后，只需返回
	                               //首地址，就可以找到后面一大块联系的空间，综上，一定要写成指针，而且你不写成指针的形式也没办法写成动态的。
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
//void checkcap(struct contact* pz);   //这儿不要声明这个函数，因为这个函数后面是回调函数，具体原因我也不是很清楚