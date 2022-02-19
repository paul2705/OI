#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
typedef long long ll;
ll f[MAXN][10][2],g[MAXN][10][2],b[MAXN];
ll n,x,y;
char tmp[MAXN];
ll dp(int i,int j,int d){
	if (!i) return 0;
	if (f[i][j][d]) return f[i][j][d];
	if (d){
		int now=i; do{now--;}while(b[now+1]==b[now]);
		f[i][j][d]=dp(now,b[now],d)+1ll*(i-now)*(i-now)*j*g[now][b[now]][1];
	}
	else {
		bool flag=b[i]<=j;
		for (int k=i-1;k>=0;k--){
			if (b[k+1]!=j) flag=j>b[k+1];
			int len=i-k;
			for (int z=0;z<10;z++){
				if (z!=j) f[i][j][d]+=dp(k,z,0)+1ll*len*len*j*g[k][z][0];
			}
			if (flag) continue;
			if (b[k]!=j||!k) f[i][j][d]+=dp(k,b[k],1)+1ll*len*len*j*g[k][b[k]][1];
		}
	}
	return f[i][j][d];
}
ll solve(ll u){
	if (!u) return 0;
	memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
	g[0][0][1]=1ll; memset(tmp,0,sizeof(tmp));
	int pos=0;
	while (u) tmp[pos++]=u%10+'0',u/=10;
	n=strlen(tmp);
	for (int i=0;i<n;i++) b[i+1]=tmp[n-i-1]-'0';
	for (int i=1;i<=n;i++){
		for (int j=0;j<10;j++){
			for (int k=0;k<10;k++)
				g[i][j][0]+=g[i-1][k][0];
			if (j<b[i]) g[i][j][0]+=g[i-1][b[i-1]][1];
		}
		g[i][b[i]][1]=1;
	}
	ll ret=dp(n,b[n],1);
	for (int z=0;z<10;z++) ret+=dp(n,z,0);
	return ret;
}
int main(){
	while (~scanf("%lld%lld",&x,&y)){
		printf("%lld\n",solve(y)-solve(x-1));
	}
	return 0;
}
