#include<stdio.h>

void InsertSort(int a[], int N);

int main(){
	int a[12] = {2,34,645,6,22,4561,3456,432,6,3,5,2};
	InsertSort(a, 12);
	int i;
	for (i = 0;i < 12;i++){
		printf("%d,",a[i]);
	}
} 

void InsertSort(int a[],int N){
	int i, j, k;
	for(i = 0; i < N; i++){
		k = a[i];
		for(j = i;a[j - 1] > k;j--){
			a[j] = a[j - 1];
		}
		a[j] = k;
	}
}
