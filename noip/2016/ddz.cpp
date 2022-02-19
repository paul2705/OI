#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=16;
int use[MAXN];
int T,n,m,ans;
void dfs(int d,int x){
	if (d>ans) return;
	int nd=d+1;
	
int main(){
	scanf("%d%d",&T,&n);
	while (T--){
		for (int i=1;i<=15;i++) use[i]=0;
		for (int i=1,x,y;i<=n;i++){
			scanf("%d%d",&x,&y);
			use[x]++;
		}
		dfs(0,n);
		printf("%d\n",ans);
	}
	return 0;
}
