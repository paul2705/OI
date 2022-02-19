/*
	Author: zxy_hhhh
	data: 2018/11/06
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<queue>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define maxn 100005
using namespace std;
inline ll rd()
{
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
int to[maxn<<1],nx[maxn<<1],hd[maxn],cnt;
inline void add(int u,int v){nx[++cnt]=hd[u],to[cnt]=v,hd[u]=cnt;}
int n,m;
int t[maxn],col[maxn],fa[maxn],F[maxn];
int mx[maxn],se[maxn],mn[maxn];
int D[maxn][2];
vector<int> vt[maxn];
void dfs(int u)
{

}
queue<int> q;
bool vis[maxn];
int lev,le[maxn];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=rd(),m=rd();
	/*
	rep(i,1,n) col[i]=rd(),vt[col[i]].push_back(i);
	rep(i,1,n-1){
		int x=rd(),y=rd();
		add(x,y),add(y,x);
	}
	memset(mn,0x7f,sizeof mn);
	dfs(1);
	rep(i,1,n)fa[i]=i;
	rep(i,1,n)
		if (col[F[i]]==col[i]) merge(fa[i],i);
	lev=m;
	rep(i,1,n){
		if (!mx[i]) printf("%d %d %d\n",i,rand()%n+1,rand()%n+1),le[i]=-1;
		if (!se[i]) {
			D[i][0]=mx[i],D[i][1]=mn[i];
			if (D[i][1]==F[D[i][0]]) {
				merge(D[i][1],D[i][0]);
				q.push(D[i][1]),q.push(D[i][0]);
				vis[D[i][0]]=vis[D[i][1]]=1;
				le[i]=lev--;
			}
			if (D[i][1]==D[i][0]) {
				q.push(D[i][0]),vis[D[i][0]]=1;
				le[i]=lev--;
			}
		}
		else D[i][0]=mx[i],D[i][1]=se[i];
	}
	bfs();
	*/
	rep(i,1,m)
		printf("nan nan nan\n");
}