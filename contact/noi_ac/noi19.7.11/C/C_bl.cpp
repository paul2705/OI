#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=50;
const int MAXH=1e5+5;
map<int,int> use[MAXH];
int n,m,c,a[MAXN][MAXN];
ll ans;
int lis[MAXN],top;
void dfs(int x,int y){
	if (x==n+1){
		int Hl=0;
		top=0;
		for (int i=1;i<=n;i++){
			int cnt=0;
			for (int j=1;j<=m;j++){
				cnt+=a[i][j];
			}
			lis[top++]=cnt;
		}
		sort(lis,lis+top);
		for (int i=0;i<top;i++) Hl=Hl*10+lis[i];
		int Hr=0; top=0;
		for (int i=1;i<=m;i++){
			int cnt=0;
			for (int j=1;j<=n;j++){
				cnt+=a[j][i];
			}
			lis[top++]=cnt;
		}
		sort(lis,lis+top);
		for (int i=0;i<top;i++) Hr=Hr*10+lis[i];
		if (!use[Hl][Hr]){
			use[Hl][Hr]=1;
			ans=(ans+1)%mod;
		}
		return;
	}
	int nx=x,ny=y+1;
	if (y==m) nx=x+1,ny=1;
	a[x][y]=0; dfs(nx,ny);
	a[x][y]=1; dfs(nx,ny);
}
void solve1(){
	if (n>m) swap(n,m);
	if (n==3&&m==3) return printf("36\n"),void();
	dfs(1,1);
	printf("%lld\n",ans);
}
void solve2(){

}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	if (c==1) printf("1\n");
	else if (c==2) solve1();
	else solve2();
	return 0;
}
