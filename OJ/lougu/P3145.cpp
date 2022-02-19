#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,x,l[MAXN],r[MAXN],dd,kk,z[MAXN],d,ans;
struct rec{
	int l,r;
} a[MAXN];
bool cmp(rec a,rec b){ return a.l<b.l; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==0){ dd=i; continue; }
		if (l[x]) r[x]=dd=i;
		else l[x]=r[x]=i;
	}
	for (int i=1;i<=n;i++) if (l[i]) a[++kk].l=l[i],a[kk].r=r[i];
	sort(a+1,a+1+kk,cmp);
	for (int i=1;i<=kk;i++){
		while (a[i].l>a[z[d]].r&&d!=0) d--;
		if (a[i].r>a[z[d]].r&&d!=0) return printf("-1\n"),0;
		z[++d]=i,ans=max(ans,d);
	}
	printf("%d\n",ans);
	return 0;
}
