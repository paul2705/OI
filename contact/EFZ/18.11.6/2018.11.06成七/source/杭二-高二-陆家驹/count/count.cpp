#include<cstdio>
const int N=4;
int n,m,p,a[N][N],ans,X[N*N],Y[N*N];
bool b[N*N],bo[N][N];
void judge(){freopen("count.in","r",stdin);freopen("count.out","w",stdout);}
void check()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			bo[i][j]=1;
	for (int i=1;i<=n;i++) bo[i][Y[n*m]]=0;
	for (int i=1;i<=m;i++) bo[X[n*m]][i]=0;
	for (int i=n*m-1;i>=1;i--)
	{
		if (bo[X[i]][Y[i]]) return;
		for (int j=1;j<=n;j++) bo[j][Y[i]]=0;
		for (int j=1;j<=m;j++) bo[X[i]][j]=0;
	}
	ans++;
	if (ans==p) ans=0;
}
void dfs(int x,int y)
{
	if (y>m) x++,y=1;
	if (x>n) {check(); return;}
	for (int i=1;i<=n*m;i++)
		if (!b[i]) a[x][y]=i,X[i]=x,Y[i]=y,b[i]=1,dfs(x,y+1),b[i]=0;
}
int main()
{
	judge();
	scanf("%d%d%d",&n,&m,&p);
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
