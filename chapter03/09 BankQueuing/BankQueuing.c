/****************************************
 *                                      *
 * �ļ���: ��03 ջ�Ͷ���\09 BankQueuing *
 *                                      *
 * �ļ���: BankQueuing.c                *
 *                                      *
 * ��  ��: 3.6��3.7                     * 
 *                                      *
 ****************************************/

#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h" 				//**chapter03**//

/*�T�T�T�T�[
�U �㷨3.6�U 
�^�T�T�T�T*/
void Bank_Simulation_1()				//����ҵ��ģ�⣬ͳ��һ���ڿͻ������ж�����ƽ��ʱ�� 
{
	char eventType;
	
	OpenForDay();						//��ʼ��

	while(MoreEvent())
	{
		EventDrived(&eventType);		//�¼�����
		
		switch(eventType)
		{
			case 'A': 
				CustomerArrived();
				break;
			case 'D': 
				CustomerDeparture();
				break;
			default : 
				Invalid();
		}
	}
	
	CloseForDay();
}
 
void OpenForDay() 
{	
	int i;
	
	gTotalTime = 0;					//��ʼ���ۼ�ʱ��Ϳͻ���Ϊ0 
	gCustomerNum = 0;
			
	InitList_L(&gEv);				//��ʼ���¼�����Ϊ�ձ�

	gEn.OccurTime = 0;				//�趨��һ���ͻ������¼� 
	gEn.NType = Arrive;
	 
	OrderInsert(gEv, gEn, cmp);		//�����¼���
	
	for(i=1; i<=4; ++i) 
		InitQueue_L(&gQ[i]);		//�ÿն���

	Show();
}

Status MoreEvent()
{
	if(!ListEmpty_L(gEv))
		return TRUE;
	else
		return FALSE;
}

void EventDrived(char *event)
{
	ListDelete_L(gEv, 1, &gEn);
	
	if(gEn.NType==Arrive)
		*event = 'A';
	else
		*event = 'D';
}

void CustomerArrived()							//����ͻ������¼���gEn.NType=0 
{	
	int durtime, intertime; 
	int cur_LeftTime, suc_ArrivalTime;
	int i;
	
	++gCustomerNum;								//�ܿͻ�����һ 
	
	Random(&durtime, &intertime);				//���ɵ�ǰ�ͻ�����ҵ����Ҫ��ʱ�����һ���ͻ��ﵽʱ����
	cur_LeftTime    = gEn.OccurTime + durtime;	//��ǰ�ͻ����뿪ʱ�� 
	suc_ArrivalTime = gEn.OccurTime + intertime;//��һ���ͻ�����ʱ�� 
			
	gCustomerRcd.ArrivedTime = gEn.OccurTime;	//��¼��ǰ�ͻ���Ϣ 
	gCustomerRcd.Duration    = durtime;
	gCustomerRcd.Count       = gCustomerNum;

	i = Minimum(gQ);							//�󳤶���̶���
	EnQueue_L(&gQ[i], gCustomerRcd); 			//��ǰ�ͻ�������̶���
	Show();
	
	if(suc_ArrivalTime<gCloseTime)				//������δ���ţ�����һ�ͻ������¼������¼���
	{
		gEn.OccurTime = suc_ArrivalTime;		//gEn�Ĳ����Ѿ��ı� 
		gEn.NType = Arrive;
		OrderInsert(gEv, gEn, cmp);
	}

	if(QueueLength_L(gQ[i])==1)					//�趨��i���еĶ�ͷ�ͻ����뿪�¼��������¼���
	{
		gEn.OccurTime = cur_LeftTime;
		gEn.NType = i;		
		OrderInsert(gEv, gEn, cmp);					
	}
}

void CustomerDeparture()						//����ͻ��뿪�¼�,gEn.NType>0
{
	int i = gEn.NType;
	
	DeQueue_L(&gQ[i], &gCustomerRcd);			//ɾ����i���е���ͷ�ͻ�
	Show();
		
	gTotalTime += gEn.OccurTime - gCustomerRcd.ArrivedTime;	//�ۼƿͻ�����ʱ��
	
	if(!QueueEmpty_L(gQ[i]))					//�趨��i���еĵ�һ���뿪�¼��������¼��� 
	{
		GetHead_L(gQ[i], &gCustomerRcd);
		gEn.OccurTime += gCustomerRcd.Duration;
		gEn.NType = i;
		OrderInsert(gEv,gEn,cmp);
	} 
}

void Invalid()
{
	printf("���д���");
		exit(OVERFLOW);
}

void CloseForDay()
{
	printf("�����ܹ���%d���ͻ���ƽ������ʱ��Ϊ%d���ӡ�\n",gCustomerNum,gTotalTime/gCustomerNum);
}

int cmp(Event a, Event b)					//�Ƚ����¼��������� 
{
	if(a.OccurTime<b.OccurTime)				//a����b���� 
		return -1;
	if(a.OccurTime==b.OccurTime)			//a��bͬʱ���� 
		return 0;
	if(a.OccurTime>b.OccurTime)				//a����b���� 
		return 1;
}

void Random(int *durtime, int *intertime)
{
	srand((unsigned)time(NULL));
	*durtime = rand()%DurationTime+1;		//��ҵ��ʱ�����1��20����
	*intertime = rand()%IntervalTime+1; 	//��һ���˿�����ʱ��Ϊ���1��10���� 
}

Status OrderInsert(EventList gEv, Event gEn, int (cmp)(Event,Event))
{
	int i;
	EventList p, pre, s;
	
	pre = gEv;
	p = gEv->next;							//pָ���һ���¼� 
	
	while(p && cmp(gEn, p->data)==1)		//����gEn���¼�����Ӧ�ò����λ��
	{
		pre = p;
		p = p->next;
	}
	
	s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	
	s->data = gEn;							//��gEn�����¼���
	s->next = pre->next;
	pre->next = s;
	
	return OK;
}

int Minimum()
{
	int i1 = QueueLength_L(gQ[1]);
	int i2 = QueueLength_L(gQ[2]);
	int i3 = QueueLength_L(gQ[3]);
	int i4 = QueueLength_L(gQ[4]);
	
	if(i1<=i2 && i1<=i3 && i1<=i4)
		return 1;
	if(i2<i1  && i2<=i3 && i2<=i4)
		return 2;
	if(i3<i1  && i3<i2  && i3<=i4)
		return 3;
	if(i4<i1  && i4<i2  && i4<i3 )
		return 4;
}

void Show()
{
	int i;
	QueuePtr p;								//��¼�����Ŀͻ��ǵڼ��� 
	
	system("cls");
	
	for(i=1; i<=4; i++)
	{
		for(p=gQ[i].front; p; p=p->next)
		{
			if(p==gQ[i].front)
			{
				if(i==1)
					printf("��̨�١�");
				if(i==2)
					printf("��̨�ڡ�");
				if(i==3)
					printf("��̨�ۡ�");
				if(i==4)
					printf("��̨�ܡ�");
			}
			else
				printf("��%03d��",p->data.Count);			

	
			if(p==gQ[i].rear)
				printf("\n"); 
		}
	}
	
	Wait(SleepTime);
}

/*�T�T�T�T�[
�U �㷨3.7�U 
�^�T�T�T�T*/
void Bank_Simulation_2()
{
	OpenForDay();							//��ʼ��
	
	while(!ListEmpty_L(gEv))
	{
		ListDelete_L(gEv, 1, &gEn);
		
		if(gEn.NType==Arrive)
			CustomerArrived();				//����ͻ������¼� 
		else
			CustomerDeparture();			//����ͻ��뿪�¼� 
	}
	
	printf("�����ܹ���%d���ͻ���ƽ������ʱ��Ϊ%d���ӡ�\n",gCustomerNum,gTotalTime/gCustomerNum);//����ƽ������ʱ��	
}

#endif
