#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
int k,m,n,cur,f[2][4010][4010],vis[2010];
struct nd{
	int x,y,z;
}a[2010];
nd pre[2010][12010];
bool operator<(const nd x,const nd y){
	if (x.x!=y.x) return x.x>y.x;
	if (x.y!=y.y) return x.y>y.y;
	return x.z>y.z;
}
void clr(int cur,int m){
	for (int i=0;i<=k;++i)
		f[cur][0][i]=f[cur][i][0]=-0x3f3f3f3f;
	for (int i=0;i<=m;++i)
		f[cur][i][m-i]=-0x3f3f3f3f;
}
int getnm(int y,int z){
	if (!y) return k+z;
	if (!z) return 2*k+1+y;
	return y;
}
void upd(int ax,int ay,int bx,int by,int c,int i,int x){
	if (f[cur^1][bx][by]+c>f[cur][ax][ay]){
		f[cur][ax][ay]=f[cur^1][bx][by]+c;
		pre[i][getnm(ax,ay)]=(nd){x,bx,by};
	}
}
void print(int x,int y,int z){
	if (!x){
		for (int i=1;i<=n;++i)
			if (!vis[i]) printf("%d ",i);
		return;
	}
	nd a=pre[x][getnm(y,z)];
	vis[a.x]=1;
	print(x-1,a.y,a.z);
	if (a.x) printf("%d ",a.x);
}
int main()
{
	scanf("%d%d",&k,&n),m=k;
	for (int i=1;i<=n;++i) scanf("%d",&a[i].x),a[i].z=i;
	for (int i=1;i<=n;++i) scanf("%d",&a[i].y);
	sort(a+1,a+n+1);
	clr(cur,m);
	for (int i=0;i<=k;++i) f[cur][i][k-i]=0;
	for (int i=1;i<=n;++i){
		cur^=1,clr(cur,max(0,m-a[i].x));
		for (int j=0;j<=m;++j)
			upd(max(0,j-a[i].x),m-j,j,m-j,max(0,a[i].y-max(0,j-a[i].x)),i,a[i].z),
			upd(j,max(0,m-j-a[i].x),j,m-j,0,i,0);
		for (int j=0;j<=k;++j)
			upd(0,j,0,j,a[i].y,i,a[i].z),
			upd(0,max(0,j-a[i].x),0,j,0,i,0);
		for (int j=0;j<=k;++j)
			upd(max(0,j-a[i].x),0,j,0,max(0,a[i].y-max(0,j-a[i].x)),i,a[i].z),
			upd(j,0,j,0,0,i,0);
		m=max(0,m-a[i].x);
	}
	nd ans=(nd){-0x3f3f3f3f,0,0};
	for (int i=0;i<=k;++i)
		ans=min(ans,(nd){f[cur][i][0],i,0});
	printf("%d\n",ans.x);
	print(n,ans.y,ans.z);
	puts("");
	return 0;
}
