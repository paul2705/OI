#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
int a[MAXN],res,n,k,cnt;
void dfs(int id,int tmp){
	if (id==n+1){
		if (tmp!=k) return;
		bool fg=1;
		for (int i=2;i*i<=res;i++){
			if (res%i==0) fg=0;
		}
		if (fg) cnt++;
		return;
	}
	res+=a[id]; dfs(id+1,tmp+1); res-=a[id];
	dfs(id+1,tmp);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d\n",cnt);
	return 0;
}
