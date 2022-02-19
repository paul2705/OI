//#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e6+5;
struct rec{
	int x,y,z,id;
} res[MAXN];
int n,a[MAXN],b[MAXN],c[MAXN];
ll ans,t[MAXN],f[MAXN];
unsigned int SA,SB,SC;
unsigned int rd(){
    SA^=SA<<16;SA^=SA>>5;SA^=SA<<1;
    unsigned int t=SA;SA=SB;SB=SC;SC^=t^SA;return SC;
}
void gen(int *P){
    for (int i=1;i<=n;++i) P[i]=i;
    for (int i=1;i<=n;++i) swap(P[i],P[1+rd()%n]);
}
bool cmp(rec a,rec b){return a.x<b.x; }
void add(int x,ll val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	ll ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
bool cmpr(rec a,rec b){return a.y<b.y; }
void cdq(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid); cdq(mid+1,r);
	for (int i=l;i<=mid;i++) res[i].id=1;
	for (int i=mid+1;i<=r;i++) res[i].id=0;
	sort(res+l,res+r+1,cmpr);
	for (int i=l;i<=r;i++){
		if (res[i].id==1) add(res[i].z,1);
		else f[i]+=sum(res[i].z);
	}
	for (int i=l;i<=r;i++) if (res[i].id==1) add(res[i].z,-1);
}
int main(){
	freopen("cdq.in","r",stdin);
	freopen("cdq1.out","w",stdout);
	scanf("%d%u%u%u",&n,&SA,&SB,&SC);
    gen(a);gen(b);gen(c);
	for (int i=1;i<=n;i++) res[i]=(rec){a[i],b[i],c[i]};
	sort(res+1,res+n+1,cmp);
	cdq(1,n);
	for (int i=1;i<=n;i++) ans+=f[i];
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
