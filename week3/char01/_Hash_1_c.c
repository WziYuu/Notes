#include"_Hash_1_H.h"

int main() {
	HashTbl H;
	H = Init(100);
	Insert("wziyuu",H);
	Insert("wzy",H);
	Insert("wwzzyy",H);
	Find("wzy",H);
	Find("wwzzyy",H);
	Find("wziyuu",H);
	printf("wzy��%d\n",Hash("wzy",100));


	DestoryTable(H);
}

HashTbl Init(int Tablesize){
	HashTbl H;
	H = malloc(sizeof(struct HashTable));
	H->TableSize = Tablesize;
	H->TheList = malloc(Tablesize*sizeof(struct ListNode));
	int i;
	for(i = 0; i < Tablesize; i++){
		H->TheList[i] = malloc(sizeof(struct ListNode));
		H->TheList[i]->Next = NULL;
		//TheList�е�i���Ƕ�Ӧ��ɢ��ֵ�� TheList�е�Elem�����洢��Ӧ��Ԫ��ֵ 
	}
	return H;
}

Position Find(Key X, HashTbl H){
	Position P;
	P = H->TheList[Hash(X, H->TableSize)]->Next;
	while(P->Elem != X){
		P = P->Next;
	}
	printf("Find:%9s��Location��%d\n",X,P);
	return P;
}

void Insert(Key X, HashTbl H){
	Position New;
	Position Tmp;
	int i = Hash(X, H->TableSize);
	New = malloc(sizeof(struct ListNode));
	printf("i:%d\n",i);
	Tmp = H->TheList[i];
	New->Next = Tmp->Next;
	Tmp->Next = New;//���뵽����ͷ�� 	
	New->Elem = X;
	printf("Insert��%5s��Location��%d\n",X,Tmp->Next);
//	while(New->Next != NULL){
//		New = New->Next; 
//	} 
//	New->Elem = X;//���뵽����β�� 
}

void DestoryTable(HashTbl H){
	int i;
	for(i = 0; i < H->TableSize; i++){
		free(H->TheList[i]);
	}
	free(H);
}
