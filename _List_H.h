#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node{
	ElementType Ele;
	Position Next;
};

List CreateList();
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L); 
void PrintList(List L);
void Append(ElementType X, List L);// 1->2->3¼Ó³É4->1->2->3


