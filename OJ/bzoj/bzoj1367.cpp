#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
typedef long long ll;
ll ans;
int tot[MAXN],L[MAXN],R[MAXN];
int n,m,M,a[MAXN],rt[MAXN];
struct tnode{
	int l,r,key,dis,sz;
} t[MAXN];
int newnode(int key){
	t[++M]=(tnode){0,0,key,0,1};
	return M;
}
int merge(int x,int y){
	if (!x) return y;
	if (!y) return x;
	if (t[x].key<t[y].key) swap(x,y);
	t[x].r=merge(t[x].r,y);
	t[x].sz=t[t[x].l].sz+t[t[x].r].sz+1;
	if (t[t[x].r].dis>t[t[x].l].dis) swap(t[x].l,t[x].r);
	t[x].dis=t[t[x].r].dis+1;
	return x;
}
int top(int rt){ return t[rt].key; }
int siz(int rt){ return t[rt].sz; }
void pop(int &rt){ rt=merge(t[rt].l,t[rt].r); }
int newheap(int x){ return newnode(x); }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]-=i;
	for (int i=1;i<=n;i++){
		m++;
		rt[m]=newheap(a[i]);
		tot[m]=1; L[m]=R[m]=i;
		while (m>1&&top(rt[m-1])>top(rt[m])){
			m--;
			rt[m]=merge(rt[m],rt[m+1]);
			tot[m]+=tot[m+1]; R[m]=R[m+1];
			while (siz(rt[m])*2>tot[m]+1) pop(rt[m]);
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=L[i],t=top(rt[i]);j<=R[i];j++){
			ans+=abs(a[j]-t);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
