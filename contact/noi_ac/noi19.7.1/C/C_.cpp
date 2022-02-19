#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAXN=1e4+5;
const int MAXM=55;
const int dx[2]={0,1},dy[2]={1,0};
map<int,int> f[MAXN];
int n,m,D,K,inv;
struct rec{
	int x,y;
} a[MAXM];
int A,B;
queue<rec> q;
bool ub(int x,int y){
	return x<0||y<0;
}
int mod_pow(int x,int n){
	int ret=1;
	while (n){
		if (n&1) ret=(ll)ret*(ll)x%mod;
		x=(ll)x*(ll)x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d",&A,&B);
	scanf("%d%d%d%d",&n,&m,&D,&K);
	for (int i=1;i<=K;i++) scanf("%d%d",&a[i].x,&a[i].y);
	inv=mod_pow(A+B,mod-2);
//	cout<<inv<<" "<<A+B<<" "<<(A+B)*inv%mod<<endl;
	q.push((rec){0,0}); f[0][0]=1;
	while (!q.empty()){
		rec u=q.front(); q.pop();
		bool flag=0;
		for (int i=1;i<=K;i++){
			if (u.x==a[i].x&&u.y==a[i].y) flag=1;
		}
		if (flag||u.x+u.y==n) continue;
		int t=f[u.x][u.y];
//		cout<<u.x<<" "<<u.y<<" "<<t<<endl;
		for (int i=0;i<2;i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if (ub(nx,ny)) continue;
			int tmp=f[nx][ny];
			int mul=(i==1?A:B);
			int add=0;
			if (nx%D==0&&ny%D==0) add=1;
			f[nx][ny]=((ll)tmp+(ll)t*(ll)mul%mod*(ll)inv%mod+(ll)add*inv)%mod;
			q.push((rec){nx,ny});
		}
	}
	int ans=0;
	for (int i=0;i<=n;i++){
		int j=n-i;
		cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		ans=(ans+f[i][j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
