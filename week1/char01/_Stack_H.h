#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElemType;

struct Node{
	ElemType Elem;
	PtrToNode Next;
};

int IsEmpty(Stack S);
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElemType X, Stack S);
void Pop(Stack S);
ElemType Top(Stack S);


