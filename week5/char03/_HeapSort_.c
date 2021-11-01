#include<stdio.h>

void swap(int a, int b);
void HeapSort(int A[], int N);
void BuildHeap(int A[], int N);
void PrintA(int a[],int N);

int main(){
	int a[9] = {56,2344,34,5,1,523,7,4,2};
	PrintA(a,9);
	BuildHeap(a,9);
	PrintA(a,9);
	int c = 1;
	int b = 2;
//	swap(c,b);
	printf("%d",b);
	

//	printf("%d\n",6%2 == 0);
}



void HeapSort(int A[], int N){
    int StopPos = N;
}

void BuildHeap(int A[], int N){
    int i,Tmp;
    for(;N>0;N--){
    
		for(i = N - 1; i > 0;i--){//构建大顶堆
	        if(i%2 == 0){
	            if(A[i]>A[(i/2)-1]){
	            	Tmp = A[i];
	            	A[i] = A[(i/2)-1];
	            	A[(i/2)-1] = Tmp;
				}
	    	}
			if(i % 2 == 1){
	            if(A[i]>A[(i-1)/2]){
	            	Tmp = A[i];
	            	A[i] = A[(i-1)/2];
	            	A[(i-1)/2] = Tmp;
				} 
	    	}
	    }
	    Tmp = A[0];//交换最大值最小值 
	    A[0] = A[N - 1];
	    A[N - 1] = Tmp;
	}	

}

void PrintA(int a[],int N){
	int i;
	for(i = 0; i<N; i++){
		printf("%d,",a[i]);
	}
	printf("\n");
}
