#include "MealCard.h"

//打印菜单
void PrintMenu()
{
	printf("*********************************\n");
	printf("*\t饭卡充值消费管理系统\t*\n");
	printf("*********************************\n");
	printf("*\t请选择功能\t\t*\n");
	printf("*********************************\n");
	printf("*\t1.注册\t\t\t*\n");
	printf("*\t2.登录\t\t\t*\n");
	printf("*\t3.录入饭卡信息\t\t*\n");
	printf("*\t4.饭卡充值\t\t*\n");
	printf("*\t5.饭卡消费\t\t*\n");
	printf("*\t6.查找饭卡信息\t\t*\n");
	printf("*\t7.打印饭卡信息\t\t*\n");
	//printf("*\t8.修改饭卡信息\t\t*\n");
	printf("*\t8.注销饭卡信息\t\t*\n");
	printf("*\t9.挂失饭卡\t\t*\n");
	printf("*\t10.解除挂失饭卡\t\t*\n");
	printf("*\t11.退出系统\t\t*\n");
	printf("*********************************\n");
}

//注册
void Register(Card**pphead)
{
	//开辟新空间
	Card* newCard = BuyNewCard(pphead);
	//注册信息
	int record = 0;
	printf("请输入10位用户名:");
	char username[11] = { 0 };
	scanf("%10s", username);
	//如果缓存区不为空，重新输入
	do{
		if (getchar() != '\n')
		{
			//清空缓存区
			while (getchar() != '\n')
			{
				;
			}
			printf("输入用户名超出10位，请重新输入:");
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
		printf("用户名已存在，请登录\n");
	}
	else
	{
		strcpy(newCard->data.user_name, username);

		printf("请输入密码:");
		scanf("%10s", newCard->data.user_password);
		//如果缓存区不为空，重新输入
		do {
			if (getchar() != '\n')
			{
				//清空缓存区
				while (getchar() != '\n')
				{
					;
				}
				printf("输入密码超出10位，请重新输入:");
				scanf("%10s", newCard->data.user_password);
				record = 1;
			}
			else
			{
				record = 0;
			}
		} while (record);
		//初始化金额
		newCard->data.accout = 0;
		//初始化ID
		strcpy(newCard->data.ID, "暂未录入");
		//初始化挂失状态
		newCard->data.lost_status = 1; //未挂失
	}
	system("pause");//暂停程序
	system("cls");//清空控制台
}


//登录
Card* Login(Card* phead)
{
	char User_name[10] = { 0 };
	char User_password[10] = { 0 };
	printf("请输入用户名:");
	scanf("%10s", &User_name);
	//记录当前用户链表节点
	Card* cur = CardFind(phead, User_name);
	if (cur == NULL)
	{
		printf("不存在该用户,请先注册\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return NULL;
	}
	else 
	{
		printf("请输入密码:");
		scanf("%10s", &User_password);
		if (strcmp(User_password, cur->data.user_password) == 0)
		{
			printf("登陆成功！\n");
		}
		system("pause");//暂停程序
		system("cls");//清空控制台
		return cur;
	}
}


//用户名查找
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



//查找饭卡
Card* CardIDFind(Card* phead, Card* cur_user)
{
	if (phead == NULL)
	{
		printf("请先注册\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return NULL;
	}
	if (cur_user == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return NULL;
	}
	if (phead == cur_user)
	{
		char id[16] = { 0 };
		printf("请输入要查找的学生ID:");
		scanf("%15s", id);
		Card* cur = phead;
		while (cur)
		{
			if ((strcmp(cur->data.ID, id)) == 0)
			{
				printf("您的学号是:%s\t您的饭卡余额为:%d\t", cur->data.ID, cur->data.accout);
				if (cur->data.lost_status == 1)
				{
					printf("您的饭卡未挂失\n");
				}
				else
				{
					printf("您的饭卡已挂失\n");
				}
				system("pause");//暂停程序
				system("cls");//清空控制台
				return cur;
			}
			cur = cur->next;
		}
		printf("该学生名下没有饭卡\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return NULL;
	}
	else
	{
		printf("您没有权限查询饭卡信息\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
	}
	
}


//录入饭卡信息
void CardInfoEnter(Card* phead)
{
	if (phead == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	printf("请输入学号:");
	scanf("%s", phead->data.ID);
	printf("录入成功！\n");
	system("pause");//暂停程序
	system("cls");//清空控制台

}




//申请新饭卡空间及链接链表
Card* BuyNewCard(Card**pphead)
{
	//申请新空间
	Card* newCard = (Card*)malloc(sizeof(Card));
	if (newCard == NULL)
	{
		printf("申请失败");
		return NULL;
	}
	newCard->next = NULL;
	//链接链表
	if (*pphead == NULL)
	{
		*pphead = newCard;    //所以一定要传二级指针
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


//打印饭卡信息
void PrintCard(Card* phead, Card* cur_user)
{
	if (phead == NULL)
	{
		printf("请先注册\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return ;
	}
	if (cur_user == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return ;
	}
	//管理员
	if (phead == cur_user)
	{
		Card* cur = phead;
		if (cur == NULL)
		{
			printf("没有饭卡\n");
			system("pause");//暂停程序
			system("cls");//清空控制台
			return;
		}
		while (cur != NULL)
		{
			printf("您的学号是:%s\t您的饭卡余额为:%d\t", cur->data.ID, cur->data.accout);
			if (cur->data.lost_status == 1)
			{
				printf("您的饭卡未挂失\n");
			}
			else
			{
				printf("您的饭卡已挂失\n");
			}
			cur = cur->next;
		}
		printf("饭卡总数为:%d\n", CardCount(phead));
		system("pause");//暂停程序
		system("cls");//清空控制台
	}
	else  // 普通学生
	{
		printf("您只有权限查看自己的饭卡信息:\n");
		printf("您的学号是:%s\t您的饭卡余额为:%d\t", cur_user->data.ID, cur_user->data.accout);
		if (cur_user->data.lost_status == 1)
		{
			printf("您的饭卡未挂失\n");
		}
		else
		{
			printf("您的饭卡已挂失\n");
		}
		system("pause");//暂停程序
		system("cls");//清空控制台
	}
	
}



//注销饭卡
void CardErase(Card** pphead,Card* cur_user)
{
	if (*pphead == NULL)
	{
		printf("请先注册\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	if (cur_user == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	if (*pphead == cur_user)
	{
		char id[16] = { 0 };
		printf("请输入要注销的饭卡所有人ID:");
		scanf("%15s", id);
		CardPop(*pphead, id);
	}
	else
	{
		CardPop(*pphead, cur_user->data.ID);
		system("pause");//暂停程序
		system("cls");//清空控制台
	}
	
	
}

//注销饭卡子函数
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
			//cur = NULL;   //临时变量,之后会用到判断，不删了
			printf("注销成功\n");
			system("pause");//暂停程序
			system("cls");//清空控制台
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
		printf("该学生名下无饭卡\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
	}
}


//饭卡总数
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


//饭卡充值
void CardRecharge(Card* phead)   
{
	if (phead == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	if (phead->data.lost_status == 0)
	{
		printf("饭卡已挂失，无法充值\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	printf("请输入你要充值的金额:");
	int recharge_amount = 0;
	scanf("%d", &recharge_amount);
	(phead->data.accout) += recharge_amount;
	printf("充值成功！\n");
	system("pause");//暂停程序
	system("cls");//清空控制台
}


//饭卡消费
void CardConsume(Card* phead)
{
	if (phead == NULL)
	{
		printf("请先登录\n");
		system("pause");
		system("cls");
		return;
	}
	if (phead->data.lost_status == 0)
	{
		printf("饭卡已挂失，无法消费\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	printf("请输入你要消费的金额:");
	int consume_amount = 0;
	scanf("%d", &consume_amount);
	(phead->data.accout) -= consume_amount;
	printf("消费成功！\n");
	system("pause");//暂停程序
	system("cls");//清空控制台
}


void CardReportLost(Card* phead)
{
	if (phead == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	if (phead->data.lost_status == 0)
	{
		printf("该卡已经处于挂失状态\n");
	}
	else
	{
		phead->data.lost_status = 0;
		printf("挂失成功\n");
	}
	system("pause");//暂停程序
	system("cls");//清空控制台
}

void CardRestoreLost(Card* phead)
{
	if (phead == NULL)
	{
		printf("请先登录\n");
		system("pause");//暂停程序
		system("cls");//清空控制台
		return;
	}
	if (phead->data.lost_status == 1)
	{
		printf("该卡未挂失\n");
	}
	else
	{
		phead->data.lost_status = 1;
		printf("解除挂失成功\n");
	}
	system("pause");//暂停程序
	system("cls");//清空控制台
}





//保存饭卡信息
void SaveCard(Card* phead)
{
	//打开文件
	FILE* pf = fopen("./Card.info", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//写入文件
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
	//关闭文件
	fclose(pf);
	pf = NULL;
	printf("\n");
}



//读入文件信息
void LoadCard(Card** pphead)
{
	//打开文件
	FILE* pf = fopen("./Card.info", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//读入文件
	MealCardData data;
	while (fread(&data, sizeof(MealCardData), 1, pf))
	{
		Card* newCard = BuyNewCard(pphead);
		newCard->data = data;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}










////尾插饭卡
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
////尾删
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
//	cur = NULL;			//临时变量
//
//}