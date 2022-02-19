#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include"sys/time.h"
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN=3e5+5;
const int MAXM=5e5+5;
const int mod=1e9+7;
ll n,m,AA,BB;
ll p[MAXN],tmp[MAXN];
int ans[MAXN],cnt[MAXM];
map<ll,int> pri;
struct rec{
	ll p;
	int cnt;
} lis[MAXN];
struct rq{
	ll key;
	int a,b;
} rtm[MAXN];
vector<ll> A,B;
vector<int> Ax[MAXN],Bx[MAXN];
int tot;
ll mul(ll a,ll b,ll mod){ 
	a%=mod; b%=mod;
	ll ret=(ll)((ld)a*b/mod)*mod;
	ret=(a*b-ret)%mod;
	return ret<0?ret+mod:ret; 
}
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll mrand(ll x){
	return (ll)((ll)rand()<<15)^(ll)rand()%x;
}
ll mod_pow(ll x,ll n,ll mod){
	ll ret=1;
	while (n){
		if (n&1) ret=mul(ret,x,mod);
		x=mul(x,x,mod);
		n>>=1;
	}
	return ret;
}
bool mrr(ll x,ll n){
	ll mod=n; n--;
	while (n&&n%2==0){
		n>>=1;
		ll res=mod_pow(x,n,mod);
		if (res!=1&&res!=mod-1) return 1;
		if (res==mod-1) return 0;
	}
	return 0;
}
bool mr(ll x){
	if (x==2||x==3||x==5||x==7) return 1;
	if (x%2==0||x%3==0||x%5==0||x%7==0) return 0;
	if (mrr(2,x)) return 0;
	if (mrr(3,x)) return 0;
	if (mrr(5,x)) return 0;
	if (mrr(7,x)) return 0;
	return 1;
}
ll f(ll x,ll c,ll mod){ return (mul(x,x,mod)+mod+c)%mod; }
ll prr(ll n){
	ll x=mrand(n),y=0,c=mrand(n);
	y=x; y=f(y,c,n);
	while (1){
		ll res=gcd(abs(x-y),n);
		if (res!=1&&res!=n) return res;
		if (res==n) return -1;
		y=f(y,c,n); y=f(y,c,n);
		x=f(x,c,n);
	}
	return -1;
}
void pr(ll n){
	if (mr(n)){
		pri[n]++;
		return;
	}
	ll res=0;
	while (1){
		res=prr(n);
		if (res!=-1) break;
	}
	pr(res); pr(n/res);
}
void get_prime(ll x){
	pr(x);
	for (map<ll,int>::iterator it=pri.begin();it!=pri.end();it++){
		lis[tot++]=(rec){(*it).first,(*it).second};
	}
}
void dfs(ll d,ll S,ll lim,vector<ll>& P){
	if (d==tot) return;
	if (!(S&(1<<d))){
		dfs(d+1,S,lim,P);
		return;
	}
	vector<ll> res;
	ll pri=1;
	for (int i=1;i<=lis[d].cnt;i++){
		if (lis[d].p==1) continue;
		pri*=lis[d].p;
		for (int j=0;j<P.size();j++){
			ll x=P[j]; if (x*pri>lim) continue;
			res.push_back(x*pri);
		}
	}
	for (int i=0;i<res.size();i++) P.push_back(res[i]);
	dfs(d+1,S,lim,P);
}
int Find(vector<ll>& P,ll x){
	return lower_bound(P.begin(),P.end(),x)-P.begin();
}
bool cmp(rq a,rq b){ return a.key<b.key; }
int main(){
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	scanf("%lld%lld",&n,&m);
	get_prime(m);
	int mn=1e9,best_st=-1;
	for (int s=0;s<(1<<tot);s++){
		int res1=1,res2=1;
		for (int i=0;i<tot;i++){
			if (s&(1<<i)) res1*=lis[i].cnt+1;
			else res2*=lis[i].cnt+1;
		}
		if (max(res1,res2)<mn){
			mn=max(res1,res2);
			best_st=s;
		}
	}
	AA=BB=1;
	for (int i=0;i<tot;i++){
		ll pri=1;
		for (int j=1;j<=lis[i].cnt;j++) pri*=lis[i].p;
		if (best_st&(1<<i)) AA*=pri;
		else BB*=pri;
	}
	A.push_back(1); B.push_back(1);
	dfs(0,best_st,AA,A);
	dfs(0,best_st^((1<<tot)-1),BB,B);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for (int i=1;i<=n;i++) scanf("%lld",&p[i]),tmp[i]=p[i];
	sort(tmp+1,tmp+n+1);
	int nn=unique(tmp+1,tmp+n+1)-tmp-1;
	for (int i=1;i<=nn;i++){
		ll x=gcd(tmp[i],AA);
		ll y=tmp[i]/x;
		rtm[i]=(rq){tmp[i],Find(A,x),Find(B,y)};
	}
	ans[1]=1;
	for (int i=0;i<B.size();i++){
		for (int j=0;j<B.size();j++){
			if (B[i]%B[j]==0) Bx[i].push_back(j);
		}
	}
	for (int i=0;i<A.size();i++){
		for (int j=0;j<A.size();j++){
			if (A[i]%A[j]==0) Ax[j].push_back(i);
		}
	}
	for (int i=1;i<=n;i++){
		ll res=0;
		int pos=lower_bound(rtm+1,rtm+nn+1,(rq){p[i],0,0},cmp)-rtm;
//		cout<<p[i]<<" "<<rtm[pos].key<<endl;
		int x=rtm[pos].b,y=rtm[pos].a;
		if (i!=1){
			for (int j=0;j<Bx[x].size();j++){
				int nx=Bx[x][j];
				res=(res+cnt[nx+y*B.size()])%mod;
			}
			ans[i]=res%mod;
		}	
		for (int j=0;j<Ax[y].size();j++){
			int ny=Ax[y][j];
			cnt[ny*B.size()+x]=(cnt[ny*B.size()+x]+ans[i])%mod;
		}
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]%mod);
	return 0;
}
