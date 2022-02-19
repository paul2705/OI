#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1,x,s;i<=k;i++){
		s=0; scanf("%d",&x);
		for (int j=0,a;j<x;j++) scanf("%d",&a),s+=a;
		printf("%d\n",s%(n+1)+1);
	}
	return 0;
}
