#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
int sz=0,l[MAXN],r[MAXN],npl[MAXN],key[MAXN];
int n,m,b[MAXN],c[MAXN],L[MAXN];
long long sum[MAXN],Num[MAXN];
int bro[MAXN],son[MAXN],root[MAXN];
int newnode(int k){
	sz++;
	l[sz]=r[sz]=npl[sz]=0;
	key[sz]=k;
	return sz;
}
int merge(int x,int y){  //返回新根
	if (!x||!y) return x+y;
	if (key[x]>key[y]) swap(x,y);
	//x->y;
	r[y]=merge(x,r[y]);
	if (npl[l[y]]<npl[r[y]]) swap(l[y],r[y]);
	npl[y]=npl[r[y]]+1;
	return y;
}
int pop(int x){  //返回新根
	return merge(l[x],r[x]);
}
int push(int x,int key){
	int y=newnode(key);
	return merge(x,y);
}
void add(int u,int p){
	bro[u]=son[p],son[p]=u;
}
int main(){
	scanf("%d%d",&n,&m); npl[0]=-1;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&b[i],&c[i],&L[i]);
		add(i,b[i]);
	}
	for (int i=n;i>=1;i--){
		sum[i]=c[i],Num[i]=1;
		root[i]=newnode(c[i]);
		for (int v=son[i];v;v=bro[v]){
			root[i]=merge(root[i],root[v]);
			sum[i]+=sum[v];
			Num[i]+=Num[v];
		}
		while (sum[i]>m){
			int mius=key[root[i]];
			sum[i]-=mius,Num[i]--;
			root[i]=pop(root[i]);
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,Num[i]*L[i]);
	printf("%lld\n",ans);
	return 0;
}
