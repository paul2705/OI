#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<cmath>
#define LL long long
#define N (55)
using namespace std;
int n,m,p,ans; 
int choose[N][N];
bool vis[N]; 
template <typename T> void read(T&t) {
	t=0;
	bool fl=true;
	char p=getchar();
	while (!isdigit(p)) {
		if (p=='-') fl=false;
		p=getchar();
	}
	do {
		(t*=10)+=p-48;p=getchar();
	}while (isdigit(p));
	if (!fl) t=-t;
}
inline bool check(int x,int y){
	for (int i=1;i<=m;i++){
		if (choose[x][i]>choose[x][y]) return 0;
	} 
	for (int i=1;i<=n;i++){
		if (choose[i][y]>choose[x][y]) return 0;
	}
	return 1;
}
void out(){
	int tt=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (check(i,j)) tt++;
			if (tt>1) return;
		}
	}
	if (tt==1) ans++;
}
void dfs(int x,int y){
	if (x>n){
		out();
		return;
	}
	for (int i=1;i<=n*m;i++){
		if (!vis[i]){
			vis[i]=1;
			choose[x][y]=i;
			if (y==m) dfs(x+1,1);
			else dfs(x,y+1);
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n),read(m),read(p);
	dfs(1,1);
	printf("%d",ans);
	return 0;
}

