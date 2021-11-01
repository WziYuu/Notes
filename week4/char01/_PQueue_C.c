#include"_PQueue_H.h"



int main(){
	PQueue P;
	P = Init(100);
	Insert(12,P);
	Insert(13,P);
	Insert(8,P);
	Insert(6,P);
	Insert(14,P);
	Insert(66,P);
	Insert(75,P);
	Insert(15,P);
	Insert(5,P);
	Insert(8,P);
	Insert(56,P);
	DeleteMin(P);
	printf("%d\n",P->Ele[10]);
}

int IsFull(PQueue P){
	return P->Size==P->Capacity;	
}

int IsEmpty(PQueue P){
	return P->Size == 0;
}

ElemType Min(ElemType A,ElemType B){
	ElemType Min;
	Min = (A>B)?B:A;
	return Min;
}

PQueue Init(int MaxElems){
	PQueue P;
	P = malloc(sizeof(struct Heap));
	P->Ele = malloc((MaxElems + 1)* sizeof(ElemType));
	P->Capacity = MaxElems;
	P->Size = 0;
	P->Ele[0] = 0; 
	return P;
}

void Insert(ElemType X,PQueue P){
	if(P->Size == P->Capacity){
		printf("ERROER");
	}
	else{
			if(P->Size == 0){
			P->Ele[1] = X;
			P->Size++;
		}		
		else{
			int Tmp,Tmp1;
			Tmp = P->Size+1;
			while(X < P->Ele[Tmp/2]) {
				P->Ele[Tmp] = P->Ele[Tmp/2];
				Tmp = Tmp/2;
			}
			P->Ele[Tmp] = X;
			P->Size++;
		}
	}
}

ElemType DeleteMin(PQueue P){
	ElemType MinTmp = 1;
	int i;
	for(;;){
		if(P->Ele[2*MinTmp]>1000000){
			P->Ele[MinTmp] = P->Ele[P->Size];
			P->Size -= 1;
			break;
		}	
		else{
			P->Ele[MinTmp] = Min(P->Ele[2*MinTmp],P->Ele[2*MinTmp + 1]);
			if(P->Ele[2*MinTmp]<P->Ele[2*MinTmp+1])
				MinTmp = 2*MinTmp;
			else
				MinTmp = 2*MinTmp + 1;

		}
	}
}

void Destory(PQueue P){
	free(P->Ele);
	free(P);
}

void MakeEmpty(PQueue P){
	P->Size = 0;
}
