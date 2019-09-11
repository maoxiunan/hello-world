/**************************************
 *                                    *
 * �ļ���: ��03 ջ�Ͷ���\07 LinkQueue *
 *                                    *
 * �ļ���: LinkQueue.h                *
 *                                    *
 * ��  ��: ������ز����б�           *
 *                                    *
 *************************************/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"		//**chapter01**//

/* �������Ͷ��� */
/* ��ģ�������Ŷӡ���������������洢���㷨�У�QElemType_L�����¶���*/
#if !defined BANKQUEUING_H     &&  \
    !defined TRI_BINARYTREE_H
typedef int QElemType_L;
#endif
typedef struct QNode				 
{
	QElemType_L data;
	struct QNode *next;
}QNode;
typedef QNode* QueuePtr;
typedef struct
{
	QueuePtr front;					//ͷָ�� 
	QueuePtr rear;					//βָ�� 
}LinkQueue;							//���е���ʽ�洢��ʾ 

/* ��ջ�����б� */
Status InitQueue_L(LinkQueue *Q);
/*��������������������
��(chapter01)��ʼ������Q�� ��
��������������������*/

void ClearQueue_L(LinkQueue *Q);
/*��������������
��(02)�ÿ�Q�� ��
��������������*/

void DestroyQueue_L(LinkQueue *Q);
/*��������������
��(chapter03)����Q�� ��
��������������*/

Status QueueEmpty_L(LinkQueue Q);
/*����������������������
��(04)�ж�Q�Ƿ�Ϊ�ա� ��
����������������������*/

int QueueLength_L(LinkQueue Q);
/*����������������������
��(05)����QԪ�ظ����� ��
����������������������*/

Status GetHead_L(LinkQueue Q, QElemType_L *e);
/*������������������������
��(06)��e��ȡ��ͷԪ�ء� ��
������������������������*/

Status EnQueue_L(LinkQueue *Q, QElemType_L e);
/*������������������
��(07)Ԫ��e��ӡ� ��
������������������*/

Status DeQueue_L(LinkQueue *Q, QElemType_L *e);
/*������������������
��(08)Ԫ��e���ӡ� ��
������������������*/

void QueueTraverse_L(LinkQueue Q, void(Visit)(QElemType_L));
/*����������������
��(09)���ʶ��С���
����������������*/

#endif
