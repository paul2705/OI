#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=5e2+5;
const int MAXM=1e4+5;
struct edge{
	int u,v,w;
} e[MAXM];
int fa[MAXN],n,m,s,t,M,mx,mn;
double ans=1e9;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
bool cmp(edge a,edge b){ return a.w<b.w; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[M++]=(edge){u,v,w};
	}
	sort(e,e+M,cmp);
	scanf("%d%d",&s,&t);
	for (int i=0;i<M;i++){
		int m1=e[i].w,m2=e[i].w; bool f=0;
		for (int j=1;j<=n;j++) fa[j]=j;
		for (int j=i;j<M;j++){
			if (find(e[j].u)!=find(e[j].v)){
				fa[find(e[j].u)]=find(e[j].v);
				m2=e[j].w;
			}
			if (find(s)==find(t)){ f=1; break; }
		}
		if ((double)m2/m1<ans&&f) ans=(double)m2/m1,mx=m2,mn=m1;
	}
	if (!mn) return printf("IMPOSSIBLE\n"),0;
	if (ans!=floor(ans)){
		int x=gcd(mx,mn);
		printf("%d/%d\n",mx/x,mn/x);
	}
	else printf("%.0lf\n",ans);
	return 0;
}
