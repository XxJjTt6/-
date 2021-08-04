#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListinit(SLT * ps1)
{
	assert(ps1);                            //写这些断言的好处是万一错了他会报错，这儿还调试，下面的所有断言都是这个目的
	ps1->size = 0;
	ps1->capcaity =4;
	ps1->a = (SQDataType *)malloc(sizeof(SQDataType)*ps1->capcaity);     // 这儿应该用一个临时变量来过渡一下，万一创建时失败了
	if (ps1->a == NULL)
	{
		printf("创建失败\n");
	}
}

void SeqListDestory(SLT *ps1)
{
	assert(ps1);
	if (ps1->a != NULL)
	{
		free(ps1->a);
		ps1->a = NULL;
	}
}

void SeqListCheckCapcaity(SLT* ps1)            //因为尾插，头插都需要扩容，所以把他抽出来写成一个函数，这个具体的细节没必要再.h文件中声明
{
	if (ps1->size == ps1->capcaity)
	{
		ps1->capcaity *= 2;
		ps1->a = (SQDataType *)realloc(ps1->a, sizeof(SQDataType)*ps1->capcaity);  // 这儿也是同样的问题，应该用一个临时变量来过渡一下，万一创建失败了
		if (ps1->a == NULL)
		{
			printf("开辟失败\n");
		}
	}
}
void SeqListPushBack(SLT* ps1,SQDataType x)
{
	assert(ps1);
	if (ps1->size == ps1->capcaity)
	{
		SeqListCheckCapcaity(ps1);
		printf("扩容成功\n");
		ps1->a[ps1->size] = x;
		ps1->size++;
	}
	else
	{
		ps1->a[ps1->size] = x;
		ps1->size++;
	}
}

void SeqListPushFront(SLT* ps1, SQDataType x)
{
	assert(ps1);
	int end = ps1->size-1;
	if (ps1->size == ps1->capcaity)
	{
		SeqListCheckCapcaity(ps1);
		printf("扩容成功\n");
		for (; end >= 0; end--)
		{
			ps1->a[end + 1] = ps1->a[end];
		}
		ps1->a[0] = x;
		ps1->size++;
	}
	else
	{
		for (; end >= 0; end--)
		{
			ps1->a[end + 1] = ps1->a[end];
		}
		ps1->a[0] = x;
		ps1->size++;
	}
}


void SeqListPopBack(SLT* ps1)
{
	assert(ps1);
	/*ps1->a[ps1->size - 1] = 0; */ //这一步反而是画蛇添足，因为万一我a数组的类型不是int型的或者我最后一个数正好就是0了，所以直接size--就行了
	ps1->size--;
}


void SeqListPopFront(SLT* ps1)
{
	int i = 0;
	for (i = 1; i < ps1->size; i++)
	{
		ps1->a[i - 1] = ps1->a[i];
	}
	ps1->size--;
}


//void SeqListInsert(SLT* ps1, int pos, SQDataType x)     //这儿的pos最好写成size_t的类型，因为库里面就是这个类型
//{
//	assert(ps1&&pos <= ps1->size - 1);
//	int end=ps1->size-1;
//	if (ps1->size == ps1->capcaity)              //其实这儿存在代码的重合，像下面的代码就没有这个问题，我的上下文代码中都犯了这个相同的问题
//	{
//		SeqListCheckCapcaity(ps1);
//		printf("扩容成功\n");
//		for (; end >= pos; end--)
//		{
//			ps1->a[end + 1] = ps1->a[end];
//		}
//		ps1->a[pos] = x;
//		ps1->size++;
//	}
//	else
//	{
//		for (; end >= pos; end--)
//		{
//			ps1->a[end + 1] = ps1->a[end];
//		}
//		ps1->a[pos] = x;
//		ps1->size++;
//	}
//}

void SeqListInsert(SLT* psl, size_t pos, SQDataType x)     //size_t的写法，这儿要注意当end为-1被当成无符号数会是一个很大的数，要想办法解决这么一个问题
{
	assert(psl);
	assert(pos <= psl->size && pos >= 0);
	SeqListCheckCapcaity(psl);

	/*int end = psl->size - 1;
	while (end >= (int)pos)
	{
	psl->a[end + 1] = psl->a[end];
	--end;
	}*/

	size_t end = psl->size;                        // 换种写法，巧妙的避开了这个问题
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}

	psl->a[pos] = x;
	psl->size++;
}

//void SeqListErase(SLT* ps1, int pos)          //这儿也是，最好写成size_t的类型，因为库里面就是这个类型
//{
//	assert(ps1&&pos<=ps1->size-1);
//	for (; pos <ps1->size-1; pos++)   //-2是为了防止越界,测试之后发现-2是不行的，考虑极端情况，当要删除的是最后一个数据时，这时pos+1不会进入for循环，而且进去了也会存在数组越界的
//		                              //的问题，因此这里直接写pos<ps1->size-1，因为这样的话，如果pos为最后一个，进不去for循环，不会有越界，而且后面的ps1->size--正好解决了这个问
//                                      //题，打印的时候不会打印出最后一个
//	{
//		ps1->a[pos] = ps1->a[pos + 1];
//	}
//	ps1->size--;
//}


void SeqListErase(SLT* psl, size_t pos)    // size_t的写法     
{
	assert(psl);
	assert(pos < psl->size);

	size_t begin = pos + 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}
	psl->size--;
}                                           //当写到这儿时，基本大部分顺序表的函数都写完了，这时候再去写菜单，会好写很多



void SeqListPrintf(SLT* ps1)
{
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		printf("%d", ps1->a[i]);
	}
}
