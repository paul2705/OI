#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=MAXN*2;
const int MAXT=MAXN*20;
struct tnode{
	int l,r,cl,cr;
	ll dat;
} t[MAXT];
int n,M;
ll res1,res2,ans;
int newnode(int l,int r,int cl,int cr,ll dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
int build(int l,int r,int val){
	if (r<val||l>val) return 0;
	if (l==r) return newnode(l,r,0,0,1);
	int mid=(l+r)>>1;
	int cl=build(l,mid,val),cr=build(mid+1,r,val);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat);
}
int merge(int l,int r,int p1,int p2){
	if (p1==0||p2==0) return p1+p2;
	if (l==r){
		t[p1].dat+=t[p2].dat;
		return p1;
	}
	int mid=(l+r)>>1;
	int cl1=t[p1].cl,cr1=t[p1].cr;
	int cl2=t[p2].cl,cr2=t[p2].cr;
	res1+=t[cr1].dat*t[cl2].dat;
	res2+=t[cr2].dat*t[cl1].dat;
	int cl=merge(l,mid,cl1,cl2);
	int cr=merge(mid+1,r,cr1,cr2);
	t[p1]=(tnode){l,r,cl,cr,t[cl].dat+t[cr].dat};
	return p1;
}
int dfs(){
	int x; scanf("%d",&x);
	if (x) return build(1,n,x);
	int nrt=merge(1,n,dfs(),dfs());
	ans+=min(res1,res2);
	res1=res2=0;
	return nrt;
}
int main(){
	scanf("%d",&n);
	dfs();
	printf("%lld\n",ans);
	return 0;
}
