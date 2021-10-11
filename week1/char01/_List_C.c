#include"_List_H.h"
int main(){
	List L;
	L = CreateList();
	printf("���Ƿ�Ϊ�գ�%d\n",IsEmpty(L));
	Append(1,L);
	printf("���Ƿ�Ϊ�գ�%d\n",IsEmpty(L));
	Append(2,L);
	Append(3,L);
	Append(4,L);
	Append(5,L);
	printf("�����ڱ�ͷ���1��2��3��4��5��õ���");
	PrintList(L);
	printf("��3�������9�õ���"); 
	Insert(9,L,Find(3,L));
	PrintList(L);
	printf("ɾ��2�õ���");
	Delete(2,L);
	PrintList(L);
	printf("1�Ƿ�Ϊ����β�ڵ㣿%d\n",IsLast(Find(1, L), L));
	printf("3�Ƿ�Ϊ����β�ڵ㣿%d\n",IsLast(Find(3, L), L));
	
	/*
	���Ƿ�Ϊ�գ�                                  1
	���Ƿ�Ϊ�գ�                                  0
	�����ڱ�ͷ���1��2��3��4��5��õ���           5,4,3,2,1,
	��3�������9�õ���                            5,4,3,9,2,1,
	ɾ��2�õ���                                   5,4,3,9,1,
	1�Ƿ�Ϊ����β�ڵ㣿                           1
	3�Ƿ�Ϊ����β�ڵ㣿                           0
	*/
} 

void PrintList(List L){
	List TMP;
	TMP = L->Next;
	while(TMP != NULL){
		printf("%d,",TMP->Ele);		
		TMP = TMP->Next;
	}
	printf("\n");
}

List CreateList(){
	List L;
	L = malloc(sizeof(struct Node));
	if(L == NULL){
		printf("ERROR");
	}
	else{
	L->Next = NULL;
	}
	return L; 
}

int IsEmpty(List L){
	return L->Next == NULL;
}

void Append(ElementType X, List L){
	List N;
	N = malloc(sizeof(struct Node));
		N->Next = L->Next;
		L->Next = N;
		N->Ele = X;
}

Position Find(ElementType X, List L){
	while(L->Next->Ele != X){
		L = L->Next;
	}
	return L->Next;
}

void Insert(ElementType X, List L, Position P){// ������P�ĺ� 
	Position TMP;
	TMP = malloc(sizeof(struct Node));
	TMP->Next = P->Next;
	P->Next = TMP;
	TMP->Ele = X;
}

Position FindPrevious(ElementType X, List L){
	List TMP;
	TMP = L;
	while(TMP->Next->Ele != X){//���ҵ�һ���ڵ����һ���ڵ��Ele��X��ͬ��ʱ�򷵻ص�ǰ�ڵ� 
		TMP = TMP->Next;
	}
	return TMP;
}

void Delete(ElementType X, List L){
	Position TMP;
	TMP = FindPrevious(2,L)->Next;// ������Ҫɾ���Ľڵ�ĵ�ַ������Ҫ�ã�����ֱ���ͷŸõ�ַ 
	FindPrevious(2,L)->Next = FindPrevious(2,L)->Next->Next;// ��Ҫɾ���Ľڵ����һ���ڵ��Nextָ��ָ��Ҫɾ���Ľڵ����һ����ַ 
	free(TMP);
}

int IsLast(Position P,List L){
	return P->Next == NULL;
}

Position Header(List L){
	return L;
}

Position First(List L){
	return L->Next;
}
 
