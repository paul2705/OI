#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n==2)n=2;
		else{
			if(n%2!=0)n=1;
			else n=0;
		}
		printf("%d\n",n);
	}
	return 0;
} 
