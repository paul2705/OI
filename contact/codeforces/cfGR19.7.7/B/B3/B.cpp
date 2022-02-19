#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=5e2+5;
const int MAXM=3e5+5;
const int MAXD=3e5+5;
const int MAXDM=5e5+5;
int edge=1,head[MAXD],tail[MAXDM],nex[MAXDM];
ll r[MAXDM];
int n,m,s,B,k,L[MAXM],R[MAXM],lis[MAXM],PS;
int S,T,cur[MAXD],tmp[2*MAXM],tcnt=0;
ll d[MAXD];
queue<int> q;
bool use[MAXM];
ll g[MAXN][MAXN];
struct sp{
	int x,a,f,p,id;
	ll val;
} a[MAXM];
struct bs{
	int x,d;
	ll g;
} b[MAXM];
bool cmp_id(sp a,sp b){ return a.id<b.id; }
bool cmp_lis(int a,int b){ return g[PS][a]<g[PS][b]; }
bool cmpb(bs a,bs b){ return a.x==b.x?a.d<b.d:a.x<b.x; }
bool cmp(sp a,sp b){ return a.x==b.x?a.f<b.f:a.x<b.x; }
int M,rt;
struct tnode{
	int l,r,cl,cr,tag;
	ll dat;
} t[MAXM*8];
int newnode(int l,int r,int cl,int cr,ll dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,0);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=max(t[cl].dat,t[cr].dat);
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	if (!t[id].tag) return;
	t[id].dat=0;
	t[cl].tag^=1;
	t[cr].tag^=1;
	t[id].tag=0;
}
void modify(int a,int b,int id,ll val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].dat=max(t[id].dat,val);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
void modify_cl(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag^=1;
		pushdown(id);
		return;
	}
	modify_cl(a,b,cl); modify_cl(a,b,cr);
	update(id);
}
ll query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return max(query(a,b,cl),query(a,b,cr));
}
void add(int u,int v,ll R){
//	cout<<u<<" "<<v<<" "<<R<<endl;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,ll R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]==inf&&r[e]>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[T]<inf;
}
ll dfs(int u,ll b){
	if (u==T) return b;
	ll ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			ll res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) g[i][j]=inf;
		g[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		if (u==v) continue;
		g[u][v]=g[v][u]=1;
	}
	scanf("%d%d%d",&s,&B,&k);
	for (int i=1;i<=s;i++){
		scanf("%d%d%d%d",&a[i].x,&a[i].a,&a[i].f,&a[i].p);
		a[i].id=i; tmp[++tcnt]=a[i].a;
	}
	for (int i=1;i<=B;i++){
		scanf("%d%d%I64d",&b[i].x,&b[i].d,&b[i].g);
		tmp[++tcnt]=b[i].d;
	}
	sort(tmp+1,tmp+tcnt+1);
	int nt=unique(tmp+1,tmp+tcnt+1)-tmp-1;
	for (int i=1;i<=s;i++){
		a[i].a=lower_bound(tmp+1,tmp+nt+1,a[i].a)-tmp;
	}
	for (int i=1;i<=B;i++){
		b[i].d=lower_bound(tmp+1,tmp+nt+1,b[i].d)-tmp;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	sort(a+1,a+s+1,cmp); sort(b+1,b+B+1,cmpb);
	for (int l=1,r=1;l<=B;l=r+1,r++){
		while (r<B&&b[l].x==b[r+1].x) r++;
		int pos=b[l].x;
		L[pos]=l,R[pos]=r;
//		cout<<pos<<" "<<L[pos]<<" "<<R[pos]<<endl;
	}
	rt=build(0,nt);
	for (int i=1;i<=n;i++) lis[i]=i;
	for (int l=1,r=1;l<=s;l=r+1,r++){
		while (r<s&&a[l].x==a[r+1].x) r++;
		int pos=a[l].x; PS=pos;
		sort(lis+1,lis+n+1,cmp_lis);
		int LL=1;
//		cout<<pos<<endl;
		for (int i=l;i<=r;i++){
			for (;LL<=n;LL++){
				if (a[i].f>=g[pos][lis[LL]]){
//					cout<<lis[LL]<<endl;
					for (int k=L[lis[LL]];k<=R[lis[LL]];k++){
						modify(b[k].d,b[k].d,rt,b[k].g);
					}
				}
				else{ LL++; break; }
			}
			a[i].val=query(0,a[i].a,rt)-a[i].p;
		}
//		cout<<endl;
		modify_cl(0,nt,0);
	}
/*	for (int i=1;i<=s;i++){
		printf("%d\n",a[i].val);
	}*/
	sort(a+1,a+s+1,cmp_id);
	S=2*k+1,T=S+1;
	ll ans=0;
	for (int i=1;i<=k;i++){
		int u,v; scanf("%d%d",&u,&v);
		use[u]=use[v]=1;
//		if (a[u].val>0) ins(S,u,a[u].val),ans+=a[u].val;
//		else ins(u,T,-a[u].val);
//		if (a[v].val>0) ins(S,v,a[v].val),ans+=a[v].val;
//		else ins(v,T,-a[v].val);
		ins(u,v,inf);
	}
	for (int i=1;i<=s;i++){
		if (!use[i]) continue;
//		cout<<i<<" "<<a[i].val<<endl;
		if (a[i].val>0) ins(S,i,a[i].val),ans+=a[i].val;
		else ins(i,T,-a[i].val);
	}
//	cout<<ans<<endl;
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		ans-=dfs(S,inf);
	}
//	cout<<ans<<endl;
	for (int i=1;i<=s;i++){
		if (use[i]) continue;
		ans+=max(0ll,a[i].val);
	}
	cout<<ans<<endl;
	return 0;
}
