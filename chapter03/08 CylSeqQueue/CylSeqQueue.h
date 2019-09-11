/****************************************
 *                                      *
 * �ļ���: ��03 ջ�Ͷ���\08 CylSeqQueue *
 *                                      *
 * �ļ���: CylSeqQueue.h                *
 *                                      *
 * ��  ��: ѭ��������ز����б�         *
 *                                      *
 ****************************************/

#ifndef CYLSEQQUEUE_H
#define CYLSEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "../../��01 ����/Status.h"		//**chapter01**//

/* �궨�� */
#define MAXQSIZE 1000					//�����г���

/* ѭ���������Ͷ��� */
typedef int QElemType_CSq;
typedef struct							//���е�˳��洢�ṹ
{
	QElemType_CSq *base;				//��ʼ���Ķ�̬����洢�ռ� 
	int front;							//ͷָ�룬�����в��գ�ָ���ͷԪ�� 
	int rear;							//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� 
}CSqQueue;

/* ѭ�����к����б� */
Status InitQueue_CSq(CSqQueue *Q);
/*������������������������
��(chapter01)��ʼ��ѭ������Q�� ��
������������������������*/

void ClearQueue_CSq(CSqQueue *Q);
/*��������������
��(02)�ÿ�Q�� ��
��������������*/

void DestroyQueue_CSq(CSqQueue *Q);
/*��������������
��(chapter03)����Q�� ��
��������������*/

Status QueueEmpty_CSq(CSqQueue Q);
/*����������������������
��(04)�ж�Q�Ƿ�Ϊ�ա� ��
����������������������*/

int QueueLength_CSq(CSqQueue Q);
/*����������������������
��(05)����QԪ�ظ����� ��
����������������������*/

Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e);
/*������������������������
��(06)��e��ȡ��ͷԪ�ء� ��
������������������������*/

Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e);
/*������������������
��(07)Ԫ��e��ӡ� ��
������������������*/

Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e);
/*������������������
��(08)Ԫ��e���ӡ� ��
������������������*/

void QueueTraverse_CSq(CSqQueue Q, void(Visit)(QElemType_CSq));
/*����������������
��(09)���ʶ��С���
����������������*/

#endif
