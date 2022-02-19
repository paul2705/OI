#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	int cnt=0,opt=0;
	scanf("%d",&n);
	while (cnt<n*n){
		int tmp; scanf("%d",&tmp);
		for (int j=1;j<=tmp;j++){
			printf("%d",opt);
			cnt++;
			if (cnt%n==0) printf("\n");
		}
		opt^=1;
	}
	return 0;
}
