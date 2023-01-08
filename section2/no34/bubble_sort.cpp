#include <stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, i, j, tmp;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
			tmp=a[j];
			a[j]=a[j+1];
			a[j+1]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}

/*
input.txt의 내용:
7
80 96 75 82 96 92 100
*/
