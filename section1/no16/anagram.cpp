#include<stdio.h>
#include<algorithm>
int a[53], b[53];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i;
	char str[100];
	scanf("%s", &str);
	
	for(i=0; str[i]!='\0'; i++){
		if(str[i]>=65 && str[i]<=90)
			a[str[i]-64]++; //64를 차감해야 첫번쨰 배열 원소 
		else a[str[i]-70]++;//70을 차감해야 27번째 배열 원소 
		printf("%c",str[i]);
	}
	printf("\n");
	scanf("%s", &str);
	for(i=0; str[i]!='\0'; i++){
		if(str[i]>=65 && str[i]<=90)
			b[str[i]-64]++;
		else b[str[i]-70]++;
		printf("%c",str[i]);
	}
	
	for(i=1; i<=52; i++){
		if(a[i]!=b[i]){
			printf("\nNO\n");
			exit(0);
		}
	}
	printf("\nYES\n");	
	return 0;
}
