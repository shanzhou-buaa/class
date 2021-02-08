#include "contact.h"

void menu()
{
	printf("0.exit\n");
	printf("1.add\n");
	printf("2.delete\n");
	printf("3.search\n");
	printf("4.modify\n");
	printf("5.show\n");
	printf("6.sort\n");
}

int main()
{
	struct Contact con;
	int input = 0;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			printf("施工中\n");
			break;
		case EXIT:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
