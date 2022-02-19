#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=2e3+5;
const int MAXM=14;
vector<int> g[MAXN];
vector<int> c[MAXM];
int szg[MAXN],szc[MAXM];
int n,T,m;
int sam[MAXM][MAXM];
ll C[MAXN][MAXN];
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
void dfs1(int u,int p){
	szc[u]=1;
	for (int i=0;i<c[u].size();i++){
		int v=c[u][i];
		if (v==p) continue;
		dfs1(v,u);
		szc[u]+=szc[v];
	}
}
void dfs2(int u,int p){
	szg[u]=1;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==p) continue;
		dfs2(v,u);
		szg[u]+=szg[v];
	}
}
bool cmp_c(int a,int b){ return szc[a]<szc[b]; }
bool cmp_g(int a,int b){ return szg[a]<szg[b]; } 
bool same(int u1,int p1,int u2,int p2){
	if (c[u1].size()!=c[u2].size()) return 0;
	if (c[u1].size()==0) return 1;
	if (sam[u1][u2]>-1) return sam[u1][u2];
	sort(c[u1].begin(),c[u1].end(),cmp_c);
	sort(c[u2].begin(),c[u2].end(),cmp_c);
	int st=0,sz=c[u1].size();
	for (int i=0;i<sz;i++){
		int nst=0,v=c[u1][i];
		for (int j=0;j<sz;j++){
			int nv=c[u2][j];
			if (same(v,u1,nv,u2)) nst=(nst<<1)+1;
			else nst<<=1;
		}
		st|=nst;
	}
	if (st==((1<<sz)-1)) return sam[u1][u2]=1;
	else return sam[u1][u2]=0;
}
ll dfs(int cu,int cp,int gu,int gp){
	if (c[cu].size()==1&&cp!=0) return 1;
//	if (g[gu].size()==1&&gp!=0) return 0;
//	cout<<__func__<<" "<<cu<<" "<<cp<<" "<<gu<<" "<<gp<<endl;
	sort(c[cu].begin(),c[cu].end(),cmp_c);
//	sort(g[gu].begin(),g[gu].end(),cmp_g);
	int sz=c[cu].size(),LL=0;
	ll cnt[sz+5];
	for (int i=0;i<sz;i++) cnt[i]=1;
	for (int l=0,r=0;l<sz;l=r+1,r++){
		while (r+1<sz&&szc[c[cu][l]]==szc[c[cu][r+1]]) r++;
		for (int i=l;i<=r;i++){
			if (c[cu][i]==cp) continue;
			if (!cnt[i]) continue;
			for (int j=l;j<=r;j++){
				if (i==j) continue;
				if (c[cu][j]==cp) continue;
				if (same(c[cu][i],cu,c[cu][j],cu)){
					cnt[i]=(cnt[i]+cnt[j])%mod;
					cnt[j]=0;
				}
			}
		}
	}
	ll lis[sz+5];
	for (int i=0;i<sz;i++) lis[i]=0;
/*	for (int l=0,r=0;l<sz;l=r+1,r++){
		while (r+1<sz&&szc[c[cu][l]]==szc[c[cu][r+1]]) r++;
		for (;LL<g[gu].size();LL++){
			int v=g[gu][LL];
			if (v==gp) continue;
			if (szg[v]==szg[c[cu][l]]){
				for (int i=l;i<=r;i++){
					if (c[cu][i]==cp) continue;
					if (!cnt[i]) continue;
					lis[i]=(lis[i]+dfs(c[cu][i],cu,v,gu))%mod;
				}
			}
			else { LL++; break; }
		}
	}*/
	for (int j=0;j<c[cu].size();j++){
		if (!cnt[j]||c[cu][j]==cp) continue;
		for (int i=0;i<g[gu].size();i++){
			int v=g[gu][i];
			if (v==gp) continue;
			lis[j]=(lis[j]+dfs(c[cu][i],cu,v,gu))%mod;
		}
	}
//	cout<<"fuck"<<endl;
	ll ret=1;
	for (int i=0;i<sz;i++){
		if (c[cu][i]==cp) continue;
//		cout<<i<<" "<<cnt[i]<<" "<<lis[i]<<endl;
		ret=ret*C[lis[i]][cnt[i]]%mod;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d",&T);
	while (T--){
		scanf("%d",&m);
		for (int i=1;i<=m;i++) c[i].clear();
		for (int i=1;i<m;i++){
			int u,v; scanf("%d%d",&u,&v);
			c[u].push_back(v);
			c[v].push_back(u);
		}
		ll ans=0;
		for (int i=1;i<=m;i++){
//			cout<<i<<"begin: "<<endl;
			for (int j=1;j<=m;j++){
				for (int k=1;k<=m;k++) sam[j][k]=-1;
				sam[j][j]=1;
			}
			for (int j=1;j<=n;j++){
				dfs1(i,0); dfs2(j,0);
				ans=(ans+dfs(i,0,j,0));
//				cout<<i<<" "<<j<<" "<<ans<<endl;
			}
//			cout<<"end; "<<endl;
		}
		ll inv=mod_pow(m,mod-2);
		printf("%lld\n",ans*inv%mod*inv%mod);
	}
	return 0;
}

