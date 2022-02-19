#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],b[MAXN],n,m;
int pos,cnt[MAXN],N,ans[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for (int i=1;i<=n;i++) if (!cnt[i]) b[++N]=i;
	pos=1; int ret=1,go=1;
	for (int i=m+1;i<=n+1;i++) a[i]=n+1;
	for (int i=1;i<=n;i++){
		if (b[go]==0) ans[ret++]=a[pos++];
		else if (a[pos]==0) ans[ret++]=b[go++];
		else if (b[go]<a[pos]) ans[ret++]=b[go++];
		else ans[ret++]=a[pos++];
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
