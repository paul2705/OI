#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=2e5+5;
int a[MAXN],n,m;
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans-=a[i]; a[i]*=2;
	}
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ans-=w; a[u]+=w; a[v]+=w;
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i+=2) ans+=a[i];
	printf("%d\n",ans);
	return 0;
}
