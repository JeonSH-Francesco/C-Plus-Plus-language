#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int a[100], n, tmp, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i=1;i<n;i++){
		tmp=a[i];
		for(j=i-1;j>=0;j--){
			if(a[j]>tmp) a[j+1]=a[j];
			else break;
		}
		a[j+1]=tmp;
	}
	
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}
/*
input.txt : 
7
11 7 5 6 10 9 15
*/
