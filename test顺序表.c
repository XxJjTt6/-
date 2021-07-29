#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void menu()
{
	printf("\n**************************************\n");
	printf("****1.β������          2.ͷ������****\n");
	printf("****3.β��ɾ��          4.ͷ��ɾ��****\n");
	printf("****5.ָ��λ�ò���  6.ָ��λ��ɾ��****\n");
	printf("****7.��ӡ              0.�˳�    ****\n");
}

void SeqListTest1(SLT *ps1)            //�����ֺ����ܶ����Ŀ������Ȳ�Ҫ����д�˵�����Ϊ�����д�˵��Ļ��������㲻֪����ôд������ʲô��������ɢ�ң���������Ҫ�������ֵĻ��ܲ�
                                       //������ԣ����д������Ŀʱ�������д�ò��ԵĲ��֣�дһ���־͵���һ���֣����������׷����Լ��Ķ����ˣ�֮ǰд�������ʱ��ͷ����������
									   //���Ե�ʱд�˵���ʱ���һ�ٶٵģ����Ҿ͹�д���˵�ϸ���϶������˴���.
{
	SeqListinit(ps1);
	SeqListPushBack(ps1,1);
	SeqListPushBack(ps1,2);
	SeqListPushBack(ps1, 3);
	SeqListPushBack(ps1, 4);
	SeqListPushBack(ps1, 5);
	SeqListPushFront(ps1, 0);
	SeqListPushFront(ps1, -1);
	SeqListPopBack(ps1);
	SeqListPopFront(ps1);
	SeqListInsert(ps1, 0, -1);    // ��pos=0���൱��ͷ�壬��pos=size-1ʱ���൱��β�壬��˿��Ը���
	SeqListErase(ps1,5);          //��pos=0���൱��ͷɾ����pos=size-1ʱ���൱��βɾ����˿��Ը���
	SeqListPrintf(ps1);
	SeqListDestory(ps1);
}

int main()
{
	SLT ps1;
	/*SeqListTest1(&ps1);  */     //�����������к�����Ҫд�˵�ʱ����ʱ�Ͳ���Ҫ�ⲿ�ֲ��Ե������ˣ���Ϊ���Ѿ����Բ���֤��������Ҫ�õú����ˣ���ע�͵�������������˵����ѡ��
	SeqListinit(&ps1);
	int input = 0;
	/*int a = 0;*/
	int pos = 0;
	do
	{
		int a = 0;
		menu();
		printf("��ѡ��->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			/*int a = 0;*/
			printf("������Ҫ�������\n");
			scanf("%d", &a);
			SeqListPushBack(&ps1,a);
			break;
		case 2:
			printf("������Ҫ�������\n");
			scanf("%d", &a);
			SeqListPushFront(&ps1,a);
			break;
		case 3:
			SeqListPopBack(&ps1);
			break;
		case 4:
			SeqListPopFront(&ps1);
			break;
		case 5:
			printf("������Ҫ�����λ��,�Լ�Ҫ���������\n");
			scanf("%d %d", &pos, &a);
			SeqListInsert(&ps1, pos, a);
			break;
		case 6:
			printf("������Ҫɾ����λ��\n");
			scanf("%d", &pos);
			SeqListErase(&ps1, pos);
			break;
		case 7:
			SeqListPrintf(&ps1);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}