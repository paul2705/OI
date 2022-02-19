#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 3012
int n,m,nul=0,inc=0,b[N][N];bool a[N][N];char sc[N];
struct Po{int x,y;}s1[N<<1],s2[N<<1];int c1=0,c2=0;
bool f[N][N],g[N][N],w[N][N];long long ans=0;
int main(){
	scanf("%d%d",&n,&m);int i,j,k,x1,y1,x2,y2;Po p;
	for(i=1;i<=n;i++)
	{
		scanf("%s",sc+1);
		for(j=1;j<=m;j++)a[i][j]=(sc[j]=='*'),nul+=(!a[i][j]);
	}
	f[1][1]=!a[1][1];g[n][m]=!a[n][m];
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)if(!a[i][j])f[i][j]|=f[i-1][j]||f[i][j-1];
	for(i=n;i>=1;i--)
	for(j=m;j>=1;j--)if(!a[i][j])g[i][j]|=g[i+1][j]||g[i][j+1];
	if(!f[n][m]){printf("%lld",1ll*nul*(nul-1)/2);return 0;}
	p=(Po){1,1};while((p.x<=n)&&(p.y<=m))s1[++c1]=p,p=g[p.x+1][p.y]?(Po){p.x+1,p.y}:(Po){p.x,p.y+1};
	p=(Po){1,1};while((p.x<=n)&&(p.y<=m))s2[++c2]=p,p=g[p.x][p.y+1]?(Po){p.x,p.y+1}:(Po){p.x+1,p.y};
	for(i=1;i<=c1;i++)++b[s1[i].x][s1[i].y];
	for(i=1;i<=c2;i++)++b[s2[i].x][s2[i].y];
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)inc+=(b[i][j]==2);
	ans=1ll*(nul-inc)*inc+1ll*inc*(inc-1)/2;
	for(i=1;i<=c2;i++)w[s2[i].x][s2[i].y]=1;
	for(i=1;i<=c1;i++)
	{
		x1=s1[i].x;y1=s1[i].y;if(b[x1][y1]==2)continue;
		for(k=x1-1;k>=max(1,x1+y1-m);k--)
		if(f[x2=k][y2=(x1+y1-k)]&&g[k][x1+y1-k])
		{
			p=(Po){x2,y2};while((p.x>=1)&&(p.y>=1))ans+=w[p.x][p.y]&&(b[p.x][p.y]!=2),p=f[p.x][p.y-1]?(Po){p.x,p.y-1}:(Po){p.x-1,p.y};
			p=(Po){x2,y2};while((p.x<=n)&&(p.y<=m))ans+=w[p.x][p.y]&&(b[p.x][p.y]!=2),p=g[p.x+1][p.y]?(Po){p.x+1,p.y}:(Po){p.x,p.y+1};
			ans-=w[x2][y2]&&(b[x2][y2]!=2);break;
		}
	}printf("%lld",ans);return 0;
}
