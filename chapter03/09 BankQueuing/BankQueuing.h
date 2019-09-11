/****************************************
 *                                      *
 * �ļ���: ��03 ջ�Ͷ���\09 BankQueuing *
 *                                      *
 * �ļ���: BankQueuing.h                *
 *                                      *
 * ��  ��: ģ�������Ŷ���ز����б�     *
 *                                      *
 ****************************************/

#ifndef BANKQUEUING_H
#define BANKQUEUING_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include <time.h>						//�ṩtimeԭ��
#include "../../��01 ����/Status.h"		//**chapter01**//

/* �궨�� */
#define SleepTime 1						//SleepTime��������ʱ��
#define DurationTime 20					//����ҵ�����ʱ���1��DurationTime���Ӳ��� 
#define IntervalTime 10					//��һ���ͻ�����ʱ����Ϊ1��IntervalTime���Ӳ��� 

/* ���Ͷ��� */
typedef enum
{
	Arrive,Leave_1,Leave_2,Leave_3,Leave_4
}EventType;								//�¼����ͣ�0�������¼���1��4��ʾ�ĸ����ڵ��뿪�¼�
typedef struct         					//�¼�����                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
{
	int OccurTime;						//�¼�����ʱ��
	EventType NType;					//�¼�����
}Event;
typedef Event LElemType_L;				//�¼�����Ԫ�� 
typedef struct LNode
{
	LElemType_L data;
	struct LNode *next;
}LNode; 
typedef LNode* LinkList;
typedef LinkList EventList;											//�¼��������ͣ�����Ϊ��������
#include "../../��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**02**//
typedef struct
{
	int ArrivedTime;					//�ͻ�����ʱ��
	int Duration;						//�������������ʱ��
	int Count;							//�˱�����¼����ÿ�����еĿͻ��ǵڼ���
}QElemType_L;							//���е�����Ԫ������ 
#include "../07 LinkQueue/LinkQueue.c"	//**chapter03**//

/* ȫ�ֱ��� */
int gTotalTime, gCustomerNum;			//�ۼƿͻ�����ʱ�䣬�ͻ���
int gCloseTime = 480;					//����ʱ��,��������ÿ��Ӫҵ8Сʱ��480�� 
EventList gEv;							//�¼���
Event gEn;								//�¼�
LinkQueue gQ[5];						//4���ͻ�����,0�ŵ�Ԫ����
QElemType_L gCustomerRcd;				//�ͻ���¼ 
 
/* ģ�������ŶӺ����б� */
void Bank_Simulation_1();
/*����������������������������������
��(chapter01)�㷨3.6��ģ�������Ŷ��¼��� ��
����������������������������������*/

void OpenForDay();
/*������������������������������
��(02)���п��ţ���ʼ������������
������������������������������*/

Status MoreEvent();
/*��������������������������
��(chapter03)�ж��¼����Ƿ�Ϊ�ա���
��������������������������*/

void EventDrived(char *event);
/*����������������������������������
��(04)�¼���������ȡ��ǰ�¼����͡���
����������������������������������*/

void CustomerArrived();
/*������������������������
��(05)����ͻ������¼�����
������������������������*/

void CustomerDeparture();
/*������������������������
��(06)����ͻ��뿪�¼�����
������������������������*/

void Invalid();
/*��������������������
��(07)�¼����ʹ��󡣩�
��������������������*/

void CloseForDay();
/*����������������
��(08)���й��š���
����������������*/

int cmp(Event a, Event b);
/*����������������������������������
��(09)�Ƚ��¼�a��b�������Ⱥ���򡣩�
����������������������������������*/

void Random(int *durtime, int *intertime);
/*������������������������������������������������������������������������
��(10)�����������������ǰ�ͷ�����ҵ������ʱ�����һ�ͻ���������ʱ�䡣��
������������������������������������������������������������������������*/

Status OrderInsert(EventList gEv, Event gEn, int(cmp)(Event,Event));
/*��������������������������������
��(11)���¼������¼�����ȷλ�á���
��������������������������������*/

int Minimum();
/*����������������������������
��(12)�󳤶���̶��е���š���
����������������������������*/

void Show();
/*����������������������������������
��(13)��ʾ��ǰ���еĿͻ��Ŷ��������
����������������������������������*/

void Bank_Simulation_2();
/*����������������������������������
��(14)�㷨3.7��ģ�������Ŷ��¼��� ��
����������������������������������*/

#endif
