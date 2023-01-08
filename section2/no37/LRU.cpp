#include <stdio.h>

int C[20];

int main(){
	//freopen("input.txt","rt",stdin);
	/*5 9
	1 2 3 2 6 2 3 5 7*/
	int s,n,a,i,j,pos; //캐시의 사이즈, 작업 개수, LRU 변수, 루프변수
	printf("========Least Recently Used========\n");
	printf("Cache Size : "); 
	scanf("%d",&s);
	
	printf("Process Count : ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		printf("pid : ");
		scanf("%d",&a);
		pos=-1;

		for(j=0; j<s; j++) if(C[j]==a) pos=j;
		
		if(pos==-1){
			for(j=s-1; j>=1; j--) C[j]=C[j-1];
		}//Cache Miss
		
		else{
			for(j=pos; j>=1; j--) C[j]=C[j-1];
		}//Cache Hit
		
		C[j]=a;
	}
	for(i=0; i<s; i++) printf("%d ", C[i]);
	return 0;
}
/*
Cache Size : 5 
Process Count : 9
pid : 1 2 3 2 6 2 3 5 7
*/
