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
		printf("��ѡ��\n");
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
			printf("ʩ����\n");
			break;
		case EXIT:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
