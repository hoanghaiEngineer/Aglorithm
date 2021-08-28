#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Insert Sort
void InsertSort(int a[], int n){
	for(int i = 0; i < n; i ++){
		int j = i;
		int last = a[i];
		
		while((j>0) && (a[j-1]>last)){
			a[j] = a[j-1];
			j = j - 1;
		}
		
		a[j] = last;
	}
}

void ShowArray(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d \t", a[i]);
	}
}
int main(int argc, char** argv) {
	int a[] = {4, 3, 2, 10, 12, 1, 5, 6};
	int n = 8;
	InsertSort(a, n);
	ShowArray(a, n);
	
	return 0;
}
