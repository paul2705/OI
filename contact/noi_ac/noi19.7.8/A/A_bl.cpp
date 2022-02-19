#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m,S,T,k,a[MAXN];
ll ans=0;
int main(){
	freopen("1.in","r",stdin);
	freopen("1_bl.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&S,&T,&k);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d%d",&u,&v,&a[i]);
	}
	sort(a+1,a+m+1);
	for (int i=1;i<=max(0,m-k);i++){
		ans+=a[i];
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
