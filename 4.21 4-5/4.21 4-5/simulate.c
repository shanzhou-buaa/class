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
	int front=1,rear=0;//队头、队尾(队头是剩余人数最前面那一个的序号，队尾是最后面那一个的序号)
	int n,i,j,k,sum=0,remain=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num[i]);//输入每一周期来的人数
	}
	for(i=1;i<=n;i++){
		sum+=num[i];//求得总数，存在sum里
	}
	for(j=i=1,k=num[j];i<=sum;i++){
		p[i].number=i;//标记每个人的序号
		if(i<=k){
			p[i].time=j;//标记每个人来时候的周期
		}
		else{
			k+=num[j+1];
			j++;
			p[i].time=j;
		}
	}
	for(i=1;i<=n;i++){//这里的i保存的是银行进行的周期数
		remain+=num[i];//保存剩余人数
		rear+=num[i];
		if(remain<=20){//开始分情况讨论
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
	while(remain!=0){//人已经不来了，但还有剩余人数，银行继续进行周期工作
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
	for(i=1;i<sum;i++){//输出
		printf("%d : %d\n",p[i].number,wait[i]);
	}
	printf("%d : %d",p[i].number,wait[i]);
 	return 0;
}
