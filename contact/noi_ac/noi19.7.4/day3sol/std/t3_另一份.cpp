#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+100,INF=1e9;
ll anses[maxn],val[maxn];
int top[maxn],dfn[maxn],dep[maxn],rig[maxn],sz[maxn],son[maxn],tim;
int fa[maxn],ato[maxn],afr[maxn],n,Q;
vector<int> G[maxn],H[maxn],A[maxn],mcfx[maxn];
void dfs1(int u,int f){
//	fprintf(stderr,"[%d]",u);
	sz[u]=1,fa[u]=f,son[u]=dfn[u]=top[u]=0;
	for(auto v:G[u])if(v!=f){
		dfs1(v,u),sz[u]+=sz[v];
		if(!son[u]||sz[son[u]]<sz[v])son[u]=v;
	}
}
void dfs2(int u,int tp,int d){
	top[u]=tp,dfn[u]=++tim,dep[u]=d;
	if(son[u])dfs2(son[u],tp,d+1);
	for(auto v:G[u])if(v!=fa[u]&&v!=son[u])
		dfs2(v,v,d+1);
	rig[u]=tim;
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
struct Data{
	int mntg,mntgcnt;
	int tg,mnans;
	int ans,anscnt;
	ll mnanscnt;
	Data(){}
	Data operator+(const Data& d)const{
		Data ret;
		ret.mntg=mntg,ret.mntgcnt=mntgcnt;
		ret.mnans=mnans,ret.mnanscnt=mnanscnt;
		if(ret.mntg==tg+d.mntg)ret.mntgcnt+=d.mntgcnt;
		else if(ret.mntg>tg+d.mntg)ret.mntg=tg+d.mntg,ret.mntgcnt=d.mntgcnt;
		ret.tg=tg+d.tg;
		if(ret.mnans==ans+d.mntg)ret.mnanscnt+=(ll)anscnt*d.mntgcnt;
		else if(ret.mnans>ans+d.mntg)ret.mnans=ans+d.mntg,ret.mnanscnt=(ll)anscnt*d.mntgcnt;
		ret.ans=ans+d.tg,ret.anscnt=anscnt;
		return ret;
	}
	void upd(int x){
		if((tg+=x)==mntg)mntgcnt++;
		else if(tg<mntg)mntg=tg,mntgcnt=1;
		if((ans+=x)==mnans)mnanscnt+=anscnt;
		else if(ans<mnans)mnans=ans,mnanscnt=anscnt;
	}
};
pair<int,Data> jl[maxn*32];
int jltp;
struct Seg{
	Data s[maxn<<2];
	void pd(int o){
		if(!s[o].mntgcnt)return ;
		s[o<<1]=s[o<<1]+s[o];
		s[o<<1|1]=s[o<<1|1]+s[o];
		s[o].tg=0;
		s[o].mntg=INF;
		s[o].mntgcnt=0;
	}
	void upd(int o){
		int L=o<<1,R=o<<1|1;
		s[o].mnanscnt=0,s[o].anscnt=0;
		s[o].mnans=min(s[L].mnans,s[R].mnans);
		
		if(s[L].mnans==s[o].mnans)s[o].mnanscnt+=s[L].mnanscnt;
		if(s[R].mnans==s[o].mnans)s[o].mnanscnt+=s[R].mnanscnt;
		
		s[o].ans=min(s[L].ans,s[R].ans);
		
		if(s[L].ans==s[o].ans)s[o].anscnt+=s[L].anscnt;
		if(s[R].ans==s[o].ans)s[o].anscnt+=s[R].anscnt;
	}
	void add(int o,int l,int r,int ql,int qr,int w){
//		if(o==1)printf("(%d)<%d,%d,%d>\n",o,ql,qr,w);
		if(ql>qr)return ;
		if(ql<=l&&r<=qr){
			s[o].upd(w);
			return ;
		}
		int mid=l+r>>1;
		pd(o);
		if(ql<=mid)add(o<<1,l,mid,ql,qr,w);
		if(qr>mid)add(o<<1|1,mid+1,r,ql,qr,w);
		upd(o);
	}
	void mdy(int o,int l,int r,int x){
//		if(o==1)printf("(%d)<%d,%d,%d>\n",o,ql,qr,w);
		if(l==r){
			s[o].mntg=INF;
			s[o].mntgcnt=0;
			s[o].ans=1;
			s[o].anscnt=1;
			s[o].mnans=1;
			s[o].mnanscnt=1;
			return ;
		}
		int mid=l+r>>1;
		pd(o);
		if(x<=mid)mdy(o<<1,l,mid,x);
		else mdy(o<<1|1,mid+1,r,x);
		upd(o);
	}
	void add2(int o,int l,int r,int ql,int qr,int w){
//		if(o==1)printf("(%d)<%d,%d,%d>\n",o,ql,qr,w);
		if(ql<=l&&r<=qr){
			jl[++jltp]=make_pair(o,s[o]);
			return (void)(s[o].upd(w));
		}
		int mid=l+r>>1;
		jl[++jltp]=make_pair(o,s[o]);
		if(s[o].mntgcnt){
			jl[++jltp]=make_pair(o<<1,s[o<<1]);
			jl[++jltp]=make_pair(o<<1|1,s[o<<1|1]);
		}
		pd(o);
		if(ql<=mid)add2(o<<1,l,mid,ql,qr,w);
		if(qr>mid)add2(o<<1|1,mid+1,r,ql,qr,w);
		upd(o);
	}
	void build(int o,int l,int r,int fla=0){
		s[o].mntg=INF;
		s[o].mntgcnt=0;		
		if(l==r){
//			printf("{val:%d}",val[l]);
			s[o].ans=fla?INF:val[l];
			s[o].anscnt=1;
			s[o].mnans=fla?INF:val[l];
			s[o].mnanscnt=0;
			return ;
		}
		int mid=l+r>>1;
		build(o<<1,l,mid,fla);
		build(o<<1|1,mid+1,r,fla);
		upd(o);
	}
	ll qry(int o,int l,int r,int ql,int qr){
//		printf("<%d>",s[o].mnans);
		if(ql<=l&&r<=qr)return s[o].mnans==1?s[o].mnanscnt:0;
		int mid=l+r>>1;
		ll ans=0;
		Data a=s[o],b=s[o<<1],c=s[o<<1|1]; 
		pd(o);
		if(ql<=mid)ans+=qry(o<<1,l,mid,ql,qr);
		if(qr>mid)ans+=qry(o<<1|1,mid+1,r,ql,qr);
		s[o<<1]=b,s[o<<1|1]=c,s[o]=a;
		return ans;
	}
	ll dqry(int u,int l,int r,int x){
		ll ans=0;
		while(top[u]!=top[x]){
//			printf("[ask:%d,%d]",dfn[top[u]],dfn[u]);
			ans+=qry(1,l,r,dfn[top[u]],dfn[u]);
			u=fa[top[u]];
		} 
//		printf("[ask:%d,%d(%d,%d)]",dfn[x],dfn[u],x,u);
		ans+=qry(1,l,r,dfn[x],dfn[u]);
		return ans;
	}
}M;
int Lpos[maxn],ALL;
void dfsL(int u,int d){
	Lpos[u]=1;
	for(auto v:H[u])if(Lpos[v])
		d--;
	val[dfn[u]]=d;
	for(auto v:G[u])if(v!=fa[u])
		dfsL(v,d+1);
	Lpos[u]=0;
}
void dfsR(int u,int rt,int fr){
//	printf("[%d]",u);
	Lpos[u]=1;
	int rtp=jltp;
	M.add2(1,1,n,1,n,1);
	for(auto v:H[u])
		if(Lpos[v])
			M.add2(1,1,n,1,n,-1);
		else if((dfn[v]>=dfn[rt]&&dfn[v]<=rig[rt])&&(dfn[v]<dfn[fr]))
			M.add2(1,1,n,dfn[v],rig[v],-1);
	for(auto v:mcfx[u]){
	//	printf("[ask%d,%d]",afr[v],rt);
		anses[v]+=M.dqry(afr[v],1,n,rt)-M.qry(1,1,n,dfn[rt],dfn[rt]);
	}
	for(auto v:G[u])if(v!=fa[u])
		dfsR(v,rt,fr);
	while(jltp>rtp){
		M.s[jl[jltp].first]=jl[jltp].second;
		jltp--;
		ALL++;
	}
	
	Lpos[u]=0;
}
void sol(int u,int f){
	if(son[u])sol(son[u],u);
	for(auto v:G[u])if(v!=f&&v!=son[u])
		sol(v,u);
	M.mdy(1,1,n,dfn[u]);
	M.add(1,1,n,dfn[u]+1,rig[u],1);
	for(auto a:H[u])if(dfn[a]>=dfn[u]&&dfn[a]<=rig[u])
		M.add(1,1,n,dfn[a],rig[a],-1);
	for(auto x:A[u]){
		if(dfn[afr[x]]>dfn[ato[x]])swap(afr[x],ato[x]);
		if(afr[x]==u){
//			printf("<%d>",ato[x]);
			anses[x]=M.dqry(ato[x],1,n,u);
		} else {
			anses[x]=M.dqry(ato[x],1,n,u);
//			printf("{%d:%lld(%lld)}",x,anses[x],M.dqry(afr[x],1,n,u));
			mcfx[ato[x]].push_back(x);
		}
	}
	for(auto v:G[u])if(v!=f&&v!=son[u])
		dfsR(v,u,v);
	for(auto x:A[u])mcfx[ato[x]].clear();
}
int main(){
//	freopen("..\\down\\3.in","r",stdin);
//	freopen("..\\down\\3.ans","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		H[u].push_back(v);
		H[v].push_back(u);
	}
	dfs1(1,0);
//	return 0;
	dfs2(1,1,1);
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&afr[i],&ato[i]);
	}
	for(int i=1;i<=Q;++i){
		if(afr[i]==ato[i])
			anses[i]=1;
		else A[lca(afr[i],ato[i])].push_back(i);
	}
	M.build(1,1,n);
	sol(1,0);
	int CNT=0,CNT2=0;
	for(int i=1;i<=Q;++i){
		printf("%lld\n",anses[i]);
		CNT+=anses[i]>2*(dep[afr[i]]+dep[ato[i]]-2*dep[lca(afr[i],ato[i])]+1);
		CNT2+=anses[i]>(dep[afr[i]]+dep[ato[i]]-2*dep[lca(afr[i],ato[i])]+1);
	}
	fprintf(stderr,"[%d,CNT2=%d(%d)]",CNT,CNT2,ALL);
}
