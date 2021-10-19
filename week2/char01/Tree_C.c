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

	printf("��СֵΪ��%d\n",FindMin(T)->Ele);
	printf("���ֵΪ��%d\n",FindMax(T)->Ele);
	
	FindElemWay(51,T);//Ѱ��51���ֵ��λ�ã��Ӹ��ڵ㿪ʼR��������������L������������ 
	printf("\n"); 
	
//	Delete(69,T);
//	SeaTree P = FindElem(61,T);
//	RotateWithLeft(P);
//	P->Left = P->Left->Right;

	printf("\n");

	printf("ǰ�������");
	PrintTree1(T);
	printf("\n");
	printf("���������");
	PrintTree2(T);
	printf("\n");
	printf("���������");
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
		T->Right = Delete(T->Ele, T->Right);//��һ���Ĳ�������ɾ��Ŀ��ڵ������������С��Ԫ��
											//����СԪ�ؿ϶���һ��ֻ��һ���ӽ���û�нڵ�Ľڵ㣩
											//Ҳ����ɾ��һ��ֻ��һ���ڵ��û�нڵ�Ľڵ� 
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
		printf("�Ѿ��� %d ���Ԫ����\n",X);
	}
	return T;// Ϊʲôһ��Ҫ�з���ֵ��������void�������ҿ��������Ҵ����� 
}

void PrintTree1(SeaTree T){//ǰ�� 
	printf("%d ",T->Ele);	
	if(T->Left != NULL){
		PrintTree1(T->Left);
	}
	if(T->Right != NULL){
		PrintTree1(T->Right);
	} 
}

void PrintTree2(SeaTree T){	//���� 
	if(T->Left != NULL){
		PrintTree2(T->Left);
	}
	printf("%d ",T->Ele);
	if(T->Right != NULL){
		PrintTree2(T->Right);
	} 
}

void PrintTree3(SeaTree T){	//���� 
	if(T->Left != NULL){
		PrintTree3(T->Left);
	}
	if(T->Right != NULL){
		PrintTree3(T->Right);
	} 
	printf("%d ",T->Ele);
}
