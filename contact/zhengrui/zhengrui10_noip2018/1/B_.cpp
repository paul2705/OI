#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=100008;
int n;
struct node{
	int f,c,d,a;
	int fa,from,from2;
	bool many;
}a[N];
int nume,head[N];
struct edge{
	int to,nxt,f;
	edge(int x=0,int y=0,int z=0){to=x,nxt=y,f=z;}
}e[N<<1];
inline void add_edge(int x,int y,int z)
{
	e[++nume]=edge(y,head[x],z);head[x]=nume;
}
int ind[N];
bool vis[N],used[N],ins[N],cir[N];
int sta[N],ta,q[N],num;
inline void dfs(int x){
	vis[x]=1;
	sta[++ta]=x;
	ins[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(e[i].f>0){
			if(a[x].c==a[a[y].from].c){
				a[y].many=1;
			}
			else if(a[x].c<a[a[y].from].c||!a[y].from){
				a[y].from2=a[y].from;
				a[y].from=x;
				a[y].many=0;
			}
			else if(a[x].c<a[a[y].from2].c||!a[y].from2){
				a[y].from2=x;
			}
		}
		if(!vis[y]){
			dfs(y);
		}
	}
}
inline void dfs2(int x){
	//cout<<x<<'\n';
	used[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].f>0){
			if(used[e[i].to]){
				if(!ins[e[i].to]) continue;
				cir[e[i].to]=1;
				q[++num]=e[i].to;
				int t=x;
				while(t!=e[i].to){
					cir[t]=1;
					q[++num]=t;
					t=a[t].fa;
				}
			}
			else{
				a[e[i].to].fa=x;
				dfs2(e[i].to);
			}
		}
	}
	ins[x]=0;
}
int t;
LL ans,tmp;
inline void solve(int x){
	ta=num=0;
	dfs(x);
	t=ta;
	while(t>0){
		if(!used[sta[t]]){
			dfs2(sta[t]);
		}
		--t;
	}
	tmp=0;
	bool flag=0;
	t=1e9;
	for(int i=1;i<=ta;++i){
		//cout<<i<<' '<<sta[i]<<' '<<a[sta[i]].from<<' '<<a[sta[i]].from2<<'\n';
		if(!ind[sta[i]]) continue;
		tmp+=1ll*(a[sta[i]].d-a[a[sta[i]].from].c)*a[sta[i]].a;
		//cout<<sta[i]<<' '<<1ll*(a[sta[i]].d-a[a[sta[i]].from].c)*a[sta[i]].a<<'\n';
		if(!cir[sta[i]]) continue;
		if(!cir[a[sta[i]].from]||a[sta[i]].many){
			flag=1;
		}
		if(a[sta[i]].from2){
			t=min(t,a[a[sta[i]].from2].c-a[a[sta[i]].from].c);
			//cout<<a[a[sta[i]].from2].c-a[a[sta[i]].from].c<<'\n';
		}
		t=min(t,a[sta[i]].d-a[a[sta[i]].from].c);
		//cout<<a[sta[i]].d-a[a[sta[i]].from].c<<'\n';
	}
	//cout<<x<<' '<<tmp<<' '<<t<<'\n';
	if(num>1&&!flag) tmp-=t;
	ans+=tmp;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].f=read();
		a[i].c=read();
		a[i].d=read();
		a[i].a=read();
	}
	for(int i=1;i<=n;++i){
		if(a[a[i].f].d>a[i].c){
			add_edge(i,a[i].f,a[a[i].f].d-a[i].c);
			add_edge(a[i].f,i,0);
			++ind[a[i].f];
		}
	}
	for(int i=1;i<=n;++i){
		//cout<<i<<'\n';
		if(!vis[i]){
			solve(i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
