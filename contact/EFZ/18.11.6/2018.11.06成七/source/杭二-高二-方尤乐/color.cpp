#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define test(x) (!x.empty())
#define SZ(x) ((int)x.size())
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
int read(){
	char c=getchar();int d=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());
	return d*f;
}
const int N=100001;
int n,m,h,t,q[N],w[N],F[N][17]; 
vector<int> c[N],e[N];
vector<PIII> ans;PIII p[N];
void addedge(int x,int y){
	e[x].pb(y);e[y].pb(x);
}
bool mk[N];
int tot,dep[N],dfn[N][2];
bool belong(int x,int y){
	return dfn[x][0]>=dfn[y][0]&&dfn[x][1]<=dfn[y][1];
}
void dfs(int f,int x){
	F[x][0]=f;
	ref(i,1,16)if(F[x][i-1]&&F[F[x][i-1]][i-1])
		F[x][i]=F[F[x][i-1]][i-1];
	dfn[x][0]=++tot;
	ref(i,0,SZ(e[x])-1){
		int y=e[x][i];
		if(y==f)continue;
		dep[y]=dep[x]+1;
		dfs(x,y);
	}
	dfn[x][1]=tot;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	def(i,16,0)if(F[x][i]&&dep[F[x][i]]>=dep[y])x=F[x][i];
	if(x==y)return x;
	def(i,16,0)if(F[x][i]&&F[y][i]&&F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
	return F[x][0];
}
void adddot(int&x,int&y,int&L,int z){
	if(dfn[x][0]<dfn[y][0])swap(x,y);
	if(belong(z,L)&&(belong(x,z)||belong(y,z)))return;
	if(y==L){
		if(belong(z,x))x=z;
		else y=z,L=lca(x,y);
	}else{
		if(belong(z,x))x=z;
		else y=z;
	}
}
int S[N];
void UPD(int x,int s){
	for(;x>=1;x-=x&-x)S[x]+=s;
}
void upd(int x){
	UPD(dfn[x][0]-1,-1);
	UPD(dfn[x][1],1);
}
void Upd(int w){
	mk[w]=1;
	ref(i,0,SZ(c[w])-1) upd(c[w][i]);
	ref(i,0,SZ(c[w])-1) q[++t]=c[w][i];
}
int ASK(int x){int s=0;
	for(;x<=n;x+=x&-x)s+=S[x];return s;
}
int ask(int x){
	return ASK(dfn[x][0]);
}
int Query(PIII p){
	int S=ask(p.fi.fi)+ask(p.fi.se)-ask(p.se)*2+mk[w[p.se]];
	return (dep[p.fi.fi]+dep[p.fi.se]-dep[p.se]*2+1-S);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read(),m=read();
	ref(i,1,n)c[w[i]=read()].pb(i);
	ref(i,2,n)addedge(read(),read());
	dfs(0,1);
	ref(i,1,m)if(test(c[i])){
		if(SZ(c[i])==1){
			ans.pb(mp(mp(c[i][0],c[i][0]),i));
			Upd(i); continue;
		}
		int x=c[i][0],y=c[i][1],L=lca(x,y);
		ref(j,2,SZ(c[i])-1) adddot(x,y,L,c[i][j]);
		if(dep[x]+dep[y]-dep[L]*2+1==SZ(c[i])){
			ans.pb(mp(mp(x,y),i));
			Upd(i); continue;
		}
		p[i]=mp(mp(x,y),L);
	}
	while(h++<t){
		int x=q[h];
		ref(i,0,SZ(e[x])-1){
			int y=e[x][i],wy=w[y];
			if(!mk[wy]&&Query(p[wy])==SZ(c[wy])){
				ans.pb(mp(p[wy].fi,wy));
				Upd(wy); continue;
			}
		}
	}
	ref(i,1,m)if(!mk[i])
		printf("%d %d %d\n",i,1,1);
	def(i,SZ(ans)-1,0){
		int x=ans[i].fi.fi,y=ans[i].fi.se,c=ans[i].se;
		printf("%d %d %d\n",c,x,y);
	}
}