#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e6+5;
const int MAXM=1e6+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,rd[MAXN];
ll m,a[MAXN],ans[MAXN];
queue<int> q;
ll nn,cnt[MAXN*2],b[MAXN],c[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	rd[v]++;
}
void solve1(){
	for (int i=1;i<=n;i++) ans[i]=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[j]%a[i]==0) add(i,j);
		}
	}
	ans[1]=1; q.push(1);
	for (int i=2;i<=n;i++){
		if (rd[i]==0) q.push(i);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			ans[v]=(ans[v]+ans[u])%mod; rd[v]--;
			if (rd[v]==0) q.push(v);
		}
	}
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
int find(int l,int r,ll x){
	int mid; l--;
	while (l+1<r){
		mid=(l+r)>>1;
		if (b[mid]>=x) r=mid;
		else l=mid;
	}
	return r;
}
void solve2(){
	for (int i=1;i<=n;i++) ans[i]=0;
	ans[1]=1; cnt[c[1]]=(cnt[c[1]]+ans[1])%mod;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=c[i];j++){
			if (a[i]%b[j]==0) ans[i]=(ans[i]+cnt[j])%mod;
		}
		cnt[c[i]]=(cnt[c[i]]+ans[i])%mod;
	}
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
void solve3(){
	for (int i=1;i<=n;i++) ans[i]=0;
	ans[1]=1; cnt[c[1]]=(cnt[c[1]]+ans[1])%mod;
	for (int i=2;i<=n;i++){
		int l=1,r=c[i];
		for (;l<=c[i];l++){
			if (b[l]*b[l]>=a[i]) break;
		}
		for (int j=1;j<=c[i]&&b[j]*b[j]<=a[i];j++){
			if (a[i]%b[j]==0){
				ans[i]=(ans[i]+cnt[j])%mod;
				int pos=find(l,r,a[i]/b[j]);
				if (pos==j||(a[i]/b[j]!=b[pos])) continue;
				ans[i]=(ans[i]+cnt[pos])%mod;
				r=pos;
			}
		}
		cnt[c[i]]=(cnt[c[i]]+ans[i])%mod;
	}
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
int main(){
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		c[i]=lower_bound(b+1,b+nn+1,a[i])-b;
	}
//	solve3();
	if (n<=1000) solve1();
	else if (n*nn<=1e7) solve2();
	else solve3();
	return 0;
}
