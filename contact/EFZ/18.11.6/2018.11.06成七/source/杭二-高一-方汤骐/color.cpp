#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
inline void judge(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
}
int n,m;
struct edge{
	int s,t,nxt;
}e[200005];
int last[100005],e_cnt;
void ins(int a,int b){
	e[e_cnt]=(edge){a,b,last[a]};
	last[a]=e_cnt++;
}
vector<int> ep[100005];
vector<int> E[100005];
int p[100005],h[100005],cnt[100005];
int fa[100005];
int R[100005];
struct node{
	int ch[2],v;
}L[10000005];
int Lsize;
void newnode(int *x){
	Lsize++; L[Lsize]=L[*x]; *x=Lsize;
}
void ins(int *u,int x){
	if(!*u)newnode(u);
	L[*u].v++;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(x<=mid)u=&L[*u].ch[0],r=mid;
		else u=&L[*u].ch[1],l=mid+1;
		if(!*u)newnode(u);
		L[*u].v++;
	}
}
int qry(int u,int x){
	if(!x)return 0;
	int res=0;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(x<=mid)u=L[u].ch[0],r=mid;
		else res+=L[L[u].ch[0]].v,u=L[u].ch[1],l=mid+1;
	}
	res+=L[u].v;
	return res;
}
int l[100005],r[100005],tot;
void dfs(int x){
	l[x]=r[x]=++tot;
	ins(&R[p[x]],l[x]);
	for(int i=last[x];i!=-1;i=e[i].nxt)if(e[i].t!=fa[x]){
		fa[e[i].t]=x; 
		dfs(e[i].t);
		r[x]=max(r[x],r[e[i].t]);
	}
}
int q[100005],he,t;
vector<int> res;
int main(){
	judge();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),cnt[p[i]]++;
	memset(last,-1,sizeof(last));
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ins(u,v);
		ins(v,u);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		int tot=0;
		if(p[fa[i]]!=p[i]&&qry(R[p[fa[i]]],r[i])-qry(R[p[fa[i]]],l[i])>1)E[p[i]].push_back(p[fa[i]]),h[fa[i]]++;
		if(qry(R[p[i]],r[i])-qry(R[p[i]],l[i]-1)<cnt[p[i]]){
			if(p[fa[i]]!=p[i]){
				E[p[fa[i]]].push_back(p[i]);
				h[p[i]]++;
			}
			tot++;
		}
		for(int j=last[i];j!=-1;j=e[j].nxt)if(e[j].t!=fa[i]){
			if(qry(R[p[i]],r[e[j].t])-qry(R[p[i]],l[e[j].t]-1)>0)tot++;
		}
		if(tot<2)ep[p[i]].push_back(i);
		assert(tot<=2);
	}
	// for(int i=1;i<=m;i++)printf("%d %d\n",(ep[i].size()>0?ep[i][0]:0),ep[i].size()>1?ep[i][1]:0);
	//return 0;
	for(int i=1;i<=m;i++)if(cnt[i]&&!h[i]){
		q[++t]=i;
	}
	while(he<t){
		he++;
		res.push_back(q[he]);
		for(int i=0;i<E[q[he]].size();i++){
			h[E[q[he]][i]]--;
			if(!h[E[q[he]][i]]){
				q[++t]=E[q[he]][i];
			}
		}
	}
	for(int i=1;i<=m;i++)if(!cnt[i])res.push_back(i);
	for(int i=(int)res.size()-1;i>=0;i--){
		if(!ep[res[i]].size())printf("%d %d %d\n",res[i],1,1);
		else if(ep[res[i]].size()==1)printf("%d %d %d\n",res[i],ep[res[i]][0],ep[res[i]][0]);
		else printf("%d %d %d\n",res[i],ep[res[i]][0],ep[res[i]][1]);
	}
	return 0;
}