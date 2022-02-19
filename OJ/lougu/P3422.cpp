#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e6+5;
int f[MAXN][2],p[MAXN],d[MAXN],n,ans[MAXN];
void calc(bool flag){
	memset(f,0,sizeof(f));
	f[2*n][0]=p[2*n]; f[2*n][1]=2*n;
	for (int i=2*n-1;i>=1;i--){
		f[i][0]=p[i]; f[i][1]=i;
		while (f[i][0]>=d[f[i][1]]&&f[i][1]+1<=2*n){
			f[i][0]=f[f[i][1]+1][0]+f[i][0]-d[f[i][1]];
			f[i][1]=f[f[i][1]+1][1];
		}
	}
	if (flag) for (int i=1;i<=n;i++) ans[i]|=f[i][1]-i>=n;
	else for (int i=1;i<=n;i++) ans[n-i+1]|=f[i][1]-i>=n;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&p[i],&d[i]);
		p[i+n]=p[i]; d[i+n]=d[i];
	}
	calc(1); 
	reverse(p+1,p+2*n+1); reverse(d+1,d+2*n+1); d[2*n+1]=d[1];
	for (int i=1;i<=2*n;i++) d[i]=d[i+1];
	calc(0);
	for (int i=1;i<=n;i++){
		if (ans[i]) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
