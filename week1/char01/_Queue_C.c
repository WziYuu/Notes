#include"_Queue_H.h"

int main(){
	printf("为方便看懂，Dequeue函数弹出队头的时候，将原队头的值置0\n\n");
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
	printf("给队列赋值："); 
	PrintQueue(Q);	
	Dequeue(Q);
	printf("弹出队头之后：");
	PrintQueue(Q);
	
	printf("队尾加上123：") ;
	Enqueue(123,Q);
	PrintQueue(Q);
	
	Dequeue(Q);
	Dequeue(Q);
	Enqueue(456,Q);
	printf("再弹出队头两次并在队尾追加456：");
	PrintQueue(Q);
	
	printf("Front：%d\n",Front(Q));
	printf("FrontAndDequeue:%d,之后的队列是：",FrontAndDequeue(Q));
	PrintQueue(Q);
	
	printf("清空队列："); 
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
//		printf("EN:Rear:%d,Front:%d\n",Q->Rear,Q->Front); //调试时使用 
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
	
//	printf("DE:Rear:%d,Front:%d\n",Q->Rear,Q->Front); // 调试时使用 
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

EleType Front(Queue Q){// 返回表头的数据
	return Q->Array[Q->Front];
}

EleType FrontAndDequeue(Queue Q){
	EleType Ele;
	Ele = Front(Q);
	Dequeue(Q);
	return Ele;
}


