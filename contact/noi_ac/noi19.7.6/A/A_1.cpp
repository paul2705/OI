#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=5e4+5;
const int MAXP=1e3+5;
ll f[3][MAXM];
int n,m,p;
ll d[MAXN],sv[MAXM];
struct rec{
	int h,t;
	ll val;
} a[MAXN];
bool cmp(rec a,rec b){ return a.val<b.val; }
ll calc(ll l,ll r){ return (r-l+1)*a[r].val-(sv[r]-sv[l-1]); }
void solve(int c,int l,int r,int dl,int dr){
	int o=c^1;
	if (l>r) return;
	int mid=(l+r)>>1;
	ll ret=1e15,pos=-1;
	for (int i=dl;i<=min(mid-1,dr);i++){
		ll tmp=f[o][i]+calc(i+1,mid);
		if (ret>tmp){
			ret=tmp;
			pos=i;
		}
	}
	f[c][mid]=ret;
	solve(c,l,mid-1,dl,pos);
	solve(c,mid+1,r,pos,dr);
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for (int i=2;i<=n;i++){
		scanf("%lld",&d[i]);
		d[i]+=d[i-1];
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a[i].h,&a[i].t);
		a[i].val=a[i].t-d[a[i].h];
	}
//	for (int i=0;i<=p;i++){
	for (int j=0;j<=m;j++) f[0][j]=1e15;
	f[0][0]=0;
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++) sv[i]=sv[i-1]+a[i].val;
	for (int i=1;i<=p;i++){
		for (int j=0;j<=m;j++) f[i&1][j]=1e18;
		solve(i&1,1,m,0,m);
	}
	printf("%lld\n",f[p&1][m]);
	fclose(stdin); fclose(stdout);
	return 0;
}
