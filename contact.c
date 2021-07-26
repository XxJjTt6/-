#include"contact.h"
//静态版本
//void init(struct contact* pz)
//{
//	pz->sz = 0;
//	memset(pz->data, 0, sizeof(pz->data));       //memset，这样高效，且快速
//}
//动态版本
void init(struct contact* pz)
{
	pz->sz = 0;
	pz->cap = begin;
	/*struct contact*data = (struct contact*)malloc()    不能这样写，因为这样写的话，这个data是你自己又创建了一个，不是原本结构体中的data*/
	pz->data = (struct people*)malloc(begin*sizeof(struct people));
}
//动态版本的增容
int checkcap(struct contact* pz) //这儿最好返回int类型，方面下面其他函数使用，因为这样有个返回值，可以利用他来做一些判断
{
	if (pz->sz == pz->cap)
	{
		/*pz->data = (struct people*)realloc(pz->data, (begin + 2)*sizeof(struct people));*/ //这儿不能直接这样写，而应该是创建一个变量，然后通过这个变量传给data；
	     struct people* str = (struct people*)realloc(pz->data, (begin + 2)*sizeof(struct people));
		if (pz->data == NULL)
		{
			printf("扩容失败\n");
			return 0;
		}
		else
		{
			pz->data = str;
			(pz->cap)+= 2;
			printf("扩容成功\n");
			return 1;
		}
	}
	return 1;
}

//动态版本
void Addcontact(struct contact* pz)
{
	if (checkcap(pz) == 0)               //这儿的checkcap有点回调函数的味道，因为前面不需要那个声明，具体原因不是很清楚
	{
		printf("扩容失败,空间不够使用\n");
	}
	else
	{
				printf("请输入名字\n");                   //这儿不需要自己在创建一个char name【】的数组来接收名字，然后打印出来，直接这样写就行了，具体原因不是很清楚，应该和printf
                                                          //或者scanf，也有可能与内存有关
				scanf("%s", pz->data[pz->sz].name);       //当data的空间创建好，其实就可以把他看出数组了，因此这儿与静态的写法一模一样
				printf("请输入年龄\n");
				scanf("%d",&(pz->data[pz->sz].age));  
				printf("请输入电话\n");
				scanf("%s", pz->data[pz->sz].tele);
				printf("请输入地址\n");
				scanf("%s", pz->data[pz->sz].address);
				pz->sz++;
				printf("增加成功\n");
	}
}
//静态版本
//void Addcontact(struct contact* pz)
//{
//	if (pz->sz ==max)
//	{
//		printf("通讯录已满");
//	}
//	else
//	{
//		printf("请输入名字\n");
//		scanf("%s", pz->data[pz->sz].name);  //注意这儿pz->sz不能少，因为data是个数组，要确定给哪个下标赋值   且这儿是数组，数组命就是首元素的地址了，故不需要取地址符号
//		printf("请输入年龄\n");
//		scanf("%d",&(pz->data[pz->sz].age));   //这儿不是什么地址，故需要取地址符号
//		printf("请输入电话\n");
//		scanf("%s", pz->data[pz->sz].tele);
//		printf("请输入地址\n");
//		scanf("%s", pz->data[pz->sz].address);
//	}
//	(pz->sz)++;
//}

void Showcontact(struct contact* pz)
{   
	printf("%15s%5s%14s%20s\n", "名字","年龄","电话","地址");                               //注意这种打印方法
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
	//	printf("通讯录为空\n");
	//}
	//else
	//{
	//	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
	printf("请输入你要查找的姓名\n");
	scanf("%s", name);
	int pos = findbyname(pz, name);
	if (pos != -1)
	{
		printf("找到了\n");
		printf("%15s%5s%14s%20s\n", "名字", "年龄", "电话", "地址");
		printf("%15s%5d%14s%20s\n", pz->data[pos].name, pz->data[pos].age, pz->data[pos].tele, pz->data[pos].address);
	}
	else
	{
		printf("没找到,不在通讯录当中\n");
	}
}

void Delectcontact(struct contact* pz)
{
	char name[20];
	printf("请输入你要删除人的姓名\n");
	scanf("%s", name);
	int pos = findbyname(pz, name);
	for (; pos < (pz->sz)-1; pos++)
	{
		pz->data[pos] = pz->data[pos + 1];
	}
	pz->sz--;
	printf("删除成功\n");
	if (pz->sz == 0)
	{
		printf("通讯录为空，无法删除");
	}
}


void Modifycontact(struct contact* pz)
{
	char name[20];
	printf("请输入你要修改人的姓名\n");
	scanf("%s", name);
	int pos = findbyname(pz, name);
	if (pos == -1)
	{
		printf("要修改的人不存在与通讯录中");
	}
	else
	{
		printf("请输入修改人的名字\n");
		scanf("%s", pz->data[pos].name);  
		printf("请输入修改人的年龄\n");
		scanf("%d", &(pz->data[pos].age));  
		printf("请输入修改人的电话\n");
		scanf("%s", pz->data[pos].tele);
		printf("请输入修改人的地址\n");
		scanf("%s", pz->data[pos].address);
		printf("修改成功\n");
	}
}


void DestroyContact(struct contact* pz)
{
	free(pz->data);
	pz->data = NULL;
	pz->cap= 0;
	pz->sz = 0;
}