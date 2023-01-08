#include<stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, tmp, min, i, j;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>0 && a[j+1]<0){
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
input.txt:
8
1 2 3 -3 -2 5 6 -6
*/
