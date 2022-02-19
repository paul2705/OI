#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=13;
const int MAXM=32;
int n,m;
ll p,ans,cnt;
int a[MAXN][MAXM],b[MAXN][MAXM];
bool ub(int x,int y){
	return x<1||x>n||y<0||y>=m;
}
void dfs(int d){
//	cout<<d<<endl;
	if (d==n+1){
		cnt++;
		for (int i=1;i<=n;i++){
			for (int j=0;j<m;j++) b[i][j]=1;
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<m;j++){
				if (!b[i][j]) continue;
				if (a[i][j]==1){
					int nx=i,ny=j+1;
					if (ub(nx,ny)){
						nx=i+1,ny=j;
						if (ub(nx,ny)) continue;
						else if (b[nx][ny]) b[nx][ny]=0,ans=(ans+1)%p;
					}
					else {
						if (!b[nx][ny]){
							nx=i+1,ny=j;
							if (ub(nx,ny)) continue;
							else if (b[nx][ny]) b[nx][ny]=0,ans=(ans+1)%p;
						}
						else b[nx][ny]=0,ans=(ans+1)%p;
					}
				}
				else {
					int nx=i+1,ny=j;
					if (ub(nx,ny)){
						nx=i,ny=j+1;
						if (ub(nx,ny)) continue;
						else if (b[nx][ny]) b[nx][ny]=0,ans=(ans+1)%p;
					}
					else {
						if (!b[nx][ny]){
							nx=i,ny=j+1;
							if (ub(nx,ny)) continue;
							else if (b[nx][ny]) b[nx][ny]=0,ans=(ans+1)%p;
						}
						else b[nx][ny]=0,ans=(ans+1)%p;
					}
				}
			}
		}
		return;
	}
	for (int s=0;s<(1<<m);s++){
		for (int i=0;i<m;i++){
			if (s&(1<<i)) a[d][i]=1;
			else a[d][i]=0;
		}
		dfs(d+1);
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&p);
//	freopen("1.out","w",stdout);
//	for (int i=1;i<=5;i++){
//		for (int j=1;j<=5;j++){
//			n=i,m=j;
			ans=0;
			dfs(1);
			printf("%lld %lld\n",cnt,ans);
//		}
//	}
//	fclose(stdin); fclose(stdout);
	return 0;
}
