#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int ch[MAXN][MAXN];
int n,m,f[MAXN][MAXN];
int c[10]={6,2,5,5,4,5,6,3,7,6};
int gen(int x,int r){
	int best=-1,cc=-1;
	if (x<0) return -1;
	if (r==0) best=0;
//	if (x==0) return best;
	if (f[x][r]>=0) return f[x][r];
	int lb=(x==n?1:0);
	for (int i=9;i>=lb;i--){
//		cout<<x<<" "<<r<<" "<<i<<endl;
		int d=gen(x-c[i],(r*10+i)%m);
		if (d>best){
			best=d; cc=i;
		}
	}
	ch[x][r]=cc;
	return f[x][r]=best+1;
}
void dfs(int x,int r){
	if (x<=0) return;
	printf("%d",ch[x][r]);
	dfs(x-c[ch[x][r]],(r*10+ch[x][r])%m);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++) f[i][j]=-1;
	}
	int len=gen(n,0);
//	cout<<f[n][0]<<" "<<ch[n][0]<<endl;
	if (f[n][0]>0) dfs(n,0);
	else printf("%d",f[n][0]);
	cout<<endl;
	return 0;
}
