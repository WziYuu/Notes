# include<stdio.h>

void ShellSort(int a[],int N);

int main(){
	int a[12] = {2,34,645,6,22,4561,3456,432,6,3,5,2};
	ShellSort(a,12);
	int i;
	for (i = 0;i < 12;i++){
		printf("%d,",a[i]);
	}
	
}

void ShellSort(int a[], int N){
	int i, j, Inc;
	int Tmp;
	for(Inc = N/2;Inc > 0;Inc /= 2){
		for(i = Inc;i < N; i += Inc){
			Tmp  = a[i];
			for(j = i;a[j-Inc] > Tmp;j -= Inc){
				a[j] = a[j- Inc];
			}
			a[j] = Tmp; 
		}
	}
}
