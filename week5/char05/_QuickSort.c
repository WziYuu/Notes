#include<stdio.h>

void QuickSort(int a[],int Beg,int End);
void Prt(int a[],int N);

int main(){
	int a[15] = {9,41,5234,6367,9,312,567,564,5634,784,8154,651,665,16,156};
	QuickSort(a,0,15);
	Prt(a,15);
}

void QuickSort(int a[],int Beg,int End){//每次执行排序的算法 
	if(Beg - End == 1 || Beg - End == 0 || Beg - End == -1){}
	else{
		int N;
		N = End;
		int Center;
		int PreviousCenter;
		
		
		int Tmp[N];
		int k;
		k = N-1;	
		Center = (Beg + End)/2;
		int LeftBgn = 0;		
		int i; 
		for(i = 0; i < N;i ++){
			if(i == Center)
				continue; 
			if(a[i] <= a[Center])
				Tmp[LeftBgn++] = a[i];
			else if(a[i] > a[Center])
				Tmp[k--] = a[i];				
		}
		Tmp[LeftBgn] = a[Center];
		for(i = 0; i < N;i ++){
			a[i] = Tmp[i];
		}
		PreviousCenter = Center; 
		
		QuickSort(a,0,Center);
		QuickSort(a,Center,End);
	}
	
}

void Prt(int a[],int N){
	int i;
	for(i = 0;i < N;i ++){
		printf("%d,",a[i]);
	}
	printf("\n");
}
