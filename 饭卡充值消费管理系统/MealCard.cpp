#include "MealCard.h"

//��ӡ�˵�
void PrintMenu()
{
	printf("*********************************\n");
	printf("*\t������ֵ���ѹ���ϵͳ\t*\n");
	printf("*********************************\n");
	printf("*\t��ѡ����\t\t*\n");
	printf("*********************************\n");
	printf("*\t1.ע��\t\t\t*\n");
	printf("*\t2.��¼\t\t\t*\n");
	printf("*\t3.¼�뷹����Ϣ\t\t*\n");
	printf("*\t4.������ֵ\t\t*\n");
	printf("*\t5.��������\t\t*\n");
	printf("*\t6.���ҷ�����Ϣ\t\t*\n");
	printf("*\t7.��ӡ������Ϣ\t\t*\n");
	//printf("*\t8.�޸ķ�����Ϣ\t\t*\n");
	printf("*\t8.ע��������Ϣ\t\t*\n");
	printf("*\t9.��ʧ����\t\t*\n");
	printf("*\t10.�����ʧ����\t\t*\n");
	printf("*\t11.�˳�ϵͳ\t\t*\n");
	printf("*********************************\n");
}

//ע��
void Register(Card**pphead)
{
	//�����¿ռ�
	Card* newCard = BuyNewCard(pphead);
	//ע����Ϣ
	int record = 0;
	printf("������10λ�û���:");
	char username[11] = { 0 };
	scanf("%10s", username);
	//�����������Ϊ�գ���������
	do{
		if (getchar() != '\n')
		{
			//��ջ�����
			while (getchar() != '\n')
			{
				;
			}
			printf("�����û�������10λ������������:");
			scanf("%10s", username);
			record = 1;
		}
		else
		{
			record = 0;
		}
	} while (record);
	if (CardFind(*pphead, username))
	{
		printf("�û����Ѵ��ڣ����¼\n");
	}
	else
	{
		strcpy(newCard->data.user_name, username);

		printf("����������:");
		scanf("%10s", newCard->data.user_password);
		//�����������Ϊ�գ���������
		do {
			if (getchar() != '\n')
			{
				//��ջ�����
				while (getchar() != '\n')
				{
					;
				}
				printf("�������볬��10λ������������:");
				scanf("%10s", newCard->data.user_password);
				record = 1;
			}
			else
			{
				record = 0;
			}
		} while (record);
		//��ʼ�����
		newCard->data.accout = 0;
		//��ʼ��ID
		strcpy(newCard->data.ID, "��δ¼��");
		//��ʼ����ʧ״̬
		newCard->data.lost_status = 1; //δ��ʧ
	}
	system("pause");//��ͣ����
	system("cls");//��տ���̨
}


//��¼
Card* Login(Card* phead)
{
	char User_name[10] = { 0 };
	char User_password[10] = { 0 };
	printf("�������û���:");
	scanf("%10s", &User_name);
	//��¼��ǰ�û�����ڵ�
	Card* cur = CardFind(phead, User_name);
	if (cur == NULL)
	{
		printf("�����ڸ��û�,����ע��\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return NULL;
	}
	else 
	{
		printf("����������:");
		scanf("%10s", &User_password);
		if (strcmp(User_password, cur->data.user_password) == 0)
		{
			printf("��½�ɹ���\n");
		}
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return cur;
	}
}


//�û�������
Card* CardFind(Card* phead, char* username)
{
	Card* cur = phead;
	while (cur)
	{
		if ((strcmp(cur->data.user_name, username)) == 0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}



//���ҷ���
Card* CardIDFind(Card* phead, Card* cur_user)
{
	if (phead == NULL)
	{
		printf("����ע��\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return NULL;
	}
	if (cur_user == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return NULL;
	}
	if (phead == cur_user)
	{
		char id[16] = { 0 };
		printf("������Ҫ���ҵ�ѧ��ID:");
		scanf("%15s", id);
		Card* cur = phead;
		while (cur)
		{
			if ((strcmp(cur->data.ID, id)) == 0)
			{
				printf("����ѧ����:%s\t���ķ������Ϊ:%d\t", cur->data.ID, cur->data.accout);
				if (cur->data.lost_status == 1)
				{
					printf("���ķ���δ��ʧ\n");
				}
				else
				{
					printf("���ķ����ѹ�ʧ\n");
				}
				system("pause");//��ͣ����
				system("cls");//��տ���̨
				return cur;
			}
			cur = cur->next;
		}
		printf("��ѧ������û�з���\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return NULL;
	}
	else
	{
		printf("��û��Ȩ�޲�ѯ������Ϣ\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
	}
	
}


//¼�뷹����Ϣ
void CardInfoEnter(Card* phead)
{
	if (phead == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	printf("������ѧ��:");
	scanf("%s", phead->data.ID);
	printf("¼��ɹ���\n");
	system("pause");//��ͣ����
	system("cls");//��տ���̨

}




//�����·����ռ估��������
Card* BuyNewCard(Card**pphead)
{
	//�����¿ռ�
	Card* newCard = (Card*)malloc(sizeof(Card));
	if (newCard == NULL)
	{
		printf("����ʧ��");
		return NULL;
	}
	newCard->next = NULL;
	//��������
	if (*pphead == NULL)
	{
		*pphead = newCard;    //����һ��Ҫ������ָ��
	}
	else
	{
		Card* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newCard;
	}
	return newCard;
}


//��ӡ������Ϣ
void PrintCard(Card* phead, Card* cur_user)
{
	if (phead == NULL)
	{
		printf("����ע��\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return ;
	}
	if (cur_user == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return ;
	}
	//����Ա
	if (phead == cur_user)
	{
		Card* cur = phead;
		if (cur == NULL)
		{
			printf("û�з���\n");
			system("pause");//��ͣ����
			system("cls");//��տ���̨
			return;
		}
		while (cur != NULL)
		{
			printf("����ѧ����:%s\t���ķ������Ϊ:%d\t", cur->data.ID, cur->data.accout);
			if (cur->data.lost_status == 1)
			{
				printf("���ķ���δ��ʧ\n");
			}
			else
			{
				printf("���ķ����ѹ�ʧ\n");
			}
			cur = cur->next;
		}
		printf("��������Ϊ:%d\n", CardCount(phead));
		system("pause");//��ͣ����
		system("cls");//��տ���̨
	}
	else  // ��ͨѧ��
	{
		printf("��ֻ��Ȩ�޲鿴�Լ��ķ�����Ϣ:\n");
		printf("����ѧ����:%s\t���ķ������Ϊ:%d\t", cur_user->data.ID, cur_user->data.accout);
		if (cur_user->data.lost_status == 1)
		{
			printf("���ķ���δ��ʧ\n");
		}
		else
		{
			printf("���ķ����ѹ�ʧ\n");
		}
		system("pause");//��ͣ����
		system("cls");//��տ���̨
	}
	
}



//ע������
void CardErase(Card** pphead,Card* cur_user)
{
	if (*pphead == NULL)
	{
		printf("����ע��\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	if (cur_user == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	if (*pphead == cur_user)
	{
		char id[16] = { 0 };
		printf("������Ҫע���ķ���������ID:");
		scanf("%15s", id);
		CardPop(*pphead, id);
	}
	else
	{
		CardPop(*pphead, cur_user->data.ID);
		system("pause");//��ͣ����
		system("cls");//��տ���̨
	}
	
	
}

//ע�������Ӻ���
void CardPop(Card* phead,char id[])
{
	Card* prev = NULL;
	Card* cur = phead;
	Card* next = cur->next;
	while (cur)
	{
		if (strcmp(cur->data.ID, id) == 0)
		{
			if (prev)
			{
				prev->next = next;
			}
			else
			{
				phead = next;
			}
			free(cur);
			//cur = NULL;   //��ʱ����,֮����õ��жϣ���ɾ��
			printf("ע���ɹ�\n");
			system("pause");//��ͣ����
			system("cls");//��տ���̨
			break;
		}
		else
		{
			prev = cur;
			cur = next;
			if (next)
			{
				next = next->next;
			}
		}
	}
	if (cur == NULL)
	{
		printf("��ѧ�������޷���\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
	}
}


//��������
int CardCount(Card* phead)
{
	int count = 0;
	Card* cur = phead;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}


//������ֵ
void CardRecharge(Card* phead)   
{
	if (phead == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	if (phead->data.lost_status == 0)
	{
		printf("�����ѹ�ʧ���޷���ֵ\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	printf("��������Ҫ��ֵ�Ľ��:");
	int recharge_amount = 0;
	scanf("%d", &recharge_amount);
	(phead->data.accout) += recharge_amount;
	printf("��ֵ�ɹ���\n");
	system("pause");//��ͣ����
	system("cls");//��տ���̨
}


//��������
void CardConsume(Card* phead)
{
	if (phead == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");
		system("cls");
		return;
	}
	if (phead->data.lost_status == 0)
	{
		printf("�����ѹ�ʧ���޷�����\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	printf("��������Ҫ���ѵĽ��:");
	int consume_amount = 0;
	scanf("%d", &consume_amount);
	(phead->data.accout) -= consume_amount;
	printf("���ѳɹ���\n");
	system("pause");//��ͣ����
	system("cls");//��տ���̨
}


void CardReportLost(Card* phead)
{
	if (phead == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	if (phead->data.lost_status == 0)
	{
		printf("�ÿ��Ѿ����ڹ�ʧ״̬\n");
	}
	else
	{
		phead->data.lost_status = 0;
		printf("��ʧ�ɹ�\n");
	}
	system("pause");//��ͣ����
	system("cls");//��տ���̨
}

void CardRestoreLost(Card* phead)
{
	if (phead == NULL)
	{
		printf("���ȵ�¼\n");
		system("pause");//��ͣ����
		system("cls");//��տ���̨
		return;
	}
	if (phead->data.lost_status == 1)
	{
		printf("�ÿ�δ��ʧ\n");
	}
	else
	{
		phead->data.lost_status = 1;
		printf("�����ʧ�ɹ�\n");
	}
	system("pause");//��ͣ����
	system("cls");//��տ���̨
}





//���淹����Ϣ
void SaveCard(Card* phead)
{
	//���ļ�
	FILE* pf = fopen("./Card.info", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//д���ļ�
	if (phead == NULL)
	{
		return;
	}
	MealCardData data = phead->data;
	while (fwrite(&data, sizeof(MealCardData), 1, pf))
	{
		if (phead->next != NULL)
		{
			phead = phead->next;
			data = phead->data;
		}
		else
		{
			break;
		}

	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	printf("\n");
}



//�����ļ���Ϣ
void LoadCard(Card** pphead)
{
	//���ļ�
	FILE* pf = fopen("./Card.info", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//�����ļ�
	MealCardData data;
	while (fread(&data, sizeof(MealCardData), 1, pf))
	{
		Card* newCard = BuyNewCard(pphead);
		newCard->data = data;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}










////β�巹��
//void CardPushBack(Card** pphead, MealCardData x)
//{
//	Card* newCard=BuyNewCard(x);
//	if (*pphead == NULL)
//	{
//		*pphead = newCard;
//	}
//	else
//	{
//		Card* tail = *pphead;
//		while (tail->next)
//		{
//			tail = tail->next;
//		}
//		tail->next = newCard;
//	}
//	
//}
//
////βɾ
//void CardPopBack(Card** pphead)
//{
//	Card* prev = NULL;
//	Card* cur = *pphead;
//	while (cur->next != NULL)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//	prev->next = NULL;
//	free(cur);
//	cur = NULL;			//��ʱ����
//
//}