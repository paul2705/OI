#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=6e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m;
ll p[MAXN];
struct rec{
	int op,val;
} a[MAXN];
bool flag=1;
void dfs(int u){
	int op=a[u].op,val=a[u].val;
	if (op>0&&val>=p[u]) flag=0;
	if (op<0&&val<0) flag=0;

	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		int nop=-op,nval=w-val;
		if (a[v].op!=-2){
			if (a[v].op==nop){
				if (a[v].val!=nval) flag=0;
			}
			else {
				a[v].op=0; a[v].val+=nval;
			}
		}
		else a[v]=(rec){nop,nval};
		dfs(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=n;i++) a[i].op=-2,a[i].val=0;
	for (int i=1;i<=n;i++){
		if (a[i].op==-2){
			a[i].op=1;
			dfs(i);
			int op=0,val=0;
			int all=0;
			for (int i=1;i<=n;i++){
				if (a[i].op<=-2) continue;
				op+=a[i].op;
				val+=a[i].val;
				all+=p[i];
				a[i].op=-3;
			}
			op=-op; 
			all-=val;
		}
	}

		
