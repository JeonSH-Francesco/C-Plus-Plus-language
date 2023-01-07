
#include<iostream>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, a, max=-2147000000, min=2147000000;
	cin>>n;
	for(i=1; i<=n; i++){
		cin>>a;
		if(a>max) max=a;
		if(a<min) min=a;
	}
	cout<<max-min;
	return 0;
}
