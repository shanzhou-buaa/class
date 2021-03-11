#include "contact.h"


void menu()
{
	printf("0.exit\n1.add\n2.del\n3.search\n4.modify\n5.show\n\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW
};

int main()
{
	int input = 0;
	struct Contact con;
	initContact(&con);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("exit success\n\n");
			break;
		case ADD:
			addContact(&con);
			break;
		case DEL:
			delContact(&con);
			break;
		case SEARCH:
			searchContact(&con);
			break;
		case SHOW:
			showContact(&con);
			break;
		case MODIFY:
			modifyContact(&con);
			break;
		default:
			printf("input error\n\n");
			break;
		}
	} while (input);
	return 0;
}