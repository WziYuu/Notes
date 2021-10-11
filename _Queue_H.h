#include<stdio.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int EleType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(EleType X, Queue Q);
void PrintQueue(Queue Q);
EleType Front(Queue Q);
void Dequeue(Queue Q);
EleType FrontAndDequeue(Queue Q);

struct QueueRecord{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	EleType Array[10];
};


