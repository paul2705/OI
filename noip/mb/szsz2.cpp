#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll a[MAXN],t[MAXN];
int n,m;
void add(int x,ll val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
ll sum(int x){
	ll ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1,op;i<=m;i++){
		scanf("%d",&op);
		if (op==1){
			int x,y; ll k;
			scanf("%d%d%lld",&x,&y,&k);
			add(x,k); add(y+1,-k);
		}
		else {
			int x;
			scanf("%d",&x);
			printf("%lld\n",sum(x)+a[x]);
		}
	}
	return 0;
}
