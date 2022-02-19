#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int MAXN=1e5+5;
map<int,int> mp[MAXN];
int n,m,id,h,x,y;
int f[MAXN];
int main(){
	scanf("%d%d%d%d",&n,&id,&h,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		if (mp[x][y]) continue;
		else mp[x][y]=1;
		f[x+1]--; f[y]++;
	}
	for (int i=1;i<=n;i++){
		f[i]=f[i]+f[i-1];
		printf("%d\n",f[i]+h);
	}
	return 0;
}
