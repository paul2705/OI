#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXT=4e6+6;
struct tnode{
	int l,r,cl,cr,pre,suf,mn;
} t[MAXT];
int n,q,M,root,ans,ret,pr[MAXN],sf[MAXN],a[MAXN];
int newnode(int l,int r,int cl,int cr,int pre,int suf,int mn){
	t[++M]=(tnode){l,r,cl,cr,pre,suf,mn};
	return M;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,pr[l],sf[r],1e9);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	int pre=min(t[cl].pre,t[cr].pre);
	int suf=min(t[cl].suf,t[cr].suf);
	int mn=min(t[cl].mn,min(t[cr].mn,t[cl].pre+t[cr].suf));
	return newnode(l,r,cl,cr,pre,suf,mn);
}
int query(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return (int)1e9;
	if (a<=l&&r<=b){
		int res=min(t[id].mn,ret+t[id].suf);
		ret=min(ret,t[id].pre);  
		return res;
	}
	cl=query(cl,a,b); cr=query(cr,a,b); 
	return min(cl,cr);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		if (c=='0') a[i]=1;
		else a[i]=-1;
	}
	for (int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
	for (int i=n;i>=1;i--) sf[i]=sf[i+1]+a[i];
	root=ini(0,n+1);
	for (int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		l--,r++; ans=ret=1e9;
		printf("%d\n",pr[l]+sf[r]-query(root,l,r));
	}
	return 0;
}
