#include<stdio.h>
#include<stdlib.h>

struct Heap;
typedef struct Heap *PQueue;
typedef int ElemType;

PQueue Init(int MaxElems);
void Destory(PQueue P);
void MakeEmpty(PQueue P);
void Insert(ElemType X,PQueue P);
ElemType DeleteMin(PQueue P);
ElemType FindMin(PQueue P);
int IsEmpty(PQueue P);
int IsFull(PQueue P);

struct Heap{
    int Capacity;
    int Size;
    int *Ele;
};
