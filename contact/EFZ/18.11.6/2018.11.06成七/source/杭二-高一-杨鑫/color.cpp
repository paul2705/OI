#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define M 1010
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
using namespace std;
inline ll read(){
    ll x = 0; char zf = 1; char ch = getchar();
    while (ch != '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
int i,j,k,m,n,x,y,z,cnt;
int col[105],v[105];
int F[M],L[M],N[M],a[M],fa[M],deep[105];
int sum[105][105];
void add(int x,int y){
	a[++k]=y;
	if(!F[x])F[x]=k;
	else N[L[x]]=k;
	L[x]=k;
}
void dfs(int x,int pre){
	
	sum[1][col[x]]++;fa[x]=pre;
	for(rt i=x;i!=1;i=fa[i])sum[i][col[x]]++;
	for(rt i=F[x];i;i=N[i])if(a[i]!=pre)
	deep[a[i]]=deep[x]+1,dfs(a[i],x);
}
int LCA[105][105];
int getlca(int x,int y){
	if(LCA[x][y])return LCA[x][y];
	if(x==y)return x;
	if(x==1||y==1)return 1;
	if(deep[getlca(fa[x],y)]>deep[getlca(x,fa[y])])
	return LCA[x][y]=getlca(fa[x],y);
	else return LCA[x][y]=getlca(x,fa[y]);
}
int main(){
	
	file("color");
	n=r;m=r;
	for(rt i=1;i<=n;i++){
		col[i]=r;
		v[col[i]]++;
	}
	for(rt i=1;i<n;i++){
		x=r;y=r;
		add(x,y);
		add(y,x);
	}
	dfs(1,1);
	for(rt i=1;i<=n;i++)
	for(rt j=1;j<=n;j++)LCA[i][j]=getlca(i,j);
	for(rt i=1;i<=n;i++)
	for(rt j=i;j<=n;j++)
	if(col[i]==col[j]&&sum[LCA[i][j]][col[i]]==v[col[i]]){
		if(sum[i][col[i]]==1||sum[j][col[j]]==1)
		cout<<col[i]<<' '<<i<<' '<<j<<endl;
	}
	return 0;
}

