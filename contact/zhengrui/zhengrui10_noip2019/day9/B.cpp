#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mxn=5010,md=1000000007;
int n,f[mxn][mxn],a[mxn][mxn],c[mxn][mxn];
int F(int x,int y){
	if (x<0||y<0) return 1;
	else return c[x+y][x];
}
int dfs(int l,int r){
	if (l>r) return 1;
	if (f[l][r]>=0) return f[l][r];
	f[l][r]=0;
	for (int i=1;i<=a[l][0];++i)
		if (a[l][i]>=l&&a[l][i]<=(l+r)/2)
			f[l][r]=(f[l][r]+1ll*dfs(l,a[l][i]-1)*dfs(a[l][i]+1,r)%md*F(a[l][i]-l,r-a[l][i]))%md;
	for (int i=1;i<=a[r][0];++i)
		if (a[r][i]<=r&&a[r][i]>(l+r)/2)
			f[l][r]=(f[l][r]+1ll*dfs(l,a[r][i]-1)*dfs(a[r][i]+1,r)%md*F(a[r][i]-l,r-a[r][i]))%md;
	return f[l][r];
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for (int i=0;i<=n;++i) c[i][0]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
	for (int i=1,x;i<=n;++i){
		scanf("%d",&x);
		a[i-x][++a[i-x][0]]=i;
		if (x) a[i+x][++a[i+x][0]]=i;
	}
	printf("%d\n",dfs(1,n));
	return 0;
}
