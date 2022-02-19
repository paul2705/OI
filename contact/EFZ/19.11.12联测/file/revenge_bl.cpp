#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=2e4+5;
const int MAXM=MAXN*2;
const int MAXS=(1<<9)+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int cnt[15],d[MAXN],ans[MAXN];
int n,m,col[MAXN];
bool stp[MAXN];
int fa[MAXN][25],st[MAXN][25];
int g[MAXN][MAXS];
bitset<10> t;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u][0]=p; st[u][0]=(1<<col[u]);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<=20;k++){
		for (int i=1;i<=n;i++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
			st[i][k]=st[i][k-1]|st[fa[i][k-1]][k-1];
//			cout<<i<<" "<<k<<" "<<st[i][k]<<endl;
		}
	}
}
struct rec{
	int f,st;
};
rec lca(int x,int y){
	rec tmp; tmp.f=0; tmp.st=0;
	if (d[x]<d[y]) swap(x,y);
	for (int k=20;k>=0;k--){
		if (d[fa[x][k]]>d[y]){
			tmp.st|=st[x][k];
			x=fa[x][k];
		}
	}
	if (d[x]>d[y]){
		tmp.st|=st[x][0]; x=fa[x][0];
	}
	if (x==y){
		tmp.f=x; tmp.st|=st[x][0];
		return tmp;
	}
	for (int k=20;k>=0;k--){
		if (fa[x][k]!=fa[y][k]){
			tmp.st|=st[x][k]|st[y][k];
			x=fa[x][k]; y=fa[y][k];
		}
	}
	if (x!=y){
		tmp.st|=st[x][0]|st[y][0];
		x=fa[x][0];
		tmp.f=x; tmp.st|=st[x][0];
		return tmp;
	}
	tmp.f=x; tmp.st|=st[x][0];
	return tmp;
}
void solve1(){
	dfs(1,0); ini();
	int ans=n+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			rec tmp=lca(i,j);
			t=tmp.st;
//			cout<<t<<" "<<i<<" "<<j<<endl;
			if (tmp.st==(1<<m)-1) ans=min(ans,d[i]+d[j]-2*d[tmp.f]+1);
		}
	}
	printf("%d\n",ans==n+1?-1:ans);
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs2(v,u);
	}
	int tmp=(1<<col[u]);
	for (int s=0;s<(1<<m);s++) g[u][s]=n+1;
	g[u][tmp]=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		for (int s1=0;s1<(1<<m);s1++){
			for (int s2=0;s2<(1<<m);s2++){
				if ((s1|s2|tmp)==(1<<m)-1){
//					cout<<(s1|s2|tmp)<<" "<<(1<<m)-1<<endl;
					int T=ans[u];
					ans[u]=min(ans[u],g[u][s1]+g[v][s2]+1);
//					if (ans[u]==1&&T!=1){
//					cout<<(s1|s2|tmp)<<" "<<(1<<m)-1<<" ";
//					t=(1<<m)-1; cout<<t<<" ";
//					t=s1; cout<<t<<" ";
//					t=tmp; cout<<t<<" ";
//					t=s2; cout<<t<<" "<<u<<" "<<g[u][s1]<<" "<<g[v][s2]<<" "<<1<<" "<<ans[u]<<" "<<tmp<<endl;
//					}
				}
			}
			g[u][s1|tmp]=min(g[u][s1|tmp],g[v][s1]+1);
		}
	}
//	for (int s=0;s<(1<<m);s++){
//		t=s; cout<<"id:"<<u<<" st:"<<t<<" ans:"<<g[u][s]<<endl;
//	}
}
void solve2(){
	for (int i=1;i<=n;i++) ans[i]=n+1;
	dfs2(1,0);
	int ret=n+1;
	for (int i=1;i<=n;i++){
		ret=min(ret,ans[i]+1);
	}
	printf("%d\n",ret>=n+1?-1:ret);
}
int main(){
	freopen("revenge.in","r",stdin);
	freopen("revenge.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&col[i]),col[i]--;
//	if (n>5005) solve2();
//	else solve1();
	solve1();
	fclose(stdin); fclose(stdout);
	return 0;
}
