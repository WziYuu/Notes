#include<stdio.h>
#include<stdlib.h>

void MSort(int A[], int Tmp[], int Left, int Right);
void MergeSort(int A[], int N);
void Merge(int a[], int Tmp[], int Lpos, int Rpos, int RightEnd);
void printA(int A[],int N);
int a[9];
int MS1 = 0;
int MS2 = 0;
int ME = 0; 
int i;

int main(){
	int a[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int b[14] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int c[9] = {99,88,77,66,55,44,33,22,11};
	int d[10] = {3,4554,456,534,2,4,3426,43,6,56};
	MergeSort(d,10);
//	MergeSort(c,9);
//	printA(c,9);
//	printf("%d",sizeof(b)/sizeof(int));
//	MergeSort(a,15);
//	printA(a,15);
//	MergeSort(b,14);
//	printA(b,14);
}

void MSort(int A[], int Tmp[], int Left, int Right){
	int Center;
	
	

	if(Left < Right){
		
		
		Center = (Left + Right)/2;
		for(i=0;i<MS1;i++)
			printf("\t");
		MS1++;
		
		printf("准备进入第%d层MS1。。。MS1.Left=%d;MS1.Right=%d;MS1.Center=%d\n\n",MS1,Left,Right,Center); 
		MSort(A,Tmp,Left,Center);
		for(i=0;i<MS1-1;i++)
			printf("\t");
		printf("退出第%d层MS1。。。MS1.Left=%d;MS1.Right=%d;MS1.Center=%d\n\n\n",MS1,Left,Right,Center);
		MS1--; 
		
		for(i=0;i<MS2;i++)
			printf("\t");
		for(i=0;i<MS1;i++)
		printf("\t");
		MS2++;
		
		printf("准备进入第%d层MS2。。。MS1=%d层,MS2.Left=%d;MS2.Right=%d;MS2.Center=%d\n\n",MS2,MS1,Center+1,Right,Center); 
		MSort(A,Tmp,Center + 1,Right);
		for(i=0;i<MS2-1;i++)
			printf("\t");
		for(i=0;i<MS1;i++)
		printf("\t");
		printf("退出第%d层MS2,MS1=%d。。。MS2.Left=%d;MS2.Right=%d;MS2.Center=%d\n\n\n",MS2,MS1,Left,Right,Center);
		MS2--;
//		printf("---------准备进入Mrege。。。Left=%d;Center+1=%d;Right=%d\n\n",Left,Center+1,Right); 
		Merge(A,Tmp,Left,Center + 1,Right);
		puts("退出Merge。。。\n\n");
		
		
	}
	
}

void MergeSort(int A[], int N){
	int *Tmp;
	Tmp = malloc(N*sizeof(int));
	if(Tmp != NULL){
		MSort(A,Tmp,0,N-1);
	}else{
		puts("err");
	}
}

void Merge(int A[], int Tmp[], int Lpos, int Rpos, int RightEnd){
	printf("------------准备进入Merge...Lpos = %d, Rpos = %d, RightEnd = %d\n",Lpos,Rpos,RightEnd);
	int i, LeftEnd, NumEles, TmpPos;//
	/*
	需要两个变量来依次遍历两个需要比较的数组， 
	Lpos Rpos 是本次遍历的左右起点位置 
	LeftEnd RightEnd 是遍历结束的位置
	TmpPos是临时数组中用来存比较大的元素的位置。 
	*/ 
	LeftEnd = Rpos - 1; 
	TmpPos = Lpos;
	NumEles = RightEnd - Lpos +1;
	int jud = Lpos <= LeftEnd && Rpos <= RightEnd;
	while(Lpos <= LeftEnd && Rpos <= RightEnd )
		if(A[Lpos] <= A[Rpos])
			Tmp[TmpPos++] = A[Lpos++];
		else
			Tmp[TmpPos++] = A[Rpos++];
			
	while(Lpos <= LeftEnd )
		Tmp[TmpPos++] = A[Lpos++];
	while(Rpos <= RightEnd)
		Tmp[TmpPos++] = A[Rpos++]; 
		
	for (i = 0;i< NumEles; i++,RightEnd--)
		A[RightEnd] = Tmp[RightEnd];
	printA(A,10);
//	printf("size of A:%d\n",sizeof(A));
}
//	int d[10] = {3,4554,456,534,2,4,3426,43,6,56};
void printA(int A[], int N){
	int i;
	for(i = 0;i< N; i ++){
		printf("%d,",A[i]);
	}
	printf("\n");
}

