//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define M 618
//#define INF 0x3f3f3f3f
//struct station{				//地铁站序号结构体 
//	char stationName[30];	//站名 
//	int IsChange;			//能否换乘 
//};
//struct vertex{				//地铁图结构体 
//	int weight;				//权重 
//	int lineID;				//路线序号 
//};
//struct station StationID_list[M];	//地铁站序号数组 
//struct vertex map[M][M];			//地铁图 
//int lineID,StationNum,lineNum,IsChange,VerNum;	//路线序号，一条路线中地铁站个数，路线个数，是否换乘，总地铁站个数 
//int prev[M],dist[M],path[M],top,pathID[M][M];	//跟踪数组，最短路径数值数组，dijkstra最短路径编号数组，栈顶，Floyd最短路径编号数组
//char StationBegin[30],StationEnd[30];	//起点站，终点站 
//void DrawSubwayMap(FILE *fp);		//建图 
//int SearchMap(char *s);				//找站名是否出现过 
//void floyd(int v1,int v2);			//floyd算法 
//void PrintPath(int v1,int v2);		//打印路径 
//int main()
//{	
//	int i,j,v1,v2,t;
//	FILE *fp = fopen("bgstations.txt","r");
//	scanf("%s %s",StationBegin,StationEnd);
//	for(i=0;i<M;i++)			//初始化图 
//		for(j=0;j<M;j++)
//		{	
//			map[i][j].weight=map[j][i].weight=INF;	//权重无穷大 
//			map[i][j].lineID=map[j][i].lineID=0;	//编号为0 
//		}
//	DrawSubwayMap(fp);		//建图 
//	v1=SearchMap(StationBegin);	//找到起点站编号 
//	v2=SearchMap(StationEnd);	//找到终点站编号  
//	floyd(v1,v2);		//找最短路 
//	for(t=v2;t!=v1;t=pathID[v1][t])	//路径追溯 
//	{
//		path[top]=t;
//		top++;
//	}
//	PrintPath(v1,v2);	//打印编号 
//	return 0;
//}
//void DrawSubwayMap(FILE *fp)
//{
//	int i,j,ContainID,EdgeLast;//两个变量，存在的地铁站的编号，边的起点 
//	char stationName[30];		//站名 
//	fscanf(fp,"%d",&lineNum);	
//	for(i=0;i<lineNum;i++)
//	{
//		fscanf(fp,"%d %d",&lineID,&StationNum);
//		EdgeLast=-1;	//每一条路线一开始都是 -1 
//		for(j=0;j<StationNum;j++)
//		{
//			fscanf(fp,"%s %d",stationName,&IsChange);
//			ContainID=SearchMap(stationName);	//看看有没有 
//			if(ContainID == -1)		//没有 
//			{
//				strcpy(StationID_list[VerNum].stationName,stationName);	//存储 
//				StationID_list[VerNum].IsChange=IsChange;				//存储 
//				if(EdgeLast != -1)		//如果有边的起点 
//				{
//					map[EdgeLast][VerNum].lineID=map[VerNum][EdgeLast].lineID=lineID;	//存储 
//					map[EdgeLast][VerNum].weight=map[VerNum][EdgeLast].weight=1;		//存储 
//				}
//				EdgeLast=VerNum;	//终点变起点 
//				VerNum++;			//总数 +1 
//			}
//			else
//			{
//				if(EdgeLast != -1)	//如果有边的起点 
//				{
//					map[EdgeLast][ContainID].lineID=map[ContainID][EdgeLast].lineID=lineID;//存储 
//					map[EdgeLast][ContainID].weight=map[ContainID][EdgeLast].weight=1;	//存储 
//				}
//				EdgeLast = ContainID;	//终点变起点
//			}
//		}
//	}
//}
//int SearchMap(char *s)
//{
//	int i;
//	for(i=0;i<VerNum;i++)
//		if(strcmp(s,StationID_list[i].stationName)==0)
//			return i;	//返回序号 
//	return -1;
//}
//void floyd(int v1,int v2)
//{
//	int i,j,k;
//	for(i=0;i<VerNum;i++)
//		for(j=0;j<VerNum;j++)
//			if(i!=j && map[i][j].weight<INF)
//				pathID[i][j]=i;		//初始化 
//	for(k=0;k<VerNum;k++)
//		for(i=0;i<VerNum;i++)
//			for(j=0;j<VerNum;j++)
//				if(map[i][j].weight>map[i][k].weight+map[k][j].weight)	//三角形原则更新路径 
//				{
//					map[i][j].weight=map[i][k].weight+map[k][j].weight;
//					pathID[i][j]=pathID[k][j];	//记录编号 
//				}
//}
//void PrintPath(int v1,int v2)
//{		
//	int i,EdgeLast=v1,pathLen=1,u=path[top-1];//i是变量，边的起点，长度，边的终点 
//	int lineId=map[EdgeLast][u].lineID;	//开始路线编号 
//	printf("%s-%d",StationID_list[v1].stationName,lineId); //打印起点站和起点站的路线 
//	EdgeLast = u;
//	for(i=top-2;i>=0;i--)	//利用栈倒过来寻找 
//	{
//		u=path[i];	//更新终点 
//		if(lineId != map[EdgeLast][u].lineID)	//换乘
//		{
//			lineId = map[EdgeLast][u].lineID;
//			printf("(%d)-%s-%d",pathLen,StationID_list[EdgeLast].stationName,lineId);
//			pathLen=0;
//		}
//		pathLen++;		//长度 +1 
//		EdgeLast = u;	//更新起点
//	}
//	printf("(%d)-%s",pathLen,StationID_list[v2].stationName);//打印终点站
//}