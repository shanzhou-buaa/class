#include "SeqList.h"

//��ʼ��
void SeqListInit(sl* p)
{
	assert(p);

	p->a = NULL;
	p->size = 0;
	p->capacity = 0;
}

//����
void SeqListDestroy(sl* p)
{
	assert(p != NULL);

	p->a = NULL;
	p->size = 0;
	p->capacity = 0;
}

//��ӡ
void SeqListPrint(sl* p)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->size; i++)
		printf("%d ", p->a[i]);
	printf("\n");
}

//������Ա��Ƿ�����
void CheckCapacity(sl* p)
{
	if (p->size == p->capacity)
	{
		int newcapacity = (p->capacity == 0) ? 4 : (p->capacity * 2);
		data* newA = (data*)realloc(p->a, sizeof(data)*newcapacity);
		if (newA == NULL)
		{
			printf("newcapacity fail\n");
			exit(-1);
		}
		p->a = newA;
		p->capacity = newcapacity;
	}
}

//�м��������
void SeqListInsert(sl* p, int pos, data x)
{
	assert(p);
	assert(pos >= 0 && pos <= p->size);
	CheckCapacity(p);

	int i = p->size;
	for (; i > pos; i--)
		p->a[i] = p->a[i - 1];
	p->a[i] = x;
	p->size++;
}

//�м�ɾ������
void SeqListErase(sl* p, int pos)
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	CheckCapacity(p);

	int i = pos;
	for (; i < p->size - 1; i++)
		p->a[i] = p->a[i + 1];
	p->size--;
}

//β��
void SeqListPushBack(sl* p, data x)
{
	/*assert(p);
	
	CheckCapacity(p);

	p->a[p->size] = x;
	p->size++;*/
	
	SeqListInsert(p, p->size, x);
}


//ͷ��
void SeqListPushFront(sl* p, data x)
{
	/*assert(p);
	
	CheckCapacity(p);

	int end = p->size;
	for (; end > 0; end--)
	{
		p->a[end] = p->a[end - 1];
	}
	p->a[0] = x;
	p->size++;*/

	SeqListInsert(p, 0, x);
}

//βɾ
void SeqListPopBack(sl* p)
{
	/*assert(p);
	assert(p->size > 0);

	CheckCapacity(p);

	p->size--;*/

	SeqListErase(p, p->size - 1);
}

//ͷɾ
void SeqListPopFront(sl* p)
{
	/*assert(p);
	assert(p->size > 0);
	int i = 0;
	for (i = 0; i < p->size - 1; i++)
		p->a[i] = p->a[i + 1];
	p->size--;*/

	SeqListErase(p, 0);
}

//����
int SeqListFind(sl* p, data x)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->a[i] == x)
			return i;
	}
	return -1;
}

//�޸�
void SeqListModify(sl* p, int pos, data x)
{
	assert(p);
	assert(pos >= 0 && pos < p->size);

	p->a[pos] = x;
}