#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=5e4+5;
const int MAXP=1e3+5;
int n,m,p;
ll f[3][MAXM],d[MAXN],sv[MAXM];
struct rec{
	int h,t;
	ll val;
} a[MAXM];
int st[MAXM],top;
bool cmp(rec a,rec b){ return a.val<b.val; }
ll calc(ll l,ll r){ return a[r].val*(r-l+1)-(sv[r]-sv[l-1]); }
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=2;i<=n;i++){
		scanf("%lld",&d[i]);
		d[i]+=d[i-1];
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a[i].h,&a[i].t);
		a[i].val=a[i].t-d[a[i].h];
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++) sv[i]=sv[i-1]+a[i].val;

