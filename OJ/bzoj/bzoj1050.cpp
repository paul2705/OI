#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
const int MAXM=5e3+5;
struct ed{
	int u,v,w;
} e[MAXM];
int n,m,fa[MAXN];
int s,t,x,y;
double ans=1e9;
int now;
bool cmp(ed a,ed b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[i]=(ed){u,v,w};
		if (find(u)!=find(v)) uion(u,v);
	}
	scanf("%d%d",&s,&t);
	if (find(s)!=find(t)) return printf("IMPOSSIBLE\n"),0;
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++){
		now=0;
		for (int j=1;j<=n;j++) fa[j]=j;
		for (int j=i;j<=m;j++){
			int u=e[j].u,v=e[j].v;
			if (find(u)!=find(v)) uion(u,v);
			if (find(s)==find(t)){
				now=j;
				break;
			}
		}
//		cout<<e[now].w<<" "<<e[i].w<<endl;
		if (now==0) continue;
		double res=(double)e[now].w/e[i].w;
		if (res<ans) ans=res,x=e[now].w,y=e[i].w;
	}
	int d=gcd(x,y);
	if (d==y) printf("%d\n",x/d);
	else printf("%d/%d\n",x/d,y/d);
	return 0;
}
