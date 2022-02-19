#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=2e5+5;
const int MAXT=MAXN*4;
ll pow[MAXN];
struct mat{
	ll a[4][4];
	mat(){
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++) a[i][j]=0;
		}
	}
	void make(ll x,ll pos){
		a[0][0]=2; a[0][1]=((x-1)%mod+mod)%mod; a[0][2]=x*pow[pos-1]%mod;
		a[1][0]=0; a[1][1]=x%mod; a[1][2]=x*pow[pos-1]%mod;
		a[2][0]=0; a[2][1]=0; a[2][2]=1;
	}
	mat operator * (const mat& b) {
		mat c;
		for (int k=0;k<3;k++){
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return c;
	}
} empty;
struct tnode{
	int l,r,cl,cr;
	mat dat;
} t[MAXT];
int n,rt,M,T;
ll a[MAXN];
int newnode(int l,int r,int cl,int cr,mat x){
	t[++M]=(tnode){l,r,cl,cr,x};
	return M;
}
int build(int l,int r){
	mat tmp; tmp.make(a[l],l);
	if (l==r) return newnode(l,r,0,0,tmp);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cr].dat*t[cl].dat);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cr].dat*t[cl].dat;
}
void modify(int a,int b,int id,ll val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].dat.make(val,l);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
mat qry(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return empty;
	if (a<=l&&r<=b) return t[id].dat;
	return qry(a,b,cl)*qry(a,b,cr);
}
ll getans(){
	mat tmp=t[rt].dat;
	ll ans=tmp.a[0][2];
	return (ans%mod+mod)%mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]%=mod;
	pow[0]=pow[1]=1; 
	for (int i=2;i<=n+1;i++) pow[i]=pow[i-1]*2ll%mod;
	rt=build(1,n);
	scanf("%d",&T);
	printf("%lld\n",getans());
	for (int i=0;i<3;i++) empty.a[i][i]=1;
	while (T--){
		ll pos,val;
		scanf("%lld%lld",&pos,&val);
		val%=mod;
		modify(pos,pos,rt,val);
		a[pos]=val;
		printf("%lld\n",getans());
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
