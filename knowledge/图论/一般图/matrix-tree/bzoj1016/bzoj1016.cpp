#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=2e3+5;
const int mod=31011;
struct rec{
	int u,v,w;
} ed[MAXM];
int cnt[MAXM];
int n,m,tot,ans,sum;
int fa[MAXN];
bool use[MAXM];
bool cmp(rec a,rec b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
void dfs(int stp,int l,int r,int now,int cnt){
	if (now==r+1){
//		cout<<stp<<" "<<cnt<<endl;
		if (stp==cnt) sum=(sum+1)%mod;
		return;
	}
	int u=ed[now].u,v=ed[now].v;
	int fu=find(u),fv=find(v);
	if (fu!=fv){
		fa[fu]=fv;
		dfs(stp+1,l,r,now+1,cnt);
		fa[fu]=fu; fa[fv]=fv;
	}
	dfs(stp,l,r,now+1,cnt);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ed[i]=(rec){u,v,w};
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(ed+1,ed+m+1,cmp);
	int res=0;
	for (int i=1;i<=m;i++){
		if (ed[i].w!=ed[i-1].w) res++;
		int u=ed[i].u,v=ed[i].v;
		if (find(u)==find(v)) continue;
		cnt[res]++; uion(u,v); tot++;
	}
	if (tot!=n-1) return printf("0\n"),0;
	for (int i=1;i<=n;i++) fa[i]=i;
	ans=res=1;
	for (int l=1,r=1;l<=m;l=r+1,r++,res++){
		while (ed[l].w==ed[r].w) r++;
		r--; sum=0;
		dfs(0,l,r,l,cnt[res]);
//		cout<<l<<" "<<r<<" "<<cnt[res]<<" "<<sum<<endl;
		ans=ans*sum%mod;
		for (int i=l;i<=r;i++){
			int u=ed[i].u,v=ed[i].v;
			if (find(u)==find(v)) continue;
			uion(u,v);
		}
	}
	printf("%d\n",ans);
	return 0;
}
