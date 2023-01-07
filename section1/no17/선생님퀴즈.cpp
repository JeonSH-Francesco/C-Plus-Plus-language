#include <stdio.h>

int main(){
	
	int ans,n,m,i,j,sum=0;//ans는 답, n은 학생수
	//m은 기준이 되는 자연수, i,j는 카운트 루프 변수
	//sum은 합 
	
	freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&m,&ans);
		sum=0;
		for(j=1;j<=m;j++){
			sum+=j;
		} 
		if(ans==sum) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}

/*
input.txt의 내용
3
10 55
20 350
100 5050*/
