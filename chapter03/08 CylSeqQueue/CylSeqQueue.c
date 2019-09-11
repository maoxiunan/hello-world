/****************************************
 *                                      *
 * �ļ���: ��03 ջ�Ͷ���\08 CylSeqQueue *
 *                                      *
 * �ļ���: CylSeqQueue.c                *
 *                                      *
 ****************************************/

#ifndef CYLSEQQUEUE_C
#define CYLSEQQUEUE_C

#include "CylSeqQueue.h" 				//**chapter03**//

Status InitQueue_CSq(CSqQueue *Q)
{
	(*Q).base = (QElemType_CSq *)malloc(MAXQSIZE*sizeof(QElemType_CSq));
	if(!(*Q).base)
		exit(OVERFLOW);

	(*Q).front = (*Q).rear = 0;

	return OK;
}

void ClearQueue_CSq(CSqQueue *Q)
{
	(*Q).front = (*Q).rear = 0;
}

void DestroyQueue_CSq(CSqQueue *Q)
{
	if((*Q).base)
		free((*Q).base);
		
	(*Q).base = NULL;
	(*Q).front = (*Q).rear = 0;
}

Status QueueEmpty_CSq(CSqQueue Q)
{
	if(Q.front==Q.rear) 						//���пյı�־
		return TRUE;
	else
		return FALSE;
}

int QueueLength_CSq(CSqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE) % MAXQSIZE;//���г��� 
}

Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e)
{
	if(Q.front==Q.rear)							//���п�
		return ERROR;
		
	*e = Q.base[Q.front];
	
	return OK;
}

Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e)
{
	if(((*Q).rear+1)%MAXQSIZE == (*Q).front)	//������
		return ERROR;
		
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear+1)%MAXQSIZE;
	
	return OK;
}

Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e)
{
	if((*Q).front==(*Q).rear)					//���п�
		return ERROR;
		
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front+1)%MAXQSIZE;
	
	return OK;
}

void QueueTraverse_CSq(CSqQueue Q, void(Visit)(QElemType_CSq))
{
	int i = Q.front;
	
	while(i!=Q.rear)
	{
		Visit(Q.base[i]);
		i = (i+1)%MAXQSIZE;
	}
}

#endif
