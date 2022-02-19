#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,p;
int ans,a[15][15];
int maxn[15],maxm[15];
bool b[105];
bool calc(){
	int i,j,maxx,cnt=0;
	ll sum=0;
	for(i=1;i<=m;i++){
		maxx=0;
		for(j=1;j<=n;j++) maxx=max(maxx,a[j][i]);
		maxn[i]=maxx;
	}
	for(i=1;i<=n;i++){
		maxx=0;
		for(j=1;j<=m;j++) maxx=max(maxx,a[i][j]);
		maxm[i]=maxx;
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if(maxm[i]==a[i][j]&&maxn[j]==a[i][j]){
			cnt++;
			if(cnt>1) return false;
		}
	}
	return true;
}
void dfs(int x){
	if(x>n*m){
		if(calc()) ans++;
		return;
	}
	int i;
	for(i=1;i<=n*m;i++){
		if(!b[i]){
			a[(x-1)/m+1][(x-1)%m+1]=i;
			b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d %d %d",&n,&m,&p);
	memset(b,0,sizeof(b)),ans=0;
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
