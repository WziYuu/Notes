#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *Position;
typedef struct Node *SeaTree;
typedef int ElemType;

SeaTree Insert(ElemType X, SeaTree T);
SeaTree Delete(ElemType X, SeaTree T);
SeaTree Create(SeaTree T, ElemType X);
void PrintTree1(SeaTree T);
void PrintTree2(SeaTree T);
void PrintTree3(SeaTree T);
Position FindMin(SeaTree T); 
Position FindMax(SeaTree T);
Position FindElemWay(ElemType X, SeaTree T);
Position FindElem(ElemType X, SeaTree T);
SeaTree RotateWithLeft(SeaTree T);

struct Node{
	ElemType Ele;
	SeaTree Left;
	SeaTree Right;
};

int TmpArr[100];//临时数组存放寻找父节点过程中经过的节点。 
