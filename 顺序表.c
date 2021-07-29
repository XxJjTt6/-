#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListinit(SLT * ps1)
{
	assert(ps1);                            //д��Щ���Եĺô�����һ�������ᱨ����������ԣ���������ж��Զ������Ŀ��
	ps1->size = 0;
	ps1->capcaity =4;
	ps1->a = (SQDataType *)malloc(sizeof(SQDataType)*ps1->capcaity);
	if (ps1->a == NULL)
	{
		printf("����ʧ��\n");
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

void SeqListCheckCapcaity(SLT* ps1)            //��Ϊβ�壬ͷ�嶼��Ҫ���ݣ����԰��������д��һ����������������ϸ��û��Ҫ��.h�ļ�������
{
	if (ps1->size == ps1->capcaity)
	{
		ps1->capcaity *= 2;
		ps1->a = (SQDataType *)realloc(ps1->a, sizeof(SQDataType)*ps1->capcaity);
		if (ps1->a == NULL)
		{
			printf("����ʧ��\n");
		}
	}
}
void SeqListPushBack(SLT* ps1,SQDataType x)
{
	assert(ps1);
	if (ps1->size == ps1->capcaity)
	{
		SeqListCheckCapcaity(ps1);
		printf("���ݳɹ�\n");
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
		printf("���ݳɹ�\n");
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
	/*ps1->a[ps1->size - 1] = 0; */ //��һ�������ǻ������㣬��Ϊ��һ��a��������Ͳ���int�͵Ļ��������һ�������þ���0�ˣ�����ֱ��size--������
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


//void SeqListInsert(SLT* ps1, int pos, SQDataType x)     //�����pos���д��size_t�����ͣ���Ϊ����������������
//{
//	assert(ps1&&pos <= ps1->size - 1);
//	int end=ps1->size-1;
//	if (ps1->size == ps1->capcaity)              //��ʵ������ڴ�����غϣ�������Ĵ����û��������⣬�ҵ������Ĵ����ж����������ͬ������
//	{
//		SeqListCheckCapcaity(ps1);
//		printf("���ݳɹ�\n");
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

void SeqListInsert(SLT* psl, size_t pos, SQDataType x)     //size_t��д�������Ҫע�⵱endΪ-1�������޷���������һ���ܴ������Ҫ��취�����ôһ������
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

	size_t end = psl->size;                        // ����д��������ıܿ����������
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}

	psl->a[pos] = x;
	psl->size++;
}

//void SeqListErase(SLT* ps1, int pos)          //���Ҳ�ǣ����д��size_t�����ͣ���Ϊ����������������
//{
//	assert(ps1&&pos<=ps1->size-1);
//	for (; pos <ps1->size-1; pos++)   //-2��Ϊ�˷�ֹԽ��,����֮����-2�ǲ��еģ����Ǽ����������Ҫɾ���������һ������ʱ����ʱpos+1�������forѭ�������ҽ�ȥ��Ҳ���������Խ���
//		                              //�����⣬�������ֱ��дpos<ps1->size-1����Ϊ�����Ļ������posΪ���һ��������ȥforѭ����������Խ�磬���Һ����ps1->size--���ý���������
//                                      //�⣬��ӡ��ʱ�򲻻��ӡ�����һ��
//	{
//		ps1->a[pos] = ps1->a[pos + 1];
//	}
//	ps1->size--;
//}


void SeqListErase(SLT* psl, size_t pos)    // size_t��д��     
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
}                                           //��д�����ʱ�������󲿷�˳���ĺ�����д���ˣ���ʱ����ȥд�˵������д�ܶ�



void SeqListPrintf(SLT* ps1)
{
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		printf("%d", ps1->a[i]);
	}
}