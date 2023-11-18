#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <string.h>

//用户数据
typedef struct Userinfo
{
	char user_name[11];			//用户名
	char user_password[11];		//密码
	char ID[16];				//学号
	int accout;					//余额
	int lost_status;			//挂失状态   0为挂失，1为正常
}User;

typedef User MealCardData;


//链表
typedef struct MealCard
{
	MealCardData data;
	struct MealCard* next;
}Card;





void PrintMenu();												//打印菜单    ,在执行函数前 说：你有/没有权限
void Register(Card** pphead);									//1.注册
Card* Login(Card* phead);										//2.登录
void CardInfoEnter(Card*phead);									//3.录入饭卡信息
void CardRecharge(Card* phead);									//4.饭卡充值
void CardConsume(Card* phead);									//5.饭卡消费
Card* CardIDFind(Card* phead, Card* cur_user);					//6.饭卡查找
void PrintCard(Card* phead, Card* cur_user);					//7.打印饭卡信息
void CardErase(Card** pphead,Card* cur_user);					//8.注销饭卡
void CardReportLost(Card* phead);								//9.挂失饭卡
void CardRestoreLost(Card* phead);								//10.解除挂失饭卡

void CardPop(Card* phead, char id[]);							//注销饭卡子函数

Card* CardFind(Card* phead, char* username);					//用户名查找
int CardCount(Card* phead);										//饭卡数量
Card* BuyNewCard(Card** pphead);								//申请新饭卡空间及链接链表

void SaveCard(Card* phead);										//保存饭卡信息
void LoadCard(Card** pphead);									//读取文件信息


//void CardPushBack(Card **pphead, MealCardData x);				//尾插饭卡
//void CardPopBack(Card** pphead);								//尾删饭卡