#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e6+6;
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
struct rec{
	int x,y,h;
} a[MAXM],b[MAXM];
int n,m,cnt1,cnt2,ans;
int fa[MAXM],h[MAXN][MAXN];
bool f[MAXM];
bool bd(int x,int y){ return x<1||x>n||y<1||y>m; }
bool cmp(rec a,rec b){ return a.h<b.h; }
int get(int x,int y){ return (x-1)*m+y; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&h[i][j]);
			if (h[i][j]>0) a[++cnt1]=(rec){i,j,h[i][j]};
			else h[i][j]=-h[i][j];
//			cout<<h[i][j]<<" ";
			b[get(i,j)]=(rec){i,j,h[i][j]};
		}
//		cout<<endl;
	}
	for (int i=1;i<=n*m;i++) fa[i]=i;
	for (int i=0;i<=n+1;i++) h[i][0]=h[i][m+1]=1e9;
	for (int i=0;i<=m+1;i++) h[0][i]=h[n+1][i]=1e9;
	sort(a+1,a+cnt1+1,cmp);
	sort(b+1,b+n*m+1,cmp);
	int now=1;
	for (int i=1;i<=cnt1;i++){
		cout<<a[i].h<<" :";
		for (;now<=n*m&&b[now].h<=a[i].h;now++){
			int x=b[now].x,y=b[now].y;
			cout<<"("<<h[x][y]<<","<<x<<","<<y<<") ";
			for (int k=0;k<4;k++){
				int nx=x+dx[k],ny=y+dy[k];
				if (bd(nx,ny)) continue;
				if (h[nx][ny]<=h[x][y]){
//					uion(get(x,y),get(nx,ny));
					f[find(get(x,y))]|=f[find(get(nx,ny))];
					uion(get(x,y),get(nx,ny));
				}
			}
		}
		cout<<endl;
		if (!f[find(get(a[i].x,a[i].y))]){
			cout<<a[i].x<<" "<<a[i].y<<endl;
			f[find(get(a[i].x,a[i].y))]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
