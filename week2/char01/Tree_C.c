#include"Tree_H.h"

int main(){
	SeaTree T;
	T = Create(T, 8); 
	Insert(6, T);
//	printf("%d",T->Right->Ele);
	Insert(5, T);
	Insert(9, T);
	Insert(61, T);
	Insert(7, T);
	Insert(3, T);
	Insert(3, T);
	Insert(4, T);
	Insert(1, T);
	Insert(50, T);
	Insert(70, T);
	Insert(65, T);
	Insert(71, T);
	Insert(51, T);
	Insert(68, T);
	Insert(67, T);
	Insert(69, T);

	printf("最小值为：%d\n",FindMin(T)->Ele);
	printf("最大值为：%d\n",FindMax(T)->Ele);
	
	FindElemWay(51,T);//寻找51这个值的位置，从根节点开始R代表走右子树，L代表走左子树 
	printf("\n"); 
	
//	Delete(69,T);
//	SeaTree P = FindElem(61,T);
//	RotateWithLeft(P);
//	P->Left = P->Left->Right;

	printf("\n");

	printf("前序遍历：");
	PrintTree1(T);
	printf("\n");
	printf("中序遍历：");
	PrintTree2(T);
	printf("\n");
	printf("后序遍历：");
	PrintTree3(T);
}


SeaTree Delete(ElemType X ,SeaTree T){
	Position TmpCell;
	if(X < T->Ele){
		T->Left = Delete(X, T->Left);
	}
	else if(X > T->Ele){
		T->Right = Delete(X, T->Right);
	}
	else if(T->Left && T->Right){
		TmpCell = FindMin(T->Right);
		T->Ele = TmpCell->Ele;
		T->Right = Delete(T->Ele, T->Right);//这一步的操作就是删除目标节点的右子树中最小的元素
											//（最小元素肯定是一个只有一个子结点或没有节点的节点）
											//也就是删除一个只有一个节点或没有节点的节点 
	}
	else{
		TmpCell = T;
		if(T->Left == NULL){
			T = T->Right;
		}
		else if(T->Right == NULL){
			T = T->Left;
		}
		free(TmpCell);
	}
	return T;
} 

Position FindElemWay(ElemType X, SeaTree T){
	if(T->Ele > X){
		printf("L");
		FindElemWay(X, T->Left);
	}
	else if(T->Ele < X){
		printf("R");
		FindElemWay(X, T->Right);
	}
	else if(T->Ele == X){
		return T;
	}	
}

Position FindElem(ElemType X, SeaTree T){
	if(T->Ele > X){
		FindElem(X, T->Left);
	}
	else if(T->Ele < X){
		FindElem(X, T->Right);
	}
	else if(T->Ele == X){
		return T;
	}	
}

Position FindMin(SeaTree T){
	while(T->Left != NULL){
		T = T->Left;
	}
	return T;
}

Position FindMax(SeaTree T){
	while(T->Right != NULL){
		T = T->Right;
	}	
	return T;
}

SeaTree Create(SeaTree T, ElemType X){
	T = malloc(sizeof(struct Node));
	T->Ele = X;
	T->Left = NULL;
	T->Right = NULL;
}

SeaTree Insert(ElemType X, SeaTree T){
	if(T == NULL){
		T = malloc(sizeof(struct Node));
		T->Ele = X;
		T->Left = NULL;
		T->Right = NULL;
		printf("Insert:%d\n");
	}
	else if(X > T->Ele){
		T->Right = Insert(X, T->Right);
	}
	else if(X < T->Ele){
		T->Left = Insert(X, T->Left);
	}
	else if(X == T->Ele){
		printf("已经有 %d 这个元素了\n",X);
	}
	return T;// 为什么一定要有返回值而不是用void？？？我看不懂但我大受震惊 
}

void PrintTree1(SeaTree T){//前序 
	printf("%d ",T->Ele);	
	if(T->Left != NULL){
		PrintTree1(T->Left);
	}
	if(T->Right != NULL){
		PrintTree1(T->Right);
	} 
}

void PrintTree2(SeaTree T){	//中序 
	if(T->Left != NULL){
		PrintTree2(T->Left);
	}
	printf("%d ",T->Ele);
	if(T->Right != NULL){
		PrintTree2(T->Right);
	} 
}

void PrintTree3(SeaTree T){	//后序 
	if(T->Left != NULL){
		PrintTree3(T->Left);
	}
	if(T->Right != NULL){
		PrintTree3(T->Right);
	} 
	printf("%d ",T->Ele);
}
