#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const int MAXN1=4e4+5;
//const int MAXM=MAXN*2;
const int MAXN=1e6+6;
const int MAXM=MAXN*2;
ll fa[MAXN][22];
struct rec{
	ll p[65];
	rec(){
		for (int i=0;i<64;i++) p[i]=0;
	}
	ll mx(){
		ll ans=0;
		for (int i=63;i>=0;i--){
			if ((ans^p[i])>ans) ans^=p[i];
		}
		return ans;
	}
} pw[MAXN1][22];
struct rec1{
	ll p[3];
	rec1(){
		for (int i=0;i<3;i++) p[i]=0;
	}
	ll mx(){
		ll ans=0;
		for (int i=2;i>=0;i--){
			if ((ans^p[i])>ans) ans^=p[i];
		}
		return ans;
	}
} pw1[MAXN][22];
int n,m;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
ll a[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void ins(rec& a,ll val){
	for (int j=63;j>=0;j--){
		if (!((val>>j)&1ll)) continue;
		if (a.p[j]) val^=a.p[j];
		else {
			a.p[j]=val;
			break;
		}
	}
}
void ins1(rec1& a,ll val){
	for (int j=2;j>=0;j--){
		if (!((val>>j)&1)) continue;
		if (a.p[j]) val^=a.p[j];
		else {
			a.p[j]=val;
			break;
		}
	}
}
rec merge(rec& a,rec& b){
	rec c=a;
	for (int i=0;i<64;i++){
		ll tmp=b.p[i];
		ins(c,tmp);
	}
	return c;
}
rec1 merge1(rec1 &a,rec1 &b){
	rec1 c=a;
	for (int i=0;i<3;i++){
		ll tmp=b.p[i];
		ins1(c,tmp);
	}
	return c;
}
void ini(int u){
	for (int k=1;k<=20;k++){
//		cout<<u<<" "<<k<<" "<<fa[u][k-1]<<endl;
		fa[u][k]=fa[fa[u][k-1]][k-1];
		pw[u][k]=merge(pw[u][k-1],pw[fa[u][k-1]][k-1]);
	}
}
void ini1(int u){
	for (int k=1;k<=20;k++){
		fa[u][k]=fa[fa[u][k-1]][k-1];
		pw1[u][k]=merge1(pw1[u][k-1],pw1[fa[u][k-1]][k-1]);
	}
}
void dfs(int u,int p){
	fa[u][0]=p; ins(pw[u][0],a[p]); ini(u);
//	cout<<u<<" "<<p<<endl;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
ll qry(int u,int stp){
	ll ans=0; rec tmp;
	ins(tmp,a[u]);
	for (int k=0;k<=20;k++){
		if (u==0) break;
//		cout<<k<<" "<<stp<<" "<<u<<" "<<fa[u][k]<<endl;
		if ((stp>>k)&1){
			tmp=merge(tmp,pw[u][k]);
			u=fa[u][k];
		}
//		cout<<u<<endl;
	}
//	cout<<__func__<<u<<endl;
	return tmp.mx();
}
ll qry1(int u,int stp){
	ll ans=0; rec1 tmp;
	ins1(tmp,a[u]);
	for (int k=0;k<=20;k++){
		if (u==0) break;
		if ((stp>>k)&1){
			tmp=merge1(tmp,pw1[u][k]);
			u=fa[u][k];
		}
	}
	return tmp.mx();
}
void modify(int u,int p){
	fa[u][0]=p; ins(pw[u][0],a[p]);
	ini(u);
}
int pos[MAXN],d[MAXN];
void dfs1(int u,int p){
	fa[u][0]=p; ins1(pw1[u][0],a[p]); ini1(u);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
	}
}
void modify1(int u,int p){
	fa[u][0]=p; ins1(pw1[u][0],a[p]);
	ini1(u);
}
int main(){
//	freopen("squirrel.in","r",stdin);
//	freopen("squirrel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int f; scanf("%d%llu",&f,&a[i]);
		if (f==0) continue;
		add(i,f); add(f,i);
//		cout<<i<<" "<<a[i]<<endl;
	}
//	cout<<"done"<<endl;
	if (n+m<=1e5){
//		cout<<"in"<<endl;
		dfs(1,0);
//		cout<<"out"<<endl;
		for (int i=1;i<=m;i++){
			int op,u; ll val;
			scanf("%d%d%llu",&op,&u,&val);
//			cout<<op<<" "<<u<<" "<<val<<endl;
			if (op==0) printf("%llu\n",qry(u,val));
			else{
				n++; a[n]=val;
				add(n,u); add(u,n);
				modify(n,u);
			}
		}
	}
	else {
		dfs1(1,0);
		for (int i=1;i<=m;i++){
			int op,u; ll val;
			scanf("%d%d%llu",&op,&u,&val);
			if (op==0) printf("%llu\n",qry1(u,val));
			else {
				n++; a[n]=val;
				add(n,u); add(u,n);
				modify1(n,u);
			}
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
