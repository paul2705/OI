#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e6+6;
const int MAXM=2e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int col[MAXN],n,m;
struct rec{
	int l,r;
	bool operator < (const rec& b) const{
		return r<b.r;
	}
} a[MAXN];
struct stk{
	int l,r;
} st[MAXN];
int top;
bool fl=1;
ll ans=1;
bool iset(int i,int j){
	int l=a[j].l,r=a[j].r;
	if (r<=a[i].l||l>=a[i].r) return 0;
	return 1;
}
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
//	cout<<u<<" "<<v<<endl;
}
void dfs(int u,int c){
	if (col[u]){
		if (col[u]!=c) fl=0;
		return;
	}
	col[u]=c;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		dfs(v,c^1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1);
	st[1]=(stk){1,1}; top=1;
	for (int i=2;i<=n;i++){
		while (top>1&&iset(st[top-1].r,i)){
			st[top-1].r=st[top].r;
			top--;
		}
		if (iset(st[top].r,i)){
			int L=st[top].l,R=st[top].r;
			for (int j=R;j>=L;j--){
				if (iset(j,i)) add(j,i),add(i,j);
			}
			st[top].r=i;
		}
		else st[++top]=(stk){i,i};
	}
	dfs(1,2);
//	cout<<fl<<endl;
	if (!fl) return printf("0\n"),0;
	while (top--) ans=ans*2ll%mod;
	printf("%lld\n",ans);
	return 0;
}
