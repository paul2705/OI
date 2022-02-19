#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e4+5;
const int MAXT=MAXN*4;
struct base{
	ll bin[33];
	base(){
		for (int i=0;i<33;i++) bin[i]=0;
	}
} B[MAXN];
struct tnode{
	int l,r,cl,cr;
	base dat;
} t[MAXT];
int n,m,M,rt;
int newnode(int l,int r,int cl,int cr,base dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
base merge(base a,base b){
	base ret;
	for (int i=0;i<33;i++){
		if (a.bin[i]==0||b.bin[i]==0) continue;
		ret.bin[i]=a.bin[i];
	}
	return ret;
}
int build(int l,int r){
	base x;
	if (l==r) return newnode(l,r,0,0,x);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,x);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=merge(t[cl].dat,t[cr].dat);
}
void modify(int a,int b,int id,base& val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].dat=val;
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
base qry(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	base x;
	if (l>b||r<a) return x;
	if (a<=l&&r<=b) return t[id].dat;
	return merge(qry(a,b,cl),qry(a,b,cr));
}
void solve2(){
	rt=build(1,n);
	for (int i=1;i<=n;i++) modify(i,i,rt,B[i]);
	for (int i=1;i<=m;i++){
		int l,r; ll x; scanf("%d%d%lld",&l,&r,&x);
		base o=qry(l,r,rt);
		for (int j=32;j>=0;j--){
			if (!(x&(1<<j))) continue;
			if (o.bin[j]) x^=o.bin[j];
		}
		if (x==0) printf("YES\n");
		else printf("NO\n");
	}
}
void solve1(){
	for (int i=1;i<=m;i++){
		int l,r; ll tmp,x; scanf("%d%d%lld",&l,&r,&tmp);
		bool flag=1;
		for (int j=l;j<=r;j++){
			x=tmp;
			for (int k=32;k>=0;k--){
				if (!(x&(1ll<<k))) continue;
				if (B[j].bin[k]) x^=B[j].bin[k];
			}
			if (x!=0) flag=0;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for (int j=1;j<=x;j++){
			ll o; scanf("%lld",&o);
			for (int k=32;k>=0;k--){
				if (!(o&(1ll<<k))) continue;
				if (!B[i].bin[k]){
					B[i].bin[k]=o;
					break;
				}
				else o^=B[i].bin[k];
			}
		}
	}
//	solve2();
	if (n<=5000) solve1();
	else solve2();
	return 0;
}
