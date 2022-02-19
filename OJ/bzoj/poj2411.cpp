#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,m;
ll f[15][15][(1<<15)];
ll dp(int x,int y,ll b){
	if (f[x][y][b]>0) return f[x][y][b];
	if (x==m) return (b==0);
	int x_,y_;
	if (y==n-1) x_=x+1,y_=0;
	else x_=x,y_=y+1;
	ll mask=(1<<y);
	if (b&mask) return f[x_][y_][b^mask]=dp(x_,y_,b^mask);
	ll ans=f[x_][y_][b^mask];
	if ((y_+1<n) && ~(b&(mask<<1))) ans+=f[x_][y_][b^(mask<<1)]=dp(x_,y_,b^(mask<<1));
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	while (n>0&&m>0){
		memset(f,0,sizeof(f)); f[m][0][0]=1;
		printf("%lld\n",dp(0,0,0));
		scanf("%d%d",&n,&m);
	}
	return 0;
}
