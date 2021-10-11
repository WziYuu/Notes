#include"_Stack_H.h"

int main(){
	Stack S;
	S = CreateStack();
	printf("%d\n",IsEmpty(S));
	Push(2, S);
	printf("%d\n",IsEmpty(S));
	Push(3, S);
	Push(4, S);
	Push(5, S);
	PrintStack(S);
	Pop(S);
	PrintStack(S);
	printf("%d\n",Top(S));
	MakeEmpty(S);
	printf("%d\n",IsEmpty(S));
	DisposeStack(S);
	/*
	1
	0
	5,4,3,2,
	4,3,2,
	4
	1
	*/ 
}

void PrintStack(Stack S){
	Stack TMP;
	TMP = S->Next;
	while(TMP != NULL){
		printf("%d,",TMP->Elem);
		TMP = TMP->Next;
	}
	printf("\n");
}

Stack CreateStack(){
	Stack S;
	S = malloc(sizeof(struct Node));
	S->Next = NULL; 
	return S;
}

int IsEmpty(Stack S){
	return S->Next == NULL;
}

void Push(ElemType X, Stack S){
	Stack TMP; 
	TMP = malloc(sizeof(struct Node));
	TMP->Next = S->Next;
	S->Next = TMP;
	TMP->Elem = X;
}



void DisposeStack(Stack S){
	MakeEmpty(S);
	free(S); 
}

void MakeEmpty(Stack S){
	while(!IsEmpty(S)){
		Pop(S);
	}
}



void Pop(Stack S){
	Stack TMP;
	TMP = S->Next;
	S->Next = S->Next->Next;
	free(TMP);
}

ElemType Top(Stack S){
	return S->Next->Elem;
}
