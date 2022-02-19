#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int t[MAXN],n,m;
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		add(i,x);
	}
	for (int i=1,op,x,y;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if (op==1) add(x,y);
		else printf("%d\n",sum(y)-sum(x-1));
	}
	return 0;
}
