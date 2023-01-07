#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
	char array[20];
	int year, age, det;
	
	struct tm* t;
	time_t base=time(NULL); // base = 0일 때 1970년 1월1일로 계산
	// base=time(NULL)일 때 현재 날짜기준으로 구해짐. 
	t=localtime(&base);
	
	scanf("%s",&array);
	if(array[7]=='1'|| array[7]=='2'){
		year=1900+((array[0]-48)*10+(array[1]-48));
		det=1;
	}
	else {
		year=2000+((array[0]-48)*10+(array[1]-48));
		det=0;
	}
	
	age=t->tm_year+1900-year+1;
	
	printf("%d",age);
	if(det==1){
		printf(" M\n");
	}
	else {
		printf(" W\n");
	}
	
	return 0;
}
