#include "MealCard.h"


int main()
{
	Card* head = NULL;  //����ͷ
	Card* cur_user = NULL;   //��ǰ�û�����ڵ�
	LoadCard(&head);
	while (1)
	{
		PrintMenu();
		int option = 0;
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			Register(&head);
			break;
		case 2:
			cur_user = Login(head);
			break;
		case 3:
			CardInfoEnter(cur_user);
			break;
		case 4 :
			CardRecharge(cur_user);
			break;
		case 5:
			CardConsume(cur_user);
			break;
		case 6:
			CardIDFind(head, cur_user);
			break;
		case 7:
			PrintCard(head, cur_user);
			break;
		case 8:
			CardErase(&head,cur_user);
			break;
		case 9:
			CardReportLost(cur_user);
			break;
		case 10 :
			CardRestoreLost(cur_user);
			break;
		case 11 :
			system("cls"); //����
			printf("Bye Bye!\n");
			SaveCard(head);
			exit(0);
			break;
		default:
			printf("����������");
			system("pause");//��ͣ����
			system("cls");//��տ���̨
			break;
		}
	}
	return 0;
}