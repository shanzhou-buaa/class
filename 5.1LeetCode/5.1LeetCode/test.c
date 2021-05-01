#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
	int* a;
	int front;
	int rear;
	int capacity;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->a = (int*)malloc(sizeof(int)* (k + 1));//��k�����ݿ�k+1���ռ�

	//ͷβ��ͬʱ����Ϊ�գ�ͷ==β+1ʱ ��
	pcq->front = 0;
	pcq->rear = 0;
	pcq->capacity = k;

	return pcq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))//��
		return false;

	else
	{
		obj->a[obj->rear] = value;
		obj->rear++;
		obj->rear %= (obj->capacity + 1);
		//printf("%d\n", obj->rear);
		return true;
	}
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))//��
		return false;

	else
	{
		obj->front++;
		obj->front %= (1 + obj->capacity);
		return true;
	}
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
		return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
	{
		if (obj->rear == 0)
			return obj->a[obj->capacity];

		return obj->a[obj->rear - 1];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	//ͷβ���Ϊ�գ�������
	return obj->rear == obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	//��ͷ = β + 1�� Ϊ����������
	int rearNext = obj->rear + 1;
	if (rearNext == obj->capacity + 1)
		rearNext = 0;
	return rearNext == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->a);
	obj->a = NULL;
	free(obj);
	obj = NULL;
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/

int main()
{

	return 0;
}