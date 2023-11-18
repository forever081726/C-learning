#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <string.h>

//�û�����
typedef struct Userinfo
{
	char user_name[11];			//�û���
	char user_password[11];		//����
	char ID[16];				//ѧ��
	int accout;					//���
	int lost_status;			//��ʧ״̬   0Ϊ��ʧ��1Ϊ����
}User;

typedef User MealCardData;


//����
typedef struct MealCard
{
	MealCardData data;
	struct MealCard* next;
}Card;





void PrintMenu();												//��ӡ�˵�    ,��ִ�к���ǰ ˵������/û��Ȩ��
void Register(Card** pphead);									//1.ע��
Card* Login(Card* phead);										//2.��¼
void CardInfoEnter(Card*phead);									//3.¼�뷹����Ϣ
void CardRecharge(Card* phead);									//4.������ֵ
void CardConsume(Card* phead);									//5.��������
Card* CardIDFind(Card* phead, Card* cur_user);					//6.��������
void PrintCard(Card* phead, Card* cur_user);					//7.��ӡ������Ϣ
void CardErase(Card** pphead,Card* cur_user);					//8.ע������
void CardReportLost(Card* phead);								//9.��ʧ����
void CardRestoreLost(Card* phead);								//10.�����ʧ����

void CardPop(Card* phead, char id[]);							//ע�������Ӻ���

Card* CardFind(Card* phead, char* username);					//�û�������
int CardCount(Card* phead);										//��������
Card* BuyNewCard(Card** pphead);								//�����·����ռ估��������

void SaveCard(Card* phead);										//���淹����Ϣ
void LoadCard(Card** pphead);									//��ȡ�ļ���Ϣ


//void CardPushBack(Card **pphead, MealCardData x);				//β�巹��
//void CardPopBack(Card** pphead);								//βɾ����