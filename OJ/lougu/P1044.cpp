#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=25;
ll f[MAXN][MAXN];
int n;
ll dfs(int x,int y){
	if (x==0) return 1;
	if (y==-1) return 0;
	if (f[x][y]) return f[x][y];
	return f[x][y]=dfs(x-1,y+1)+dfs(x,y-1);
}
int main(){
	scanf("%d",&n);
	printf("%lld\n",dfs(n,0));
	return 0;
}
