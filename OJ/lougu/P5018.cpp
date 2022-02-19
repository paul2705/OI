#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll stp=1057;
const int MAXN=1e6+6;
struct node{
	int val,cl,cr,l1,r1,l2,r2;
} t[MAXN];
int n,m;
ll dfn1[MAXN],cnt=0;
ll has1[MAXN],has2[MAXN];
ll dfn2[MAXN];
ll has3[MAXN],has4[MAXN];
void dfs1(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].l1=cnt;
	if (cl!=-1) dfs1(cl);
	dfn1[++cnt]=t[id].val;
	if (cr!=-1) dfs1(cr);
	t[id].r1=cnt;
}
void dfs2(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].l2=cnt;
	if (cr!=-1) dfs2(cr);
	dfn2[++cnt]=t[id].val;
	if (cl!=-1) dfs2(cl);
	t[id].r2=cnt;
}
ll mod_pow(ll x,ll n){
	ll ans=1;
	while (n){
		if (n&1) ans=ans*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&t[i].val);
	for (int i=1;i<=n;i++) scanf("%d%d",&t[i].cl,&t[i].cr);
	dfs1(1);
//	for (int i=1;i<=cnt;i++) printf("%lld ",dfn[i]);
//	printf("\n");
//	for (int i=1;i<=n;i++) printf("%d %d\n",t[i].l,t[i].r);
	for (int i=1;i<=cnt;i++) has1[i]=(has1[i-1]*stp%mod+dfn1[i])%mod;
	for (int i=cnt;i>=1;i--) has2[i]=(has2[i+1]*stp%mod+dfn1[i])%mod;
	cnt=0;
	dfs2(1);
	for (int i=1;i<=cnt;i++) has3[i]=(has3[i-1]*stp%mod+dfn2[i])%mod;
	for (int i=cnt;i>=1;i--) has4[i]=(has4[i+1]*stp%mod+dfn2[i])%mod;
	int ans=0;
	for (int i=1;i<=n;i++){
		int l=t[i].l1,r=t[i].r1;
		ll tmp1=((has1[r]-has1[l]*mod_pow(stp,r-l)%mod)%mod+mod)%mod;
		ll tmp2=((has2[l+1]-has2[r+1]*mod_pow(stp,r-l)%mod)%mod+mod)%mod;
		l=t[i].l2; r=t[i].r2;
		ll tmp3=((has3[r]-has3[l]*mod_pow(stp,r-l)%mod)%mod+mod)%mod;
		ll tmp4=((has4[l+1]-has4[r+1]*mod_pow(stp,r-l)%mod)%mod+mod)%mod;
//		cout<<i<<" "<<tmp1<<" "<<tmp2<<endl;
		if (tmp1==tmp2&&tmp3==tmp4) ans=max(ans,r-l);
	}
	printf("%d\n",ans);
	return 0;
}
