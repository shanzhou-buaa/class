#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int wait[10024],num[1000];

struct people
{
	int number;
	int time;
}p[10024];

int main()
{
	int front=1,rear=0;//��ͷ����β(��ͷ��ʣ��������ǰ����һ������ţ���β���������һ�������)
	int n,i,j,k,sum=0,remain=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num[i]);//����ÿһ������������
	}
	for(i=1;i<=n;i++){
		sum+=num[i];//�������������sum��
	}
	for(j=i=1,k=num[j];i<=sum;i++){
		p[i].number=i;//���ÿ���˵����
		if(i<=k){
			p[i].time=j;//���ÿ������ʱ�������
		}
		else{
			k+=num[j+1];
			j++;
			p[i].time=j;
		}
	}
	for(i=1;i<=n;i++){//�����i����������н��е�������
		remain+=num[i];//����ʣ������
		rear+=num[i];
		if(remain<=20){//��ʼ���������
			if(remain<=3){
				remain=0;
				for(j=front;j<=rear;j++){
					wait[j]=i-p[j].time;
				}
				front=rear+1;
			}
			else{
				remain-=3;
				for(j=front;j<=front+2;j++){
					wait[j]=i-p[j].time;
				}
				front+=3;
			}
		}
		if(remain>20&&remain<=27){
			remain-=4;
			for(j=front;j<=front+3;j++){
				wait[j]=i-p[j].time;
			}
			front+=4;
		}
		if(remain>27){
			remain-=5;
			for(j=front;j<=front+4;j++){
				wait[j]=i-p[j].time;
			}
			front+=5;
		}
	}
	while(remain!=0){//���Ѿ������ˣ�������ʣ�����������м����������ڹ���
		if(remain>34){
			remain-=5;
			for(j=front;j<=front+4;j++){
				wait[j]=i-p[j].time;
			}
			i++;
			front+=5;
		}
		if(remain>27&&remain<=34){
			remain-=4;
			for(j=front;j<=front+3;j++){
				wait[j]=i-p[j].time;
			}
			i++;
			front+=4;
		}
		if(remain<=27){
			if(remain<=3){
				remain=0;
				for(j=front;j<=rear;j++){
					wait[j]=i-p[j].time;
				}
			}
			else{
				remain-=3;
				for(j=front;j<=front+2;j++){
					wait[j]=i-p[j].time;
				}
				i++;
				front+=3;
			}
		}
	}
	for(i=1;i<sum;i++){//���
		printf("%d : %d\n",p[i].number,wait[i]);
	}
	printf("%d : %d",p[i].number,wait[i]);
 	return 0;
}
