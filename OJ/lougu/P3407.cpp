#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const ll INF=1e18;
int ans[MAXN],x[MAXN],dir[MAXN];
int n,t,q;
int gett(int lx,int ld,int x,int d){
	if (ld==d) return INF;
	else return (x-lx)>>1;
}
int getx(int x,int d,int t){
	return x+d*t;
}
int main(){
	scanf("%d%d%d",&n,&t,&q);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&dir[i]),dir[i]-=2;
	for (int i=1;i<=n;i++){
		int lt=gett(x[i-1],dir[i-1],x[i],dir[i]);
		int lx=getx(x[i],dir[i],lt);
		int rt=gett(x[i],dir[i],x[i+1],dir[i+1]);
		int rx=getx(x[i],dir[i],rt);
		if (lt<rt){
			if (t<lt) ans[i]=getx(x[i],dir[i],t);
			else ans[i]=lx;
		}
		else if (t<rt) ans[i]=getx(x[i],dir[i],t);
			else ans[i]=rx;
	}
	for (int i=0,x;i<q;i++){
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
