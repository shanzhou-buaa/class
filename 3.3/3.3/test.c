#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


struct s
{
	char name[20];
	int age;
	double score;
};
//int main()
//{
//	struct s s1 = { "zhangsan", 18, 60.1 };
//	FILE* pf = fopen("text.txt", "wb");
//	if (pf == NULL)
//		return 0;
//	fwrite(&s1, sizeof(struct s), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	//struct s s1 = { "zhangsan", 18, 60.1 };
//	struct s tmp = { 0 };
//	FILE* pf = fopen("text.txt", "rb");
//	if (pf == NULL)
//		return 0;
//	fread(&tmp, sizeof(struct s), 1, pf);
//	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	FILE* pf = fopen("text.txt", "r");
	
	fseek(pf, 2, SEEK_CUR);
	printf("%c\n", fgetc(pf));

	fseek(pf, -2, SEEK_END);
	printf("%c\n", fgetc(pf));

	fseek(pf, 0, SEEK_SET);
	printf("%c\n", fgetc(pf));

	fclose(pf);
	pf = NULL;
	return 0;
}