#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=1e7;
const int MAXN=5e4+5;
const int MAXT=2e6*4;
const int del=1e6;
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXT];
int n,m,M,rt;
ll ans;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
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
	t[id].dat=t[cl].dat|t[cr].dat;
}
void modify(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].dat=1;
		return;
	}
	modify(cl,a,b); modify(cr,a,b);
	update(id);
}
int qryl(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return -inf;
//	cout<<__func__<<" "<<l<<" "<<r<<" "<<t[id].dat<<endl;
	if (l==r) return t[id].dat?l:-inf;
	if (a<=l&&r<=b){
		if (t[cr].dat) return qryl(cr,a,b);
		else if (t[cl].dat) return qryl(cl,a,b);
		else return -inf;
	}
	return max(qryl(cl,a,b),qryl(cr,a,b));
}
int qryr(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return inf;
//	cout<<__func__<<" "<<l<<" "<<r<<" "<<t[id].dat<<endl;
	if (l==r) return t[id].dat?l:inf;
	if (a<=l&&r<=b){
		if (t[cl].dat) return qryr(cl,a,b);
		else if (t[cr].dat) return qryr(cr,a,b);
		else return inf;
	}
	return min(qryr(cl,a,b),qryr(cr,a,b));
}
int main(){
	scanf("%d",&n);
	rt=build(1,(int)2e6);
	scanf("%lld",&ans);
	modify(rt,ans+del,ans+del);
	for (int i=2;i<=n;i++){
		int x; scanf("%d",&x); x+=del;
		int l=qryl(rt,1,x);
		int r=qryr(rt,x+1,(int)2e6);
		ans+=min(x-l,r-x);
//		cout<<i<<": "<<l<<" "<<x<<" "<<r<<endl;
		modify(rt,x,x);
	}
	printf("%lld\n",ans);
	return 0;
}
