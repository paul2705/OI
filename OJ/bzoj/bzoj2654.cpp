#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e4*5+5;
const int MAXM=1e5*2+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],col[MAXM],w[MAXM];
struct rec{
	int u,v,col,w;
} ed[MAXM];
int n,m,ned,tot,cnt,res,fa[MAXN];
void add(int u,int v,int W,int Col){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,col[edge]=Col,w[edge]=W;
}
bool cmp(rec a,rec b){
	return a.w==b.w?a.col<b.col:a.w<b.w;
}
int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
bool check(int x){
	tot=cnt=res=0;
	for (int i=1;i<=n;i++){
		fa[i]=i;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (!col[e]) ed[res++]=(rec){i,v,col[e],w[e]+x};
			else ed[res++]=(rec){i,v,col[e],w[e]};
		}
	}
	sort(ed,ed+m,cmp);
	for (int i=0;i<m;i++){
		int p=find(ed[i].u),q=find(ed[i].v);
		if (p!=q){
			fa[p]=q;
			tot+=ed[i].w;
			if (!ed[i].col) cnt++;
		}
	}
	return cnt>=ned;
}
int main(){
	scanf("%d%d%d",&n,&m,&ned);
	for (int i=0,u,v,w,col;i<m;i++){
		scanf("%d%d%d%d",&u,&v,&w,&col);u++,v++;
		add(u,v,w,col); add(v,u,w,col);
	}
	int l=-105,r=105,sumv=0;
	while (l<=r){
//		cout<<l<<" "<<r<<endl;
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1,sumv=tot-ned*mid;
		else r=mid-1;
	}
	printf("%d\n",sumv);
	return 0;
}
