#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const ll mod=1e9+7;
ll f[3][MAXN][MAXN],g[3][MAXN][MAXN];
ll sg[MAXN],sf[MAXN],inv[MAXN],rpw[MAXN][MAXN];
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	inv[1]=1;
	for (int i=2;i<=K;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for (int i=1;i<=K;i++){
		rpw[i][0]=1;
		for (int j=1;j<=K;j++) rpw[i][j]=rpw[i][j-1]*inv[i]%mod;
	}
	f[0][0][0]=0; 
	for (int i=1;i<=K;i++) g[0][i][i]=1;
	for (int i=1;i<=K;i++){
		sg[i]=sg[i-1];
		for (int j=1;j<=K;j++){
			sg[i]=(sg[i]+g[0][i][j])%mod;
			g[0][i][j]=(g[0][i][j]+g[0][i-1][j]+g[0][i][j-1]-g[0][i-1][j-1])%mod;
		}
	}
	for (int i=1;i<=n;i++){
		int c=i&1; int o=c^1;
		for (int j=1;j<=K;j++){
			for (int l=1;l<=j;l++){
				f[c][j][l]=sf[j]+(i-1)*calcg(l,k-1);
				g[c][j][k]=
