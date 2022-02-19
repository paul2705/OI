#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=7e5+5;
int t[MAXN];
int n;
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int select(int x){
	int c=0;
	for (int k=20;k>=0;k--){
		c+=(1<<k);
		if (c<=n&&t[c]<=x) x-=t[c];
		else c-=(1<<k);
	}
	return c;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) t[i]=i&-i;
	int s=0;
	for (int i=0,x;i<n;i++){
		scanf("%d",&x);
		s+=x; s%=(n-i);
		int p=select(s);
		printf("%d\n",p+1);
		add(p+1,-1);
	}
	return 0;
}
