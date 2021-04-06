#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tagPIM
{
	unsigned char ucPim1;
	unsigned char ucData0 : 1;
	unsigned char ucData1 : 2;
	unsigned char ucData2 : 3;
}*pstPimData;

//ucData0 00000001
//ucData1 00000010
//ucData2 00000011


int main()
{
	unsigned char puc[4];
	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;//0000 0001
	pstPimData->ucData0 = 3;//1
	pstPimData->ucData0 = 4;//00
	pstPimData->ucData0 = 5;//101
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}