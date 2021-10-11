#include"_List_H.h"
int main(){
	List L;
	L = CreateList();
	printf("表是否为空？%d\n",IsEmpty(L));
	Append(1,L);
	printf("表是否为空？%d\n",IsEmpty(L));
	Append(2,L);
	Append(3,L);
	Append(4,L);
	Append(5,L);
	printf("依次在表头添加1，2，3，4，5后得到：");
	PrintList(L);
	printf("在3后面插入9得到："); 
	Insert(9,L,Find(3,L));
	PrintList(L);
	printf("删除2得到：");
	Delete(2,L);
	PrintList(L);
	printf("1是否为链表尾节点？%d\n",IsLast(Find(1, L), L));
	printf("3是否为链表尾节点？%d\n",IsLast(Find(3, L), L));
	
	/*
	表是否为空？                                  1
	表是否为空？                                  0
	依次在表头添加1，2，3，4，5后得到：           5,4,3,2,1,
	在3后面插入9得到：                            5,4,3,9,2,1,
	删除2得到：                                   5,4,3,9,1,
	1是否为链表尾节点？                           1
	3是否为链表尾节点？                           0
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

void Insert(ElementType X, List L, Position P){// 插入在P的后方 
	Position TMP;
	TMP = malloc(sizeof(struct Node));
	TMP->Next = P->Next;
	P->Next = TMP;
	TMP->Ele = X;
}

Position FindPrevious(ElementType X, List L){
	List TMP;
	TMP = L;
	while(TMP->Next->Ele != X){//当找到一个节点的下一个节点的Ele与X相同的时候返回当前节点 
		TMP = TMP->Next;
	}
	return TMP;
}

void Delete(ElementType X, List L){
	Position TMP;
	TMP = FindPrevious(2,L)->Next;// 先留存要删除的节点的地址，后面要用，不能直接释放该地址 
	FindPrevious(2,L)->Next = FindPrevious(2,L)->Next->Next;// 将要删除的节点的上一个节点的Next指针指向要删除的节点的下一个地址 
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
 
