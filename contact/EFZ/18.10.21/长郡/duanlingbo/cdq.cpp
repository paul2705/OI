#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
unsigned int SA,SB,SC;int n,a[N],b[N],c[N];
struct rec{
    int a,b,c;
} res[N];
ll ansa,ansb,ansc,t[N];
unsigned int rd(){
    SA^=SA<<16;SA^=SA>>5;SA^=SA<<1;
    unsigned int t=SA;SA=SB;SB=SC;SC^=t^SA;
    return SC;
}
void gen(int *P){
    for (int i=1;i<=n;++i) P[i]=i;
    for (int i=1;i<=n;++i) swap(P[i],P[1+rd()%n]);
}
void add(int x,ll val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
ll sum(int x){
	ll ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
bool cmpa(rec a,rec b){ return a.a<b.a; }
bool cmpb(rec a,rec b){ return a.b<b.b; }
bool cmpc(rec a,rec b){ return a.c<b.c; }
int main(){
	freopen("cdq.in","r",stdin);
	freopen("cdq.out","w",stdout);
	scanf("%d%u%u%u",&n,&SA,&SB,&SC);
    gen(a);gen(b);gen(c);
    for (int i=1;i<=n;i++) res[i]=(rec){a[i],b[i],c[i]};
	sort(res+1,res+n+1,cmpa);
	for (int i=1;i<=n;i++){
		ansa+=sum(res[i].b);
		add(res[i].b,1);
	}
	for (int i=1;i<=n;i++) t[i]=0;
	for (int i=1;i<=n;i++){
		ansb+=sum(res[i].c);
		add(res[i].c,1);
	}
	for (int i=1;i<=n;i++) t[i]=0;
	sort(res+1,res+n+1,cmpb);
	for (int i=1;i<=n;i++){
		ansc+=sum(res[i].c);
		add(res[i].c,1);
	}
	printf("%lld\n",(ansa+ansb+ansc-(ll)n*(n-1)/2)/(ll)2);
	fclose(stdin); fclose(stdout);
	return 0;
}
