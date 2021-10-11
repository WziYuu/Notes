#include"_Queue_H.h"

int main(){
	printf("Ϊ���㿴����Dequeue����������ͷ��ʱ�򣬽�ԭ��ͷ��ֵ��0\n\n");
	Queue Q;
	Q = CreateQueue(10);
	Enqueue(111,Q);
	Enqueue(222,Q);
	Enqueue(333,Q);
	Enqueue(444,Q);
	Enqueue(555,Q);
	Enqueue(666,Q);
	Enqueue(777,Q);
	Enqueue(888,Q);
	Enqueue(999,Q);
	Enqueue(1010,Q);
	printf("�����и�ֵ��"); 
	PrintQueue(Q);	
	Dequeue(Q);
	printf("������ͷ֮��");
	PrintQueue(Q);
	
	printf("��β����123��") ;
	Enqueue(123,Q);
	PrintQueue(Q);
	
	Dequeue(Q);
	Dequeue(Q);
	Enqueue(456,Q);
	printf("�ٵ�����ͷ���β��ڶ�β׷��456��");
	PrintQueue(Q);
	
	printf("Front��%d\n",Front(Q));
	printf("FrontAndDequeue:%d,֮��Ķ����ǣ�",FrontAndDequeue(Q));
	PrintQueue(Q);
	
	printf("��ն��У�"); 
	MakeEmpty(Q);
	PrintQueue(Q);
	DisposeQueue(Q); 
	return 0;
}

Queue CreateQueue(int MaxElements){
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	Q->Front = 0;
	Q->Rear = -1;
	Q->Capacity = MaxElements;
	Q->Size = 0;
	return Q;
} 

void PrintQueue(Queue Q){
	int i;
	for(i = 0;i < 10;i ++){
		printf("%d,",Q->Array[i]);
	}
	printf("\n");
}

int IsEmpty(Queue Q){
	return Q->Size == 0;
}

int IsFull(Queue Q){
	return Q->Size == Q->Capacity;
}

void Enqueue(EleType X,Queue Q){
	if(IsFull(Q)){
		printf("Queue is full!");
	}
	else{
		Q->Rear++;
		if(Q->Front >= Q->Capacity){
			Q->Front = 0;
		}
		if(Q->Rear >= Q->Capacity){
			Q->Rear = 0;
		}
		
		Q->Array[Q->Rear] = X;
		Q->Size++;
//		printf("EN:Rear:%d,Front:%d\n",Q->Rear,Q->Front); //����ʱʹ�� 
	}
}

void Dequeue(Queue Q){
	EleType t; 
	if(Q->Front >= Q->Capacity){
		Q->Front = 0;
	}
	if(Q->Rear >= Q->Capacity){
		Q->Rear = 0;
	}
	
//	printf("DE:Rear:%d,Front:%d\n",Q->Rear,Q->Front); // ����ʱʹ�� 
	t = Q->Array[Q->Front];
	Q->Array[Q->Front] = 0;
	Q->Front++;
	Q->Size--;
}

void DisposeQueue(Queue Q){
	free(Q);
}

void MakeEmpty(Queue Q){
	if(IsEmpty(Q))
		printf("ERROR");
	else{
		while(!IsEmpty(Q))
			Dequeue(Q);
	}	
}

EleType Front(Queue Q){// ���ر�ͷ������
	return Q->Array[Q->Front];
}

EleType FrontAndDequeue(Queue Q){
	EleType Ele;
	Ele = Front(Q);
	Dequeue(Q);
	return Ele;
}


