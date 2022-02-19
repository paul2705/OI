#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=9e5+5;
ll id[MAXN],t[MAXN];
int n,m,q;
int select(int y){
	int c=0;
	for (int i=1<<19;i>0;i>>=1){
		c+=i;
		if (c<=n+m+q&&t[c]<y) y-=t[c];
		else c-=i;
	}
	return c;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n+m+q;i++) t[i]=i&-i;
	for (int i=1;i<=m;i++) id[i]=i;
	for (int i=m+1;i<=m+n;i++) id[i]=(i-m+1LL)*m;
	for (int i=0,x,y;i<q;i++){
		scanf("%d%d",&x,&y);
		int k=select(y)+1;
		printf("%lld\n",id[k]);
		for (int j=k;j<=n+m+q;j+=j&-j) t[j]--;
		id[n+m+i]=id[k];
	}
	return 0;
}
