#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=10;
ll a[MAXN][MAXN],n,m,p,ans;
bool use[MAXN*MAXN];
ll mx1[MAXN],mx2[MAXN];
void dfs(int d){
	if (d==n*m+1){
		int cnt=0;
		for (int i=1;i<=max(n,m);i++) mx1[i]=mx2[i]=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				mx1[i]=max(mx1[i],a[i][j]);
			}
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				mx2[i]=max(mx2[i],a[j][i]);
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (a[i][j]==mx1[i]&&a[i][j]==mx2[j]) cnt++;
			}
		}
		if (cnt==1) ans=(ans+1)%p;
		return;
	}
	int x=d/m+1,y=d%m;
	if (y==0) y=m,x--;
	for (int i=1;i<=n*m;i++){
		if (!use[i]){
			a[x][y]=i; use[i]=1;
			dfs(d+1);
			use[i]=0;
		}
	}
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&p);
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
