#include <bits/stdc++.h>
using namespace std;
#define re register int
#define rep(i,a,b) for(re i=a;i<=b;++i)
#define _ 0
template <class T>inline void read(T &x) {
	x=0; int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}

int n, m, p, s, ans;
int vis[123456], w[233][233];

int check() {
	int num=0;
	rep(i,1,n) {
		int id=0, o=0;
		rep(j,1,m)if(w[i][j]>o)	o=w[i][j],id=j;
		rep(j,1,n) {
			if(w[j][id]>o)break;
			if(j==n)	num++;
		}
	}
	return num==1;
}

void dfs(int x,int y) {
	if(x==n&&y==m) {
		ans+=check();
		if(ans>=p)	ans-=p;
		return;
	}
	if(y!=m) {
		rep(i,1,s)if(!vis[i]) {
			vis[i]=1, w[x][y]=i;
			dfs(x,y+1);
			vis[i]=0, w[x][y]=0;
		}
	}
	else {
		rep(i,1,s)if(!vis[i]) {
			vis[i]=1, w[x][y]=i;	
			dfs(x+1,1);
			vis[i]=0, w[x][y]=0;
		}
	}
}

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n),read(m),read(p); s=n*m;
	dfs(1,1);
	printf("%d\n", ans);
	return ~~(0^_^0);
}
